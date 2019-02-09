//
//  main.c
//  20190203_StructMemeryUsed
//
//  Created by hanoi_ahoj on 2019/2/3.
//  Copyright © 2019 ahoj. All rights reserved.
//

#include <stdio.h>

struct s1 {
    char c1;
    int i;
    char c2;
};

struct s2 {
    char c1;
    char c2;
    int i;
};

struct s3 {
    double d;
    char c;
    int i;
};

struct s4 {
    char c1;
    struct s3 s;
    double d;
};

int main(int argc, const char * argv[]) {
    printf("%lu\n", sizeof(struct s1));
    printf("%lu\n", sizeof(struct s2));
    printf("%lu\n", sizeof(struct s3));
    printf("%lu\n", sizeof(struct s4));
    return 0;
}
