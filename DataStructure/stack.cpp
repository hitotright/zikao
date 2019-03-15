#include <cstdio>
#include <cstdlib>


#define STACK_INIT_SIZE 100
#define STACK_INC 10
#define OK true
#define ERROR false
#define OVERFLOW 500

typedef int SElemType;
typedef bool Status;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

Status InitStack(SqStack &S);

Status DestroyStack(SqStack &S);

Status ClearStack(SqStack &S);

Status StackEmpty(SqStack &S);

int StackLength(SqStack &S);

Status GetTop(SqStack S, SElemType &e);

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

Status StackTraverse(SqStack S, Status(*visit)());

Status InitStack(SqStack &S) {
    S.base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    printf("InitS.top:%u",S.top);
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(SqStack S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(S.top - 1);
    return OK;
}

Status Push(SqStack &S, SElemType e) {
    if (S.top - S.base >= S.stacksize) {
        S.base = (SElemType *) realloc(S.base, (S.stacksize + STACK_INC) * sizeof(SElemType));
        if (!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACK_INC;
    }
    printf("PushS.top:%u\n",S.top);
    *(S.top++) = e;
    printf("PushS.top:%u\n",S.top);
    return OK;
}

Status Pop(SqStack &S, SElemType &e) {
    if (S.top == S.base) return ERROR;
    e = *(--S.top);
    return OK;
}

int c = 0;
void move(char x,int n,char z){
        printf("%i move disk.%i from %c to %c \n",++c,n,x,z);
}
//将n个盘子从x移动到z,辅助杆为y
void hanoi(int n,char x,char y,char z){
    if(n == 1){
        move(x,1,z);
    }else{
        hanoi(n-1,x,z,y);
        move(x,n,z);
        hanoi(n-1,y,x,z);
    }
}

int main() {
    printf("Stack Test \n");
    SqStack S;
    SElemType e1 = 8;
    SElemType e2 = 9;
    SElemType t1, t2;
    Status status = InitStack(S);
    printf("status:%d \n", status);
    status = Push(S, e1);
    status = Push(S, e2);
    status = Pop(S, t1);
    status = Pop(S, t2);
    printf("t1:%d,t2:%d\n", t1,t2);

    hanoi(5,'x','y','z');
    return 0;
}