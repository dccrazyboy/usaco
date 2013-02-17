/*
ID: dccrazy2
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long filesize;

char tolower(char c)
{
    return c>='A' && c<='Z' ? c - 'A' + 'a' : c;
}

int calchar(char s[],int start,int end)
{
    int i,count = 0;
    for (i = start; i <= end; i++)
        if ((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
        {   //cout << s[i];
            count++;
        }
    return count;
}

char findNextChar(char s[],int &pos,bool left)
{
    int inc = left?-1:1;
    if (pos < 0 || pos > filesize)
        return ' ';
    while (!((s[pos]>='a'&&s[pos]<='z') || (s[pos]>='A'&&s[pos]<='Z')))
    {
        pos += inc;
        if (pos < 0 || pos > filesize)
            return ' ';
    }
    //cout << tolower(s[pos]);
    return tolower(s[pos]);
}

int findMaxPalindrome(char s[],int pos,int &start,int &end)
{
    // odd
    int oddstart = pos;
    int oddend = pos;
    do
    {
        oddstart--;
        oddend++;
        if (oddstart < 0 || oddend > filesize)
            break;
    }while (findNextChar(s,oddstart,true) == findNextChar(s,oddend,false));
    //int oddlen = oddend - oddstart - 1;
    oddstart++;
    oddend--;
    int oddlen = calchar(s,oddstart,oddend);

    // even
    int evenstart = pos;
    int evenend = pos+1;
    while (findNextChar(s,evenstart,true) == findNextChar(s,evenend,false))
    {
        evenstart--;
        evenend++;
        if (evenstart < 0 || evenend > filesize)
            break;
    }
    //int evenlen = evenend - evenstart - 1;
    evenstart++;
    evenend--;
    int evenlen = calchar(s,evenstart,evenend);

    if (oddlen > evenlen)
        goto RET_ODD;
    else if (oddlen < evenlen)
        goto RET_EVEN;
    else
        if (oddstart <= evenstart)
            goto RET_ODD;
        else
            goto RET_EVEN;

RET_ODD:
    start = oddstart;
    end = oddend;
    return oddlen;
RET_EVEN:
    start = evenstart;
    end = evenend;
    return evenlen;
}

int main()
{
/*
    char s[] = "if (abs(terms[lv][lv2]) != 1 || (lv == 0 && lv2 == 0))";
    filesize = 10000;
    int pos,start1 = 4,end1=6;
    pos = 19;
    //findNextChar(s,start1,true);
    //findNextChar(s,end1,false);
    findMaxPalindrome(s,pos,start1,end1);
    cout << endl;
    cout << start1 << " " << end1;
    return 0;
*/
    ofstream fout ("calfflac.out",ios::binary);
    ifstream fin ("calfflac.in",ios::binary);
    filebuf *pbuf;

    char buffer[20000];
    pbuf = fin.rdbuf();
    filesize=pbuf->pubseekoff (0,ios::end,ios::in);
    pbuf->pubseekpos (0,ios::in);
    pbuf->sgetn (buffer,filesize);

    int i;
    int maxlen = 0;
    int start,end;
    for (i = 0; i < filesize;i++)
    {
        int s,e;
        int nextlen = findMaxPalindrome(buffer,i,s,e);
        if (nextlen>maxlen)
        {
            start = s;
            end = e;
            maxlen = nextlen;
        }
    }

    findNextChar(buffer,start,false);
    findNextChar(buffer,end,true);
    fout << calchar(buffer,start,end) << endl;
    for (i = start;i <= end ;i++)
        fout << buffer[i];
    fout << endl;
    return 0;
}
