#include <iostream>

int main()
{
    // 指针常量与常量指针

    const double pi = 3.14;         // pi是一个常量，其值不更改变
    // pi = 4.44;                   // 错误：表达式必须是可修改的左值C/C++(137)
    // double *p = &pi;             // 错误："const double *" 类型的值不能用于初始化 "double *" 类型的实体C/C++(144)
    const double *ptr = &pi;        // 正确，这里可以p为指针常量（pointer to const），表示指针指向的对象是一个常量

    int errNumb = 10;
    int *const ptr1 = &errNumb;     // const在*后面，表示ptr是一个常量，也就是常量指针（const pointer），表示指针所指向的地址不能变更了
    int temp = 10;
    // ptr = &temp;                 // 错误：表达式必须是可修改的左值C/C++(137)
    *ptr1 = 20;                     // 正确，此时errNumb为20

    const int *ptr2 = &temp;        // 正确，指向常量的指针没有规定所指向的对象一定是常量
    // *ptr2 = 20;                  // 错误，所谓指向常量的指针仅仅要求不能通过该指针去修改对象的值，可以通过其他方法去修改

    // 底层const和顶层const
    int i = 0;
    int *const p1 = &i;             // p1本身是一个常量，这是一个顶层const
    const int ci = 42;              // ci本身是一个常量，这是一个顶层const
    const int *p2 = &ci;            // p2指向的是一个常量，这是一个底层const
    const int *const p3 = p2;       // 左边的const的意思是指向的对象是一个常量，因此是底层const；右边的const表示这个指针是一个常量，因此是顶层const
    const int &r = i;               // 用于声明引用的const都是底层const

    // 赋值规则
    const int a = 10;
    int b = a;                      // a的const是一个顶层const，不受影响可以忽略

    const int *const pp1 = new int(10);
    // int *pp2 = pp1;              // 错误："const int *" 类型的值不能用于初始化 "int *" 类型的实体C/C++(144)  pp1最左侧的底层const必须一致
    const int *pp3 = pp1;           // 正确
    // int *const pp4 = pp1;        // 错误，pp4的const表示顶层const，不受影响可以忽略，这样与pp1相比缺少一个底层const
    // int *pp4 = &a;               // 虽然a的const是一个顶层const，可以不受影响，但是当使用&a时，表示我们有一个指向a的cosnt指针，也就是底层const，所以pp4也需要有一个底层const
    const int *pp5 = &a;            // 这个就是正确的

    // 引用的补充
    const int m = 10;
    const int &r1 = m;              // 正确，m有底层const，声明引用的const也是底层const
    // int &r2 = m;                 // 错误
    // int &r3 = r1;                // 错误
    int n = r1;                     // 正确，r1是a的别名，这个表达式相当于 int n = a; 这与第31行一样
}