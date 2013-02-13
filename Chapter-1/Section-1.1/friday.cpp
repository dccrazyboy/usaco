/*
ID: dccrazy2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            return true;
        else
            return false;
    }
    if (year % 4 == 0)
        return true;
    else
        return false;
}

int main()
{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n, count[7]={0};
    fin >> n;
    int i,j;

    // 1900.1.13 is Saturday
    int now = 6;
    int year[] = {31,29,31,30,31,30,31,31,30,31,30,31};
    for (i = 1900;i < 1900 + n;i++)
    {
        if (is_leap_year(i))
            year[1] = 29;
        else
            year[1] = 28;
        for (j = 0;j < 12;j++)
        {
            count[now]++;
            now += year[j];
            now %= 7;
        }
    }

    fout << count[6] << " "
        << count[0] << " "
        << count[1] << " "
        << count[2] << " "
        << count[3] << " "
        << count[4] << " "
        << count[5] << endl;

    return 0;
}
