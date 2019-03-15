//
// Created by hitotright on 2019/3/7.
//
#include <stdio.h>
#include <stdlib.h>

#define MAXQSIZE 5
#define OK true
#define ERROR false
#define OVERFLOW 500

typedef bool Status;
typedef int QElemType;
typedef struct {
    QElemType * base;
    int front;//前
    int rear;//尾
} SqQueue;

Status InitQueue(SqQueue &Q){
    Q.base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
    if(!Q.base) exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLength(SqQueue Q){
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q,QElemType e){
    if((Q.rear +1)%MAXQSIZE == Q.front){
        return ERROR;//队列已满
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear +1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e){
    if(Q.front == Q.rear) return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front +1) % MAXQSIZE;
    return OK;
}

int main(){
    printf("Queue Test \n");
    SqQueue Q;
    InitQueue(Q);
    for(int i=1;i <= 7;i++) {
        bool b = EnQueue(Q,i);
        if(!b){
            break;
        }
        printf("i=%i,Q.len:%d,Q.front:%d,Q.rear:%d,Q.base:%u\n",i,QueueLength(Q),Q.front,Q.rear,Q.base);
    }

    QElemType e;
    for(int i=1;i <= 7;i++) {
        bool b = DeQueue(Q,e);
        if(!b){
            break;
        }
        printf("e:%d",e);
        printf("i=%i,Q.len:%d,Q.front:%d,Q.rear:%d,Q.base:%u\n",i,QueueLength(Q),Q.front,Q.rear,Q.base);
    }

    

}
