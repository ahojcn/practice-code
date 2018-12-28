# 模拟实现strcpy和strlen函数的几个注意点

> 资料：《高质量C++/C编程》

在模拟实现函数的过程中，不只要只实现个功能，还要注重如何让代码更加健壮！

先来给出code，下面再详细解释：

```c
#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char *str_dest, const char *str_src)
{
    assert(str_dest != NULL);
    assert(str_src != NULL);
    
    char *tmp = str_dest;
    
    while((*tmp++ = *str_src++))
    {
        ;
    }
    
    return str_dest;
}

unsigned int my_strlen(const char *str)
{
    int count = 0;
    assert(str != NULL);
    
    while(*str != '\0')
    {
        count++;
        str++;
    }
    
    return count;
}

int main()
{
    char *str1 = "abc";
    char str2[10] = "1234567890";
    
    // 将str1中的字符拷贝到str2中
    my_strcpy(str2, str1);
    printf("str2 : %s\n", str2);
    printf("str2 : %s\n", my_strcpy(str2, str1));
    
    // 
    int len = my_strlen(str2);
    printf("str2_len : %d\n", len);
    printf("str2_len : %d\n", my_strlen(str2));
    
    return 0;
}
```

1. **assert**

   在函数中需要对指针进行解引用时，就需要用assert来断言。

   在没有assert的情况下，传进去一个空指针：

   ```c
   my_strcpy(str2, NULL);
   printf("str2 : %s\n", str2);
   ```

   build succeeded，但在run的时候崩了：

   ![](https://wx3.sinaimg.cn/mw690/006wR0dcly1fwo1u6tk8zj31by16yjyi.jpg)

   有assert的情况下，传进去一个空指针，同样run的时候出现错误，但提示了错误的地方，这样就有利于排查程序中的错误。

   ![](https://wx1.sinaimg.cn/mw690/006wR0dcly1fwo1u6eqotj31f616ygto.jpg)

   在看string.h中的函数源码时候会发现，strcpy中并没有assert，但是在自己写的时候加上就方便检查错误。

   在测试时(debug)启用断言，在部署(release)时禁用断言。

   ![](https://wx1.sinaimg.cn/mw690/006wR0dcly1fwo1u7fxktj31f616y15m.jpg)

   > 编写代码时，我们总是会做出一些假设，断言就是用于在代码中捕捉这些假设，可以将断言看作是[异常处理](https://baike.baidu.com/item/%E5%BC%82%E5%B8%B8%E5%A4%84%E7%90%86/6250107)的一种高级形式。断言表示为一些[布尔表达式](https://baike.baidu.com/item/%E5%B8%83%E5%B0%94%E8%A1%A8%E8%BE%BE%E5%BC%8F/1574380)，程序员相信在程序中的某个特定点该表达式值为真。可以在任何时候启用和禁用断言验证，因此可以在测试时启用断言，而在部署时禁用断言。同样，程序投入运行后，最终用户在遇到问题时可以重新启用断言。

2. **const**

   在传递参数时候，有必要加上const来约束在函数中的权限。

   不加const时，若误将代码写如下：

   ```c
   while(*str_src++ = *tmp++)
   {
       ;
   }
   ```

   build succeeded but run error！

   但如果有const：

   `Read-only variable is not assignable`

   build就会不通过，这样就不会导致更严重的运行时的问题，将误写错误扼杀在摇篮里～

3. **返回值**

   + strcpy函数：

     这个函数为什么要返回值呢？

     为了实现链式表达，增加灵活性。

     `printf("str2 : %s\n", my_strcpy(str2, str1));`

   - strlen函数的返回值unsigned int：

     在string.h中，strlen的返回值为unsigned int。

     意思都明白，他的意思是长度没有负的嘛，但是

     有的时候这个unsigned int不是很好用，例如：

     ```c
     #include <stdio.h>
     #include <string.h>
     #include <assert.h>
     unsigned int my_strlen(const char *str)
     {
         int count = 0;
         assert(str != NULL);
         
         while(*str != '\0')
         {
             count++;
             str++;
         }
         
         return count;
     }
     
     int main()
     {
         char *str1 = "abc";
         char str2[10] = "1234567890";
         
         if(my_strlen(str1) - my_strlen(str2) > 0)
         {
             printf("length: str1 > str2\n");
         }
         else
         {
             printf("length: str1 <= str2\n");
         }
         
         return 0;
     }
     ```

     运行结果如下：

     `length: str1 > str2`

     这是为什么呢？str1的长度不是比str2小吗？

     这就是unsigned int惹的祸。

     `my_strlen(str1) - my_strlen(str2)`前面小的无符号整型减去后面大一点的无符号整型得到的结果还是一个无符号整型(而且是一个很大的数)，所以这个条件成立，继续下面的。

     这个就要注意咯～