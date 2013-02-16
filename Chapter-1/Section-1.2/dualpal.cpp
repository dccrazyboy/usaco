/*
ID: dccrazy2
PROG: dualpal
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
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    int N, S;
    fin >> N >> S;
    while (N > 0)
    {
        S++;
        int i;
        int count = 0;
        char ans[100];
        for(i = 2; i <= 10; i++)
        {
            itoa(S,ans,i);
            if (isPalindrome(ans))
                count++;
        }
        if (count >= 2)
        {
            fout << S << endl;
            N--;
        }

    }
    return 0;
}
