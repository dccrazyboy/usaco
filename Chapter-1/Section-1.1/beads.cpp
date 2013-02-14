/*
ID: dccrazy2
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
using namespace std;

int N;
string necklace;

char findcolor(int pos,bool left)
{
    int inc = left?-1:1;
    while (necklace[pos] == 'w')
        pos = (pos + inc + N)%N;
    return necklace[pos];
}

int cal(int pos,bool left)
{
    int inc = left?-1:1;
    pos = left?pos:pos+1;
    char color = findcolor(pos,left);
    int count = 0;
    while (necklace[pos] == color || necklace[pos] == 'w')
    {
        pos = (pos + inc + N)%N;
        count++;
    }
    return count;
}

int cut(int pos)
{
    return cal(pos,true)+cal(pos,false);
}

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    fin >> N >> necklace;

    int i;
    for (i = 0;i < N;i++)
        if (necklace[i] !=necklace[0])
            break;
    if (i == N)
    {
        fout << N << endl;
        return 0;
    }

    int max = 0;
    for (i=0; i<N; i++)
    {
        int now = cut(i);
        max = max>now?max:now;
    }

    fout << max << endl;
    return 0;
}
