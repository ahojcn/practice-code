#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    const char * src = "hello world!";
    char dst[100] = {0};
    memcpy(dst, src, 12);
    printf("%s\n", dst);
    
    return 0;
}
