/*
ID: dccrazy2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Time
{
    int start;
    int end;
};

int main()
{
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N,i;
    int start = 1000000,end = 0;
    Time time[5001];
    bool ans[1000001] = {false};

    fin >> N;
    for (i = 0; i < N; i++)
    {
        fin >> time[i].start >> time[i].end;
        if (start > time[i].start)
            start = time[i].start;
        if (end < time[i].end)
            end = time[i].end;
        int j;
        for (j = time[i].start;j < time[i].end;j++)
            ans[j] = true;
    }

    int ans1 = 0, ans2 = 0;
    int count = 0;
    bool nowstatus = true;
    for (i = start; i <= end;i++)
    {
        if (nowstatus == ans[i])
            count++;
        else
        {
            if (nowstatus == true && count > ans1)
                ans1 = count;
            if (nowstatus == false && count > ans2)
                ans2 = count;
            nowstatus = ans[i];
            count = 1;
        }
    }

    fout << ans1 << " " << ans2 << endl;

    return 0;
}
