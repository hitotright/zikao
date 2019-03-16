//
// Created by hitotright on 2019/3/8.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char SString[];
typedef struct {
    char *ch;
    int length;
} HString;

//代表当前字符之前的字符串中，有多大长度的相同前缀后缀。例如如果next [j] = k，代表j 之前的字符串中有最大长度为k 的相同前缀后缀
void getNext(char p[],int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}


//KMP
int KMP(char s[], char p[]) {
    int i = 0;
    int j = 0;
    int next[] = {};
    getNext(p, next);
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen) {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}

//暴力匹配
int ViolentMatch(char s[], char p[], int pos) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++
            i++;
            j++;
        } else {
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0
            i = i - j + 1;
            j = 0;
        }
    }
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (j == pLen)
        return i - j;
    else
        return -1;
}


int main() {
    char S[] = "bbc abcdab abcdabcdabde";
    char T[] = "abcdabd";
//    int p = ViolentMatch(S, T, 0);
//    printf("pos:%d\n", p);
    int next[strlen(T)];
    getNext(T,next);
    for (int i = 0; i < strlen(T); ++i) {
        printf("pos:%d\n", next[i]);
    }
}

