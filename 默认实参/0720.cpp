#include <iostream>
#include <functional>
using namespace std;

int func1(int, int, int = 10);
int func1(int, int = 9, int);
int func1(int = 8, int, int);

int func1(int a, int b, int c)
{
    cout << a << " " << b << " " << c << endl;
    return 1;
}

int a(int);

int a(int b = 121)
{
    return b;
}

class TEST
{
public:
    void f()
    {
        cout << "no parameters" << endl;
    }
    void f(int a)
    {
        cout << "has parameters : " << a << endl;
    }
};

void test1(void(TEST::*p)(int), TEST *test, int n)
{
    (test->*p)(n);
}

int main()
{
    TEST test;
    test1(&TEST::f, &test, 7);
    return 0;
}