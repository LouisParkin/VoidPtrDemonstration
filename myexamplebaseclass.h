/// @file myexamplebaseclass.h
///
/// For the better part, this class (MyExampleBaseClass) actually does nothing but occupy memory.
///
/// Its functions mostly do nothing.
///
/// The purpose of it and its descendant, is to carry arbitrary data for memory analysis.


#ifndef MYEXAMPLEBASECLASS_H
#define MYEXAMPLEBASECLASS_H

#include <QDebug>
#include <QObject>

class MyExampleBaseClass : public QObject
{
    Q_OBJECT
  public:
    explicit MyExampleBaseClass(QObject *parent = 0);
    virtual ~MyExampleBaseClass();

    /// A pure virtual public function.  Has to be overridden in a derived class.
    virtual void publicBaseMemberFunction1() = 0;

    /// A normal virtual public function.  Can be overridden in a derived class.
    virtual void publicBaseMemberFunction2();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicBaseMemberFunction3();

    virtual void populatename(char withWhat);

  protected:

    /// A pure virtual protected function.  Has to be overridden in a derived class.
    virtual void protectedBaseMemberFunction1() = 0;

    /// A normal virtual protected function.  Can be overridden in a derived class.
    virtual void protectedBaseMemberFunction2();

    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedBaseMemberFunction3();

    char _basename[32];

  private:

    /// A pure virtual private function.  Has to be overridden in a derived class.
    virtual void privateBaseMemberFunction1() = 0;

    /// A normal virtual private function.  Can be overridden in a derived class.
    virtual void privateBaseMemberFunction2();

    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateBaseMemberFunction3();

  signals:

  public slots:
};

#endif // MYEXAMPLEBASECLASS_H
