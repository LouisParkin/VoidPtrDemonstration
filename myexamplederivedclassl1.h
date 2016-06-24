/// @file myexamplederivedclassl1.h
///
/// For the better part, this class (MyExampleDerivedClassL1) actually does nothing but occupy memory.
///
/// It inherits from MyExampleBaseClass, overrides some virtual functions, but those, inherited
/// and overridden mostly do nothing.
///
/// The purpose of it, it's ancestor and descendant, is to carry arbitrary data for memory analysis.

#ifndef MYEXAMPLEDERIVEDCLASSL1_H
#define MYEXAMPLEDERIVEDCLASSL1_H

#include "myexamplebaseclass.h"

class MyExampleDerivedClassL1 : public MyExampleBaseClass
{
  public:
    MyExampleDerivedClassL1();
    virtual ~MyExampleDerivedClassL1();

    /// A pure virtual public function.  Has to be overridden in a derived class.
    virtual void publicDerivedL1MemberFunction1() = 0;

    /// A normal virtual public function.  Can be overridden in a derived class.
    virtual void publicDerivedL1MemberFunction2();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicDerivedL1MemberFunction3();

    /// Override of public pure virtual in base class.
    virtual void publicBaseMemberFunction1();

    virtual void populatename(char withWhat);

  protected:
    /// A pure virtual protected function.  Has to be overridden in a derived class.
    virtual void protectedDerivedL1MemberFunction1() = 0;

    /// A normal virtual protected function.  Can be overridden in a derived class.
    virtual void protectedDerivedL1MemberFunction2();

    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedDerivedL1MemberFunction3();

    /// Override of protected pure virtual in base class.
    virtual void protectedBaseMemberFunction1();

    char _derivedL1name[32];

  private:

    /// A pure virtual private function.  Has to be overridden in a derived class.
    virtual void privateDerivedL1MemberFunction1() = 0;

    /// A normal virtual private function.  Can be overridden in a derived class.
    virtual void privateDerivedL1MemberFunction2();

    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateDerivedL1MemberFunction3();

    /// Override of private pure virtual in base class.
    virtual void privateBaseMemberFunction1();

};

#endif // MYEXAMPLEDERIVEDCLASSL1_H
