/*
ID: dccrazy2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

int trans['Z']={0};


int main()
{
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict ("dict.txt");
    // init trans table
    trans['A']=2;
    trans['B']=2;
    trans['C']=2;

    trans['D']=3;
    trans['E']=3;
    trans['F']=3;

    trans['G']=4;
    trans['H']=4;
    trans['I']=4;

    trans['J']=5;
    trans['K']=5;
    trans['L']=5;

    trans['M']=6;
    trans['N']=6;
    trans['O']=6;

    trans['P']=7;
    trans['R']=7;
    trans['S']=7;

    trans['T']=8;
    trans['U']=8;
    trans['V']=8;

    trans['W']=9;
    trans['X']=9;
    trans['Y']=9;

    long long num;
    fin >> num;
    char cnum[20];
    sprintf(cnum,"%lld",num);
    unsigned int numlen = strlen(cnum);

    int i;
    bool find = false;
    for (i = 0; i < 4617;i++)
    {
        char name[20];
        dict >> name;
        if (strlen(name) != numlen)
            continue;
        long long namenum = 0;
        unsigned int j;
        for (j = 0;j < strlen(name);j++)
            namenum += trans[name[j]] * pow(10,strlen(name)-1-j);
        if (namenum == num)
        {
            find = true;
            fout << name << endl;
        }
    }

    if (find == false)
        fout << "NONE" << endl;
    return 0;
}
