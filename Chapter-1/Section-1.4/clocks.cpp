/*
ID: dccrazy2
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

const int fixnum = 57521883;
const int move[10] = {0,18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
const int finishnum = 0;

class Clocks
{
public:
    int clock;
    Clocks()
    {
        clock = 0;
    }
    void Move(int step)
    {
        clock = (clock+move[step]) & fixnum;
    }
    bool finish()
    {
        return clock == finishnum;
    }
};

int main()
{
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
    Clocks clocks;
    int i,j;
    for (i = 0;i < 9;i++)
    {
        int time;
        fin >> time;
        time %= 12;
        time /= 3;
        clocks.clock |= time << 3*(8-i);
    }

    int c[10];
    for(c[1]=0;c[1]<=3;c[1]++)
        for(c[2]=0;c[2]<=3;c[2]++)
            for(c[3]=0;c[3]<=3;c[3]++)
                for(c[4]=0;c[4]<=3;c[4]++)
                    for(c[5]=0;c[5]<=3;c[5]++)
                        for(c[6]=0;c[6]<=3;c[6]++)
                            for(c[7]=0;c[7]<=3;c[7]++)
                                for(c[8]=0;c[8]<=3;c[8]++)
                                    for(c[9]=0;c[9]<=3;c[9]++)
                                    {
                                        Clocks clock = clocks;
                                        for (i = 1; i <= 9; i++)
                                            for (j = 0;j < c[i];j++)
                                                clock.Move(i);
                                        if (clock.finish())
                                        {
                                            stringstream ss;
                                            string outstr;
                                            for (i = 1;i <= 9;i++)
                                                for (j = 0;j < c[i];j++)
                                                    ss << i << " ";
                                            getline(ss, outstr);
                                            outstr = outstr.substr(0,outstr.length()-1);

                                            fout << outstr << endl;
                                        }
                                    }
    return 0;
}
