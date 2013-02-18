/*
ID: dccrazy2
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX(x,y) ((x) > (y) ? (x) : (y))

using namespace std;

    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");

struct Rect
{
    int width;
    int hight;
    int area;
    Rect()
    {
        width = 0;
        hight = 0;
        area = 0;
    }
    void resize()
    {
        if (width > hight)
        {
            int tp = hight;
            hight = width;
            width = tp;
        }
        calarea();
    }

    void calarea()
    {
        area = width*hight;
    }

    void swap(Rect &a)
    {
        Rect tp;
        tp = a;
        a = *this;
        *this = tp;
    }
};

Rect r[4];

vector<Rect> anss;

Rect layout1(Rect rect[4])
{
    Rect ans;
    ans.width = rect[0].width + rect[1].width + rect[2].width + rect[3].width;
    ans.hight = MAX(MAX(MAX(rect[0].hight,
                            rect[1].hight),
                        rect[2].hight),
                    rect[3].hight);
    ans.resize();
    return ans;
}

Rect layout2(Rect rect[4])
{
    Rect ans;
    ans.width = MAX(rect[3].hight,
                    rect[0].width + rect[1].width + rect[2].width);
    ans.hight = rect[3].width + MAX(
                                     MAX(rect[0].hight,
                                         rect[1].hight),
                                     rect[2].hight);
    ans.resize();
    return ans;
}

Rect layout3(Rect rect[4])
{
    Rect ans;
    ans.width = MAX(rect[0].width + rect[1].width + rect[2].width,
                    rect[3].hight + rect[2].width);
    ans.hight = MAX(rect[2].hight,
                     rect[3].width + MAX(rect[0].hight,
                                         rect[1].hight));
    ans.resize();
    return ans;
}

Rect layout4(Rect rect[4])
{
    Rect ans;
    ans.width = rect[0].width + rect[3].width + MAX(rect[1].width,
                                                    rect[2].width);
    ans.hight = MAX(MAX(rect[0].hight,
                        rect[3].hight),
                    rect[1].hight+rect[2].hight);
    ans.resize();
    return ans;
}

Rect layout5(Rect rect[4])
{
    Rect ans;
    // equal to layout 4!
    // ignore it
    return ans;
}

Rect layout6(Rect rect[4])
{
    Rect ans;

    /*
    这段是我抄的。。。
    我实在不会分析。。。
    */
    ans.width = rect[0].width+rect[1].width;
	ans.hight = max(rect[0].hight+rect[2].hight, rect[1].hight+rect[3].hight);
	if (rect[0].hight < rect[1].hight)
		ans.width = max(ans.width, rect[2].width+rect[1].width);
	if (rect[0].hight+rect[2].hight > rect[1].hight)
		ans.width = max(ans.width, rect[2].width+rect[3].width);
	if (rect[1].hight < rect[0].hight)
		ans.width = max(ans.width, rect[0].width+rect[3].width);
	ans.width = max(ans.width, rect[2].width);
	ans.width = max(ans.width, rect[3].width);

    /*
    if(2高>=4高)and((1宽>2宽)or(3宽<4宽))
        then整体图形的宽:=max(1宽+3宽,2宽+4宽)
    else整体图形的宽:=max(1宽,2宽)+max(3宽+4宽)

    整体图形的高:=max(1高+2高,3高+4高)

    if (rect[1].hight>=rect[3].hight && (rect[0].width>rect[1].width || rect[2].width<rect[3].width))
        ans.width = MAX(rect[0].width+rect[2].width,
                        rect[1].width+rect[3].width);
    else
        ans.width = MAX(rect[0].width+rect[1].width,
                        rect[2].width+rect[3].width);
    ans.hight = MAX(rect[0].hight+rect[1].hight,
                    rect[2].hight+rect[3].hight);
    */
    ans.resize();
    return ans;
}

typedef Rect (*Layout)(Rect [4]);

Layout layout[] = {layout1,layout2,layout3,layout4,layout6};

int cmp(const Rect &a, const Rect &b ){
    if (a.area < b.area)
        return 1;
    else if (a.area == b.area)
    {
        if (a.width < b.width)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

void combine(Rect rect[4],int begin,int end)
{
    if (begin == end)
    {
        // call the layout
        int i;
        for (i = 0;i < 5;i++)
        {
            Rect o = layout[i](rect);
            fout << "layout" << i+1 << " area:" << o.area << endl;
            anss.push_back(layout[i](rect));
        }


        /*
        int i;
        for (i = 0;i < 4;i++)
            fout << rect[i].width << " " << rect[i].hight << "\t";
        fout << endl;
        */
    }
    else
    {
        int i;
        for (i = begin;i <= end;i++)
        {
            rect[i].swap(rect[begin]);
            combine(rect,begin+1,end);
            rect[i].swap(rect[begin]);
        }
    }
}

int main()
{
    int i;
    for (i = 0;i < 4;i++)
    {
        fin >> r[i].width >> r[i].hight;
        r[i].resize();
    }

    combine(r,0,3);

    sort(anss.begin(),anss.end(),cmp);

    vector<Rect>::iterator iter = anss.begin();
    int minarea = iter->area;
    fout << minarea << endl;
    while (iter->area==minarea && iter < anss.end())
    {
        fout << iter->width << " " << iter->hight << endl;
        iter++;
    }
    return 0;
}
