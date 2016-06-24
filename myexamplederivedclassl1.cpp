#include "myexamplederivedclassl1.h"

MyExampleDerivedClassL1::MyExampleDerivedClassL1()
  :MyExampleBaseClass(),
    _derivedL1name{"MyExampleDerivedClassL1"}
{

}

MyExampleDerivedClassL1::~MyExampleDerivedClassL1()
{

}

void MyExampleDerivedClassL1::publicDerivedL1MemberFunction1()
{

}

void MyExampleDerivedClassL1::publicDerivedL1MemberFunction2()
{

}

void MyExampleDerivedClassL1::publicDerivedL1MemberFunction3()
{

}

void MyExampleDerivedClassL1::publicBaseMemberFunction1()
{

}

void MyExampleDerivedClassL1::populatename(char withWhat)
{
  memset(&_derivedL1name[0], withWhat, sizeof(_derivedL1name));
  MyExampleBaseClass::populatename(withWhat);
}

void MyExampleDerivedClassL1::protectedDerivedL1MemberFunction1()
{

}

void MyExampleDerivedClassL1::protectedDerivedL1MemberFunction2()
{

}

void MyExampleDerivedClassL1::protectedDerivedL1MemberFunction3()
{

}

void MyExampleDerivedClassL1::protectedBaseMemberFunction1()
{

}

void MyExampleDerivedClassL1::privateBaseMemberFunction1()
{

}

void MyExampleDerivedClassL1::privateDerivedL1MemberFunction1()
{

}

void MyExampleDerivedClassL1::privateDerivedL1MemberFunction2()
{

}

void MyExampleDerivedClassL1::privateDerivedL1MemberFunction3()
{

}

