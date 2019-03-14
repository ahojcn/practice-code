#include <stdio.h>

int main()
{
    
    
    
    return 0;
}



//
//#include <stdio.h>
//#include <ctype.h>
//
//int main()
//{
////    printf("%d", iscntrl('\t'));
////    printf("\v");
//
////    isdigit('0');
////    isxdigit('A');
////    islower(<#int _c#>)
////    isalpha(<#int _c#>)
////    isalnum(<#int _c#>)
////    ispunct()
////    isgraph(<#int _c#>)
////    isprint(<#int _c#>)
//
//    return 0;
//}

//
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//
//int main()
//{
//    FILE *fp = fopen("test.txt", "r");
//    if(fp == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//
//    return 0;
//}

//int main()
//{
//    char str[100] = "abcdefg@qq.com";
//    char *e = "@.";
//    char *p = NULL;
//    p = strtok(str, e);
//
//    while(p != NULL)
//    {
//        puts(p);
//        p = strtok(NULL, e);
//    }
//
//    return 0;
//}

//int main()
//{
//    char str[100] = "str::::str...end";
//    char *e = ":.";
//    char *p = strtok(str, e);
//    while(p != NULL)
//    {
//        puts(p);
//        p = strtok(NULL, e);
//    }
//
//    return 0;
//}






//int main(int argc, const char * argv[])
//{
//    const char * s1 = "abcdef";
//    const char * s2 = "ab";
//    if(strlen(s2) - strlen(s1) > 0)
//    {
//        printf("s1 < s2\n");
//    }
//    else
//    {
//        printf("s1 > s2\n");
//    }
//
//    return 0;
//}


//int main()
//{
//    char * src = "abc";
//    char dst[10] = "1234564881";
//
//    strncpy(dst, src, 6);
//
//    return 0;
//}


//int main()
//{
//    char * src = "abc";
//    char dst[15] = "12345";
//    strncat(dst, src, 6);
//    
//    return 0;
//}

//int main()
//{
//    char str[][5] = { "R2D2", "C3PO", "R2A6" };
//    for(int n=0; n<3; n++)
//    {
//        if(strncmp(str[n], "R2xx", 2) == 0)
//        {
//            printf("%s\n", str[n]);
//        }
//    }
//
//    return 0;
//}



//int main()
//{
//    char str[] = "This is a simple string!";
//    char * p = NULL;
//    p = strstr(str, "simple");
//    printf("%s\n", p);
//    strncpy(p, "aaaaaa", 6);
//    puts(p);
//
//    return 0;
//}




