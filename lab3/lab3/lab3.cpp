// lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MyFirstClass
{
private:
    int a;
    int b;
public:
    void SetObj(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    void GetObj()
    {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    int c()
    {
        return a/= - b;
    }
};
int main()
{
    MyFirstClass Obj;
    Obj.SetObj(15,-3);
    Obj.GetObj();
    int c = Obj.c();
    cout << c << endl;
    return 0;
}

