//
// Created by hanoi_ahoj on 2018/12/30.
//

#include "Stack.h"

void StackInit(Stack *ps) {
    assert(ps != NULL);
    ps->s_top = -1;
}

void StackPush(Stack *ps, const StackElemType e) {
    assert(ps != NULL);
    if (ps->s_top == MAXLENGTH - 1) {
        printf("ERROR:栈满\n");
        exit(1002);
    }
    else {
        ps->s_top ++;
        ps->s_data[ps->s_top] = e;
    }
}

void StackPop(Stack *ps) {
    assert(ps != NULL);
    if (StackFull(ps)) {
        printf("ERROR:栈空\n");
        exit(1003);
    }
    else {
        ps->s_top --;
    }
}

StackElemType StackGetTop(const Stack *ps) {
    assert(ps != NULL);
    if (StackEmpty(ps)) {
        printf("ERROR:栈空\n");
        exit(1004);
    }
    else {
        return ps->s_data[ps->s_top];
    }
}

bool StackEmpty(const Stack *ps) {
    assert(ps != NULL);
    return ps->s_top == -1 ? true : false;
}

bool StackFull(const Stack *ps) {
    assert(ps != NULL);
    return ps->s_top == MAXLENGTH-1 ? true : false;
}