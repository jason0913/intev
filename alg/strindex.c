/*
 * =====================================================================================
 *
 *       Filename:  strindex.c
 *
 *    Description:  string index
 *
 *        Version:  1.0
 *        Created:  2015年04月30日 10时04分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100
 typedef struct 
 {
     char ch[MAXSIZE];
    unsigned int length;
 }String;

/*int strindex(String S, String T,int pos)
{
    int n,m,i;
    String sub;
    if (pos > 0) 
    {
        n= StrLength(S);
        m =StrLength(T);
        i = pos;
        while(i <=n-m+1)
        {
            SubString(sub,S,i,m);
            if (Strcompare(sub,T) != 0)
            {
                ++i;
            }
            else
                return i;
        }
    }
    return 0;
}
*/
void Concat(String *S,String T1,String T2)
{
    int i,n;
    n = MAXSIZE;
    if (T1.length +T2.length <= MAXSIZE)
    {
        for (i = 0; i < T1.length; ++i)
        {
            S->ch[i] = T1.ch[i];
        }
        for (i = 0; i < T2.length; ++i)
        {
            S->ch[T1.length+i] = T2.ch[i];
        }
        S->length =T1.length+T2.length;
        S->ch[S->length+1] ='\0';
    }
    else if (T1.length + T2.length > MAXSIZE && T1.length < MAXSIZE)
    {
        for (i = 0; i < T1.length; ++i)
        {
            S->ch[i] = T1.ch[i];
        }
        for (i = 0; i < MAXSIZE -T1.length; ++i)
        {
            S->ch[T1.length+i] = T2.ch[i];
        }
        S->length = T1.length+i;
        S->ch[S->length+1] ='\0';
    }
    else if (T1.length ==MAXSIZE)
    {
        for (i = 0; i < T1.length; ++i)
        {
            S->ch[i]= T1.ch[i];
        }
        S->length =MAXSIZE;
        S->ch[S->length+1]='\0';
    }
}
void Init_strig(String *S)
{
    fgets(S->ch,sizeof(S->ch),stdin);
    S->length = strlen(S->ch)-1;
}
void Print_string(String S)
{
    printf("%s,length %d\n", S.ch,S.length);
}
void SubString(String *T,String S,int pos,int len)
{
    int i;
    if (pos < 1 || pos > S.length || len <1 || len >S.length - pos)
    {
        printf("position or len invalid\n");
        return;
    }
    else
    {
        for (i = 0; i < len; ++i)
        {
            T->ch[i]=S.ch[pos-1+i];
        }
        T->length = len;
    }
}
int main(int argc, char const *argv[])
{
    String S,T1,T2,T3;
    int pos,len;
    printf("Init T1\n");
    Init_strig(&T1);
    printf("Init T2\n");
    Init_strig(&T2);
    printf("T1 and  T2:\n");
    Print_string(T1);
    Print_string(T2);
    printf("Concat :\n");
    Concat(&S,T1,T2);
    Print_string(S);
    printf("SubString S:pos and len:\n");
    scanf("%d %d",&pos,&len);
    SubString(&T3,S,pos,len);
    Print_string(T3);
    return 0;
}
