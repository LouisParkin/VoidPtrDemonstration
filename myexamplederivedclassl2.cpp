#include "myexamplederivedclassl2.h"

MyExampleDerivedClassL2::MyExampleDerivedClassL2()
  :MyExampleDerivedClassL1(),
    _derivedL2name{"MyExampleDerivedClassL2"}
{

}

MyExampleDerivedClassL2::~MyExampleDerivedClassL2()
{

}

void MyExampleDerivedClassL2::publicDerivedL2MemberFunction1()
{

}

void MyExampleDerivedClassL2::publicDerivedL2MemberFunction2()
{

}

void MyExampleDerivedClassL2::publicDerivedL2MemberFunction3()
{

}

void MyExampleDerivedClassL2::publicDerivedL1MemberFunction1()
{

}

void MyExampleDerivedClassL2::populatename(char withWhat)
{
  memset(&_derivedL2name[0], withWhat, sizeof(_derivedL2name));
  MyExampleDerivedClassL1::populatename(withWhat);
}

void MyExampleDerivedClassL2::protectedDerivedL2MemberFunction1()
{

}

void MyExampleDerivedClassL2::protectedDerivedL2MemberFunction2()
{

}

void MyExampleDerivedClassL2::protectedDerivedL2MemberFunction3()
{

}

void MyExampleDerivedClassL2::protectedDerivedL1MemberFunction1()
{

}

void MyExampleDerivedClassL2::privateDerivedL2MemberFunction1()
{

}

void MyExampleDerivedClassL2::privateDerivedL2MemberFunction2()
{

}

void MyExampleDerivedClassL2::privateDerivedL2MemberFunction3()
{

}

void MyExampleDerivedClassL2::privateDerivedL1MemberFunction1()
{

}

