/*
ID: dccrazy2
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int cmpinterspace( const int &a, const int &b ){
    return a > b;
}

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    int M, S, C;
    int cowpos[201];
    fin >> M >> S >> C;

    // for M > C
    if (M > C)
    {
        fout << C << endl;
        return 0;
    }

    int i;
    for (i = 0;i < C;i++)
        fin >> cowpos[i];
    sort(cowpos,cowpos+C);

    int interspace[201];
    for (i = 0; i < C-1; i++)
        interspace[i] = cowpos[i+1] - cowpos[i] - 1;
    sort(interspace,interspace+C-1,cmpinterspace);

    int nowlen = cowpos[C-1] - cowpos[0] + 1;
    for (i = 0; i < M - 1; i++)
    {
        nowlen -= interspace[i];
    }
    fout << nowlen << endl;
    return 0;
}
