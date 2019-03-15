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

void get_next(char T[], int &nextval[]) {
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if (T[i] != T[j]) {
                nextval[i] = j;
            } else {
                nextvar[i] = nextval[j];
            }
        } else {
            j = nextvar[j];
        }
    }
}

//KMP
int Index_KMP(char s[], char p[]) {
    int i = 0;
    int j = 0;
    int next[] = {};
    get_next(p, next);
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
    char S[] = "acabaabaab";
    char T[] = "ab";
    int p = ViolentMatch(S, T, 0);
    printf("pos:%d", p);
}

