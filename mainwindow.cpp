#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myexamplederivedclassl3.h"

MainWindow::MainWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  _state(false)
{
  ui->setupUi(this);

  setFonts();
  clearTextBoxes();

  evaluateState();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on__nonPolyInstantiateButton_clicked()
{
  /// The following two lines wwon't compile, as the classes contain pure virtual functions they cannot stand
  /// on their own as concrete instances.

  /*------------------------------------------------------*/
  // _basePtr          = new MyExampleBaseClass();
  // _derivedLevel1Ptr = new MyExampleDerivedClassL1();
  /*------------------------------------------------------*/

  /// The following two lines, however, are legal, will compile and run, as these two classes
  /// contain no pure virtual functions, and can override the pure virtuals in their base classes.

  _derivedLevel2Ptr.reset(new MyExampleDerivedClassL2());
  _derivedLevel3Ptr.reset(new MyExampleDerivedClassL3());

  QString header{"_derivedLevel2Ptr : MyExampleDerivedClassL2"};
  dumpobject<MyExampleDerivedClassL2>(__LINE__,
                                      QString("on__nonPolyInstantiateButton_clicked"),
                                      header,
                                      _derivedLevel2Ptr.data(),
                                      ui->_nonPolyPointerContent);

  header = QString{"_derivedLevel3Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__,
                                      QString("on__nonPolyInstantiateButton_clicked"),
                                      header,
                                      _derivedLevel3Ptr.data(),
                                      ui->_nonPolyPointerContent);
  ui->_nonPolyInstantiateButton->setEnabled(false);
  evaluateState();
}

void MainWindow::on__polyAsBaseInstantiateButton_clicked()
{
  /// Won't compile, as a standalone instance of MyExampleDerivedClassL1 cannot exist.

  /*-----------------------------------------------------------------*/
  // _derivedLevel1PtrAsBasePtr = new MyExampleDerivedClassL1();
  /*-----------------------------------------------------------------*/

  /// Will however work, and store level2 and level3 objects in their MyExampleBaseClass base pointers.
  _derivedLevel2PtrAsBasePtr.reset(new MyExampleDerivedClassL2());
  _derivedLevel3PtrAsBasePtr.reset(new MyExampleDerivedClassL3());

  QString header{"_derivedLevel2PtrAsBasePtr : MyExampleBaseClass"};
  dumpobject<MyExampleBaseClass>(__LINE__,
                                 QString("on__polyAsBaseInstantiateButton_clicked"),
                                 header,
                                 _derivedLevel2PtrAsBasePtr.data(),
                                 ui->_polyAsBasePointerContent);

  header = QString{"_derivedLevel3PtrAsBasePtr : MyExampleBaseClass"};
  dumpobject<MyExampleBaseClass>(__LINE__,
                                 QString("on__polyAsBaseInstantiateButton_clicked"),
                                 header,
                                 _derivedLevel3PtrAsBasePtr.data(),
                                 ui->_polyAsBasePointerContent);
  ui->_polyAsBaseInstantiateButton->setEnabled(false);
  evaluateState();
}

void MainWindow::on__polyAsLevel1InstantiateButton_clicked()
{
  /// Will work, and store level2 and level3 objects in their MyExampleDerivedClassL1 base pointers.
  _derivedLevel2PtrAsDerivedLevel1Ptr.reset(new MyExampleDerivedClassL2());
  _derivedLevel3PtrAsDerivedLevel1Ptr.reset(new MyExampleDerivedClassL3());

  QString header{"_derivedLevel2PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL1"};
  dumpobject<MyExampleDerivedClassL1>(__LINE__,
                                      QString("on__polyAsLevel1InstantiateButton_clicked"),
                                      header,
                                      _derivedLevel2PtrAsDerivedLevel1Ptr.data(),
                                      ui->_polyAsLevel1PointerContent);

  header = QString{"_derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL1"};
  dumpobject<MyExampleDerivedClassL1>(__LINE__,
                                      QString("on__polyAsLevel1InstantiateButton_clicked"),
                                      header,
                                      _derivedLevel3PtrAsDerivedLevel1Ptr.data(),
                                      ui->_polyAsLevel1PointerContent);
  ui->_polyAsLevel1InstantiateButton->setEnabled(false);
  evaluateState();
}

void MainWindow::on__polyAsLevel2InstantiateButton_clicked()
{
  /// Will work, and store a level3 object in its MyExampleDerivedClassL2 base pointer.
  _derivedLevel3PtrAsDerivedLevel2Ptr.reset(new MyExampleDerivedClassL3());

  QString header{"_derivedLevel3PtrAsDerivedLevel2Ptr : MyExampleDerivedClassL2"};
  dumpobject<MyExampleDerivedClassL2>(__LINE__,
                                      QString("on__polyAsLevel2InstantiateButton_clicked"),
                                      header,
                                      _derivedLevel3PtrAsDerivedLevel2Ptr.data(),
                                      ui->_polyAsLevel2PointerContent);
  ui->_polyAsLevel2InstantiateButton->setEnabled(false);
  evaluateState();
}

void MainWindow::on__voidPtrInfoButton_clicked()
{
  /************************************************************************************************************/
  /************************************************************************************************************/

  /// Take the existing objects and overwrite their character buffers
           _derivedLevel3PtrAsBasePtr.data()->populatename(0x11);
  _derivedLevel3PtrAsDerivedLevel1Ptr.data()->populatename(0x22);
  _derivedLevel3PtrAsDerivedLevel2Ptr.data()->populatename(0x33);
                    _derivedLevel3Ptr.data()->populatename(0x44);

  /************************************************************************************************************/
  /************************************************************************************************************/

  /// Cast them to void pointers
  void* baseVoidPtrObject   = reinterpret_cast<void*>(_derivedLevel3PtrAsBasePtr.data());
  void* level1VoidPtrObject = reinterpret_cast<void*>(_derivedLevel3PtrAsDerivedLevel1Ptr.data());
  void* level2VoidPtrObject = reinterpret_cast<void*>(_derivedLevel3PtrAsDerivedLevel2Ptr.data());
  void* level3VoidPtrObject = reinterpret_cast<void*>(_derivedLevel3Ptr.data());

  /// Dump the contents of the void pointers according to the sizes of the original objects
  QString header{"baseVoidPtrObject : _derivedLevel3PtrAsBasePtr : void *"};
  dumpobject(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
             baseVoidPtrObject, sizeof(MyExampleBaseClass), ui->_polyAsBasePointerAddresses);

  header = QString{"level1VoidPtrObject : _derivedLevel3PtrAsDerivedLevel1Ptr : void *"};
  dumpobject(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
             level1VoidPtrObject, sizeof(MyExampleDerivedClassL1), ui->_polyAsLevel1PointerAddresses);

  header = QString{"level2VoidPtrObject : _derivedLevel3PtrAsDerivedLevel2Ptr : void *"};
  dumpobject(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
             level2VoidPtrObject, sizeof(MyExampleDerivedClassL2), ui->_polyAsLevel2PointerAddresses);

  header = QString{"level3VoidPtrObject : _derivedLevel3Ptr : void *"};
  dumpobject(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
             level3VoidPtrObject, sizeof(MyExampleDerivedClassL3), ui->_nonPolyPointerAddresses);

  /************************************************************************************************************/
  /************************************************************************************************************/

  /// Cast them back from void pointers to the original object types
  MyExampleBaseClass*      baseObject   = (reinterpret_cast<MyExampleBaseClass*>(baseVoidPtrObject));
  MyExampleDerivedClassL1* level1Object = (reinterpret_cast<MyExampleDerivedClassL1*>(level1VoidPtrObject));
  MyExampleDerivedClassL2* level2Object = (reinterpret_cast<MyExampleDerivedClassL2*>(level2VoidPtrObject));
  MyExampleDerivedClassL3* level3Object = (reinterpret_cast<MyExampleDerivedClassL3*>(level3VoidPtrObject));

  /// Dump the contents of the original object types
  header = QString{"baseObject : _derivedLevel3PtrAsBasePtr : MyExampleBaseClass"};
  dumpobject<MyExampleBaseClass>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                 baseObject, ui->_polyAsBasePointerAddresses);

  header = QString{"level1Object : _derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL1"};
  dumpobject<MyExampleDerivedClassL1>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level1Object, ui->_polyAsLevel1PointerAddresses);

  header = QString{"level2Object : _derivedLevel3PtrAsDerivedLevel2Ptr : MyExampleDerivedClassL2"};
  dumpobject<MyExampleDerivedClassL2>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level2Object, ui->_polyAsLevel2PointerAddresses);

  header = QString{"level3Object : _derivedLevel3Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level3Object, ui->_nonPolyPointerAddresses);

  /************************************************************************************************************/
  /************************************************************************************************************/

  /// Cast the void pointers into the lowest-level derived type object
  MyExampleDerivedClassL3* baseRecoveredObject   = (reinterpret_cast<MyExampleDerivedClassL3*>(baseVoidPtrObject));
  MyExampleDerivedClassL3* level1RecoveredObject = (reinterpret_cast<MyExampleDerivedClassL3*>(level1VoidPtrObject));
  MyExampleDerivedClassL3* level2RecoveredObject = (reinterpret_cast<MyExampleDerivedClassL3*>(level2VoidPtrObject));
  MyExampleDerivedClassL3* level3RecoveredObject = (reinterpret_cast<MyExampleDerivedClassL3*>(level3VoidPtrObject));

  /// Dump the contents of the lowest-level derived type objects
  header = QString{"baseRecoveredObject : _derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      baseRecoveredObject, ui->_polyAsBasePointerAddresses);

  header = QString{"level1RecoveredObject : _derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level1RecoveredObject, ui->_polyAsLevel1PointerAddresses);

  header = QString{"level2RecoveredObject : _derivedLevel3PtrAsDerivedLevel2Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level2RecoveredObject, ui->_polyAsLevel2PointerAddresses);

  header = QString{"level3RecoveredObject : _derivedLevel3Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level3RecoveredObject, ui->_nonPolyPointerAddresses);

  /************************************************************************************************************/
  /************************************************************************************************************/

  /// Manipulate these through the object handles
  baseRecoveredObject->populatename(0x55);
  level1RecoveredObject->populatename(0x66);
  level2RecoveredObject->populatename(0x77);
  level3RecoveredObject->populatename(0x88);

  header = QString{"baseRecoveredObject : _derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      baseRecoveredObject, ui->_polyAsBasePointerAddresses);

  header = QString{"level1RecoveredObject : _derivedLevel3PtrAsDerivedLevel1Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level1RecoveredObject, ui->_polyAsLevel1PointerAddresses);

  header = QString{"level2RecoveredObject : _derivedLevel3PtrAsDerivedLevel2Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level2RecoveredObject, ui->_polyAsLevel2PointerAddresses);

  header = QString{"level3RecoveredObject : _derivedLevel3Ptr : MyExampleDerivedClassL3"};
  dumpobject<MyExampleDerivedClassL3>(__LINE__, QString("on__voidPtrInfoButton_clicked"), header,
                                      level3RecoveredObject, ui->_nonPolyPointerAddresses);

  /************************************************************************************************************/
  /************************************************************************************************************/

  /// And dump them again.
  ui->_nonPolyInstantiateButton->setEnabled(true);
  ui->_polyAsBaseInstantiateButton->setEnabled(true);
  ui->_polyAsLevel1InstantiateButton->setEnabled(true);
  ui->_polyAsLevel2InstantiateButton->setEnabled(true);
  evaluateState();
}

void MainWindow::evaluateState()
{
  _state = !(ui->_polyAsLevel2InstantiateButton->isEnabled() ||
             ui->_polyAsLevel1InstantiateButton->isEnabled() ||
             ui->_polyAsBaseInstantiateButton->isEnabled()   ||
             ui->_nonPolyInstantiateButton->isEnabled());
  ui->_voidPtrInfoButton->setEnabled(_state);
}

void MainWindow::setFonts()
{

  QString fontFamily{"Courier New"};
  QFont font = QFont(fontFamily);

  ui->_nonPolyPointerContent->setFont(font);
  ui->_polyAsBasePointerContent->setFont(font);
  ui->_polyAsLevel1PointerContent->setFont(font);
  ui->_polyAsLevel2PointerContent->setFont(font);

  ui->_nonPolyPointerAddresses->setFont(font);
  ui->_polyAsBasePointerAddresses->setFont(font);
  ui->_polyAsLevel1PointerAddresses->setFont(font);
  ui->_polyAsLevel2PointerAddresses->setFont(font);
}

void MainWindow::clearTextBoxes()
{
  ui->_nonPolyPointerContent->clear();
  ui->_polyAsBasePointerContent->clear();
  ui->_polyAsLevel1PointerContent->clear();
  ui->_polyAsLevel2PointerContent->clear();

  ui->_nonPolyPointerAddresses->clear();
  ui->_polyAsBasePointerAddresses->clear();
  ui->_polyAsLevel1PointerAddresses->clear();
  ui->_polyAsLevel2PointerAddresses->clear();
}

void MainWindow::on__clearBoxesButton_clicked()
{
  clearTextBoxes();
}
