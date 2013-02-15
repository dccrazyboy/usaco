/*
ID: dccrazy2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void op1(int N,const char square1[10][10],char square2[10][10])
{
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            square2[i][j] = square1[N-1-j][i];
}

void op2(int N,const char square1[10][10],char square2[10][10])
{
    char s1[10][10];
    op1(N,square1,s1);
    op1(N,s1,square2);
}

void op3(int N,const char square1[10][10],char square2[10][10])
{
    char s1[10][10],s2[10][10];
    op1(N,square1,s1);
    op1(N,s1,s2);
    op1(N,s2,square2);
}

void op4(int N,const char square1[10][10],char square2[10][10])
{
    int i,j;
    for (i = 0; i < N;i++)
        for (j = 0; j < N; j++)
            square2[i][j] = square1[i][N-1-j];
}

void op5_1(int N,const char square1[10][10],char square2[10][10])
{
    char s1[10][10];
    op4(N,square1,s1);
    op1(N,s1,square2);
}

void op5_2(int N,const char square1[10][10],char square2[10][10])
{
    char s1[10][10];
    op4(N,square1,s1);
    op2(N,s1,square2);
}

void op5_3(int N,const char square1[10][10],char square2[10][10])
{
    char s1[10][10];
    op4(N,square1,s1);
    op3(N,s1,square2);
}

void op6(int N,const char square1[10][10],char square2[10][10])
{
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            square2[i][j] = square1[i][j];
}

bool equal(int N,const char square1[10][10],const char square2[10][10])
{
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (square1[i][j] != square2[i][j])
                return false;
    return true;
}

typedef void (*OP)(int,const char [][10],char [][10]);
OP op[]={op1,op2,op3,op4,op5_1,op5_2,op5_3,op6};
//        0   1   2   3    4     5     6    7

int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int N;
    char square[10][10],tosquare[10][10];
    fin >> N;
    int i,j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            fin >> square[i][j];
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            fin >> tosquare[i][j];

    char afterop[10][10];

    for (i = 0;i < 8;i++)
    {
        op[i](N,square,afterop);
        if (equal(N,tosquare,afterop))
        {
            if (i < 4)
                fout << i + 1 << endl;
            else if (i >= 4 && i < 7)
                fout << 5 << endl;
            else
                fout << 6 << endl;
            return 0;
        }
    }
    fout << 7 << endl;
    return 0;
}
