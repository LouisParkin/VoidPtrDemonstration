#include "myexamplebaseclass.h"

MyExampleBaseClass::MyExampleBaseClass(QObject *parent) : QObject(parent),
_basename{"MyExampleBaseClass"}
{
//  _basename = "MyExampleBaseClass";
}

MyExampleBaseClass::~MyExampleBaseClass()
{

}

void MyExampleBaseClass::publicBaseMemberFunction1()
{

}

void MyExampleBaseClass::publicBaseMemberFunction2()
{

}

void MyExampleBaseClass::publicBaseMemberFunction3()
{

}

void MyExampleBaseClass::populatename(char withWhat)
{
  memset(&_basename[0], withWhat, sizeof(_basename));
}

void MyExampleBaseClass::protectedBaseMemberFunction1()
{

}

void MyExampleBaseClass::protectedBaseMemberFunction2()
{

}

void MyExampleBaseClass::protectedBaseMemberFunction3()
{

}

void MyExampleBaseClass::privateBaseMemberFunction1()
{

}

void MyExampleBaseClass::privateBaseMemberFunction2()
{

}

void MyExampleBaseClass::privateBaseMemberFunction3()
{

}

