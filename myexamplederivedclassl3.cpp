#include "myexamplederivedclassl3.h"

MyExampleDerivedClassL3::MyExampleDerivedClassL3()
  :MyExampleDerivedClassL2(),
    _derivedL3name{"MyExampleDerivedClassL3"}
{

}

MyExampleDerivedClassL3::~MyExampleDerivedClassL3()
{

}

void MyExampleDerivedClassL3::publicDerivedL3MemberFunction1()
{

}

void MyExampleDerivedClassL3::publicDerivedL3MemberFunction2()
{

}

void MyExampleDerivedClassL3::publicDerivedL3MemberFunction3()
{

}

void MyExampleDerivedClassL3::populatename(char withWhat)
{
  memset(&_derivedL3name[0], withWhat, sizeof(_derivedL3name));
  MyExampleDerivedClassL2::populatename(withWhat);
}

void MyExampleDerivedClassL3::protectedDerivedL3MemberFunction1()
{

}

void MyExampleDerivedClassL3::protectedDerivedL3MemberFunction2()
{

}

void MyExampleDerivedClassL3::protectedDerivedL3MemberFunction3()
{

}

void MyExampleDerivedClassL3::privateDerivedL3MemberFunction1()
{

}

void MyExampleDerivedClassL3::privateDerivedL3MemberFunction2()
{

}

void MyExampleDerivedClassL3::privateDerivedL3MemberFunction3()
{

}

