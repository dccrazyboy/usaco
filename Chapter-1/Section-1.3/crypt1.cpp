/*
ID: dccrazy2
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n, N[9];

bool inN(int num)
{
    while (num != 0)
    {
        int mod = num%10;
        int i;
        bool find = false;
        for (i = 0;i < n;i++)
            if (N[i] == mod)
                find = true;
        if (find == false)
            return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    fin >> n;
    int i,j;
    for(i = 0;i < n;i++)
        fin >> N[i];

    int count = 0;
    for (i = 100;i <= 999;i++)
        for (j = 10;j <= 99;j++)
        {
            if (i*j>=1000 && i*j<=9999
                && i*(j%10)>=100 && i*(j%10)<=999
                && i*(j/10)>=100 && i*(j/10)<=999)
            {
                if (inN(i) && inN(j) && inN(i*(j%10)) && inN(i*(j/10)) && inN(i*j))
                    count++;
            }
        }
    fout << count << endl;
    return 0;
}
