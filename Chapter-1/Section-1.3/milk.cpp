/*
ID: dccrazy2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Milk
{
    int price;
    int vol;
};

Milk milk[5000];

int cmp( const Milk &a, const Milk &b ){
    return a.price < b.price;
}

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int N, M;
    fin >> N >> M;
    int i;
    for (i = 0; i < M; i++)
        fin >> milk[i].price >> milk[i].vol;
    sort(milk,milk+M,cmp);

    int price = 0;
    int pos = 0;
    while (N > 0)
    {
        if (N > milk[pos].vol)
        {
            price += milk[pos].price * milk[pos].vol;
            N -= milk[pos].vol;
        }
        else
        {
            price += milk[pos].price * N;
            N = 0;
        }
        pos++;
    }
    fout << price << endl;
    return 0;
}
