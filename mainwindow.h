#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QPlainTextEdit>

#include "myexamplederivedclassl3.h"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = 0);
  virtual ~MainWindow();

private slots:

  /// Objects are instantiated in pointers of their own type. No polymorphism.
  void on__nonPolyInstantiateButton_clicked();

  /// Objects are stored in MyExampleBaseClass pointers.
  void on__polyAsBaseInstantiateButton_clicked();

  /// Objects are stored in MyExampleDerivedClassL1 pointers.
  void on__polyAsLevel1InstantiateButton_clicked();

  /// The object is stored in a MyExampleDerivedClassL2 pointer.
  void on__polyAsLevel2InstantiateButton_clicked();

  /// Casts the various objects to void pointers and back and prints their content.
  void on__voidPtrInfoButton_clicked();

  /// Clears all the text boxes.
  void on__clearBoxesButton_clicked();

  /// Same thing, just without smart pointers.
  void on__nonSmartPtrExampleButton_clicked();

  private:
  Ui::MainWindow* ui;
  bool _state;

  QSharedPointer<MyExampleBaseClass>      _basePtr;

  QSharedPointer<MyExampleDerivedClassL1> _derivedLevel1Ptr;
  QSharedPointer<MyExampleDerivedClassL2> _derivedLevel2Ptr;
  QSharedPointer<MyExampleDerivedClassL3> _derivedLevel3Ptr;

  QSharedPointer<MyExampleBaseClass>      _derivedLevel1PtrAsBasePtr;
  QSharedPointer<MyExampleBaseClass>      _derivedLevel2PtrAsBasePtr;
  QSharedPointer<MyExampleBaseClass>      _derivedLevel3PtrAsBasePtr;

  QSharedPointer<MyExampleDerivedClassL1> _derivedLevel2PtrAsDerivedLevel1Ptr;
  QSharedPointer<MyExampleDerivedClassL1> _derivedLevel3PtrAsDerivedLevel1Ptr;

  QSharedPointer<MyExampleDerivedClassL2> _derivedLevel3PtrAsDerivedLevel2Ptr;

  MyExampleBaseClass* _testLevel2AsBasePtr;
  MyExampleBaseClass* _testLevel3AsBasePtr;

  MyExampleDerivedClassL2* _level2Ptr;
  MyExampleDerivedClassL3* _level3Ptr;

  /// Determines how and when which buttons should be enabled/disabled.
  void evaluateState();

  /// Ensures the text boxes use Courier New font.
  void setFonts();

  /// Clears all the text boxes.
  void clearTextBoxes();

  template <class T>
  void dumpobject(int line, QString caller, QString& header, T const* t, QPlainTextEdit* debugWindow)
  {
    unsigned char const* p = reinterpret_cast<unsigned char const*>(t);
    char buf[4];
    QString output = QString();
    int offset = 0;
    for (size_t n = 0 ; n < sizeof(T) ; ++n) {
      if (n == 0) {
        char nextBuf[16];
        sprintf(&nextBuf[0], "\n%04X: ", offset);
        output = output + QString(nextBuf);
      }

      else if (n % 16 == 0) {
        char nextBuf[16];
        offset += 16;
        sprintf(&nextBuf[0], "%04X: ", offset);
        output = output + QString("\n") + QString(nextBuf);;
      }

      sprintf(&buf[0], "%02X", p[n]);
      n == sizeof(T) - 1 ? output = output + QString(buf[0]) + QString(buf[1]) : output = output + QString(buf[0]) + QString(buf[1]) + QString(" ");
    }
    const void* xx = t;
    QString ptrStr = QString(" @ 0x%1").arg((quintptr)xx,
                                            QT_POINTER_SIZE, 16, QChar('0'));
    QString debugText = QString("************************************************************\n")
                        + header + ptrStr
                        + QString("\n************************************************************")
                        + output
                        + QString("\n************************************************************\n");
    qDebug() << "************************************************************";
    qDebug() << line << QString(":") + caller;
    qDebug() << t << ptrStr;
    qDebug() << output;
    qDebug() << "************************************************************";

    debugWindow->appendPlainText(debugText);
  }

  void dumpobject(int line, QString caller, QString& header, void* t, size_t length, QPlainTextEdit* debugWindow)
  {
    unsigned char const* p = reinterpret_cast<unsigned char const*>(t);
    char buf[4];
    QString output = QString();
    int offset = 0;
    for (size_t n = 0 ; n < length ; ++n) {
      if (n == 0) {
        char nextBuf[16];
        sprintf(&nextBuf[0], "\n%04X: ", offset);
        output = output + QString(nextBuf);
      }

      else if (n % 16 == 0) {
        char nextBuf[16];
        offset += 16;
        sprintf(&nextBuf[0], "%04X: ", offset);
        output = output + QString("\n") + QString(nextBuf);;
      }

      sprintf(&buf[0], "%02X", p[n]);
      n == length - 1 ? output = output + QString(buf[0]) + QString(buf[1]) : output = output + QString(buf[0]) + QString(buf[1]) + QString(" ");
    }
    QString ptrStr = QString(" @ 0x%1").arg((quintptr)t,
                                            QT_POINTER_SIZE, 16, QChar('0'));
    QString debugText = QString("************************************************************\n")
                        + header + ptrStr
                        + QString("\n************************************************************")
                        + output
                        + QString("\n************************************************************\n");
    qDebug() << "************************************************************";
    qDebug() << line << QString(":") + caller;
    qDebug() << t << ptrStr;
    qDebug() << output;
    qDebug() << "************************************************************";

    debugWindow->appendPlainText(debugText);
  }
};

#endif // MAINWINDOW_H
