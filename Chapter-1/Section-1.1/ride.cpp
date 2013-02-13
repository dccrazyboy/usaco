/*
ID: dccrazy2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, team;
    fin >> comet >> team;
    int comet_num = 1, team_num = 1;
    int i = 0;
    while (i < comet.length())
        comet_num *= comet[i++]- 'A' + 1;
    i = 0;
    while (i < team.length())
        team_num *= team[i++]- 'A' + 1;
    if (comet_num%47 == team_num%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}
