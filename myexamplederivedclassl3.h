/// @file myexamplederivedclassl3.h
///
/// For the better part, this class (MyExampleDerivedClassL3) actually does nothing but occupy memory.
///
/// It inherits from MyExampleDerivedClassL2, overrides some virtual functions, but those, inherited
/// and overridden mostly do nothing.
///
/// The purpose of it and its ancestor is to carry arbitrary data for memory analysis.

#ifndef MYEXAMPLEDERIVEDCLASSL3_H
#define MYEXAMPLEDERIVEDCLASSL3_H

#include "myexamplederivedclassl2.h"

class MyExampleDerivedClassL3 : public MyExampleDerivedClassL2
{
  public:
    MyExampleDerivedClassL3();
    virtual ~MyExampleDerivedClassL3();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicDerivedL3MemberFunction1();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicDerivedL3MemberFunction2();

    /// A normal non-virtual public function.  Can't be overridden in a derived class.
    void publicDerivedL3MemberFunction3();

    virtual void populatename(char withWhat);

  protected:
    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedDerivedL3MemberFunction1();

    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedDerivedL3MemberFunction2();

    /// A normal non-virtual protected function.  Can't be overridden in a derived class.
    void protectedDerivedL3MemberFunction3();

    char _derivedL3name[32];


  private:
    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateDerivedL3MemberFunction1();

    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateDerivedL3MemberFunction2();

    /// A normal non-virtual private function.  Can't be overridden in a derived class.
    void privateDerivedL3MemberFunction3();
};

#endif // MYEXAMPLEDERIVEDCLASSL3_H
