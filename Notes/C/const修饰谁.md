# const修饰的谁?

> 要在编程中多正确的使用const来使程序变得更加健壮。
>
> 《高质量C++/C编程指南》

const是修饰谁?

```c
#include <stdio.h>

int main(int argc, const char * argv[])
{
    const int num = 1;	// 等价 int const num = 1;
    
    num = 2;	// ERROR!
    
    int *p = &num;	//WARNING!
    
    *p = 30;
    
    printf("*p = %d\n", *p);
    
    return 0;
}
```

`ERROR:Cannot assign to variable 'num' with const-qualified type 'const int'`

`WARNING:Initializing 'int *' with an expression of type 'const int *' discards qualifiers`

给出了警告，现在的编译器都挺严格。

`const int num = 1;`中的const修饰num是一个不可改变的变量，但是当我们用一个指针指向num，然后用指针改变值时却可以。注释掉ERROR那句运行结果为`p = 30`。这个要注意！

```c
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int num = 1;
    
    const int *p = &num;
    
    *p = 30; // ERROR!
    
    printf("*p = %d\n", *p);
    
    return 0;
}
```

`ERROR:Read-only variable is not assignable`

`const int *p = &num;`中const修饰的是*p，也就是num，这句话的意思就是**不能通过p来修改变量num的值**。这句话和`int const *p = &num;`是等价的，都是修饰\*p。

```c
int main(int argc, const char * argv[])
{
    int num = 1;
    int test = 20;
    
    int * const p = &num;
    
    *p = 30;
    
    p = &test;	// ERROR!
    
    printf("*p = %d\n", *p);
    
    return 0;
}
```

`ERROR:Cannot assign to variable 'p' with const-qualified type 'int *const'`

`int * const p = &num;`中的const修饰的是指针p，也就是p里的值是不可以改变的，不可以改变指针的指向。