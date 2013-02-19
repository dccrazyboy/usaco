/*
ID: dccrazy2
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

#define MAX(x,y) ((x>y)?(x):(y))

using namespace std;

int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int R;
    int dp[1001] = {0};
    //int dp2[1001] = {0};
    int input[1001];

    fin >> R;
    int i,j;
    fin >> dp[1];
    for (i = 2;i <= R;i++)
    {
        for (j = 1;j <= i;j++)
            fin >> input[j];

        // j = i
        dp[i] = dp[i-1] + input[i];

        // j = i-1...2
        for (j = i-1;j >= 2;j--)
            dp[j] = MAX(dp[j-1],dp[j])+input[j];

        // j = 1
        dp[1] = dp[1] + input[1];
    }

    int max = 0;
    for (i = 1;i <= R;i++)
        max = MAX(max,dp[i]);

    fout << max << endl;
    return 0;
}
