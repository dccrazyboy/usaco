/*
ID: dccrazy2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct People
{
    string name;
    int start;
    int income;
    int left;
};
int NP;
People people[10];

int getID(string name)
{
    int i;
    for (i = 0; i < NP; i++)
        if (name == people[i].name)
            break;
    return i;
}

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> NP;
    int i;
    for (i = 0;i < NP;i++)
    {
        fin >> people[i].name;
        people[i].start = 0;
        people[i].income = 0;
        people[i].left = 0;
    }
    while (fin)
    {
        string name;
        fin >> name;
        i = getID(name);
        fin >> people[i].start;
        int tonum;
        fin >> tonum;
        if (tonum == 0)
        {
            people[i].left = people[i].start;
            continue;
        }
        people[i].left = people[i].start % tonum;
        int j;
        for (j = 0;j < tonum;j++)
        {
            fin >> name;
            people[getID(name)].income += people[i].start / tonum;
        }
    }

    for (i = 0;i < NP;i++)
    {
        fout << people[i].name << " " <<
            people[i].income - (people[i].start - people[i].left) << endl;
    }
    return 0;
}
