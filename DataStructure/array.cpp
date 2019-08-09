//
// Created by hitotright on 2019/3/19.
//
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_ARRAY_DIM 8

typedef bool Status;
typedef int ElemType;
typedef struct {
    ElemType * base;//数组元素基址
    int dim;//数组维度
    int * bounds;//数组维界基址
    int * constants;//数组映像函数常量基址
}Array;
va_list ap;
Status InitArray(Array &A,int dim,...){
    if (dim <1||dim > MAX_ARRAY_DIM) return false;
    A.dim = dim;
    A.bounds = (int *)malloc(dim * sizeof(int));
    if (!A.bounds) exit(1);
    int elemtotal = 1;
    va_start(ap,dim);
    for (int i = 0; i < dim ; ++i) {
        A.bounds[i] = va_arg(ap,int);
        if (A.bounds[i]<0) return false;
        elemtotal *= A.bounds[i];
    }
    va_end(ap);
    A.base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if(!A.base) exit(1);
    A.constants = (int *)malloc(dim* sizeof(int));
    if(!A.constants) exit(1);
    A.constants[dim -1] = 1;
    for (int j = dim -2; j >=0 ; --j) {
        A.constants[j] = A.bounds[j+1] * A.constants[j+1];
    }
    return true;
}

Status Locate(Array A,va_list ap,int &off){
    off = 0;
    for (int i = 0; i < A.dim ; ++i) {
        int ind = va_arg(ap,int);
        if (ind <0||ind>A.bounds[i]) return false;
        off +=A.constants[i] * ind;
    }
    return true;
}

Status Value(Array A,ElemType &e,...){
    va_start(ap,e);
    int off;Status result;
    if ((result = Locate(A,ap,off))<=0) return result;
    e = *(A.base + off);
}

Status Assign(Array A,ElemType &e,...){
    va_start(ap,e);
    int off;Status result;
    if((result = Locate(A,ap,off))<=0) return result;
    *(A.base +off) =e;
    return true;
}

int main(){
    Array A;
    InitArray(A,3,1,2,3);
    ElemType e = 4;
    Assign(A,e,1);
    Value(A,e,2);
    printf("e:%d\n",e);
}
