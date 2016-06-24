/// @file myexamplederivedclassl2.h
///
/// For the better part, this class (MyExampleDerivedClassL2) actually does nothing but occupy memory.
///
/// It inherits from MyExampleDerivedClassL1, overrides some virtual functions, but those, inherited
/// and overridden mostly do nothing.
///
/// The purpose of it, it's ancestor and descendant, is to carry arbitrary data for memory analysis.

#ifndef MYEXAMPLEDERIVEDCLASSL2_H
#define MYEXAMPLEDERIVEDCLASSL2_H

#include "myexamplederivedclassl1.h"

class MyExampleDerivedClassL2 : public MyExampleDerivedClassL1
{
  public:
    MyExampleDerivedClassL2();
    virtual ~MyExampleDerivedClassL2();

    /// A pure virtual public function.  Has to be overridden in a derived class.
    virtual void publicDerivedL2MemberFunction1();

    /// A normal virtual public function.  Can be overridden in a derived class.
    virtual void publicDerivedL2MemberFunction2();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicDerivedL2MemberFunction3();

    /// Override of public pure virtual in base class.
    virtual void publicDerivedL1MemberFunction1();

    virtual void populatename(char withWhat);

  protected:
    /// A normal virtual protected function.  Can be overridden in a derived class.
    virtual void protectedDerivedL2MemberFunction1();

    /// A normal virtual protected function.  Can be overridden in a derived class.
    virtual void protectedDerivedL2MemberFunction2();

    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedDerivedL2MemberFunction3();

    /// Override of protected pure virtual in base class.
    virtual void protectedDerivedL1MemberFunction1();

    char _derivedL2name[32];

  private:
    /// A normal virtual private function.  Can be overridden in a derived class.
    virtual void privateDerivedL2MemberFunction1();

    /// A normal virtual private function.  Can be overridden in a derived class.
    virtual void privateDerivedL2MemberFunction2();

    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateDerivedL2MemberFunction3();

    /// Override of private pure virtual in base class.
    virtual void privateDerivedL1MemberFunction1();
};

#endif // MYEXAMPLEDERIVEDCLASSL2_H
