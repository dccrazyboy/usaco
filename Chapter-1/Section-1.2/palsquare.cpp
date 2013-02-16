/*
ID: dccrazy2
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void itoa(int num,char ans[],int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int mod;
    int pos = 0;
    do
    {
        mod = num % radix;
        num /= radix;
        ans[pos++] = index[mod];
    } while(num != 0);
    ans[pos] = 0;

    int i;
    char tp;
    for (i = 0; i < pos/2; i++)
    {
        tp = ans[i];
        ans[i] = ans[pos-1-i];
        ans[pos-1-i] = tp;
    }
    return;
}

bool isPalindrome(char s[])
{
    int i;
    int len = strlen(s);
    for (i = 0; i < len/2; i++)
        if (s[i] != s[len-1-i])
            return false;
    return true;
}

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");

    int B;
    fin >> B;
    int i;
    for (i = 1; i <= 300; i++)
    {
        char ansi2[10];
        itoa(i*i,ansi2,B);
        if (isPalindrome(ansi2))
        {
            char ansi[10];
            itoa(i,ansi,B);
            fout << ansi << " " << ansi2 << endl;
        }
    }
    return 0;
}
