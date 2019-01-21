#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define A(uc, x) uc##x

#pragma pack(1)
typedef struct sup
{
    unsigned char uc1 : 1;
    unsigned char uc2 : 1;
    unsigned char uc3 : 1;
    unsigned char uc4 : 1;
    unsigned char uc5 : 1;
    unsigned char uc6 : 1;
    unsigned char uc7 : 1;
    unsigned char uc8 : 1;
} *pSUP_S;
#pragma pack()


void bit_set(unsigned char *p_data, unsigned char pos, int flag)
{
    pSUP_S ps = (pSUP_S)p_data;
    switch(pos)
    {
        case 1:
            ps->A(uc, 1) = flag;
            break;
        case 2:
            ps->A(uc, 2) = flag;
            break;
        case 3:
            ps->A(uc, 3) = flag;
            break;
        case 4:
            ps->A(uc, 4) = flag;
            break;
        case 5:
            ps->A(uc, 5) = flag;
            break;
        case 6:
            ps->A(uc, 6) = flag;
            break;
        case 7:
            ps->A(uc, 7) = flag;
            break;
        case 8:
            ps->A(uc, 8) = flag;
            break;
        default:
            break;
    }
}

void print(unsigned char a)
{
    while(a)
    {
        printf("%d", a%2);
        a /= 2;
    }
    printf("\n");
}

int main()
{
    unsigned char a = 1;
    bit_set(&a, 5, 1);
    print(a);
    return 0;
}
