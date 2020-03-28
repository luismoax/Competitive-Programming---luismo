    #include <iostream>
    #include <cstdio>
    #include <vector>
    #include <cstring>
    #include <map>
    #include <algorithm>
    #include <cmath>
    #include <set>
    #include <queue>

    #define pf printf
    #define sf scanf


    #define INF 1000000

    /*
        Author: Luismo
        Problem: 
        Algorithm: DFS process O(N), sort the sections by left field, for ecah 
				   query binary search on the sorted collection to find the page and answer O(1)
				   O(NlogN + QlogN)
					
    */

    using namespace std;

struct _section
{
    int left,right,father;
    int max,min;
    vector<int> sons;
    _section(){}
    _section(int _left,int _right, int _father)
    {
        left = _left;
        right = _right;
        father = _father;

        max = 0;
        min = INF;
    }


};

// vector de secciones
vector<_section> sections;

void DFS(_section &node)
{
    // if is leaf
    if(node.sons.empty())
    {
        node.min = node.right - node.left + 1;
        node.max = node.min;

        return;
    }
    // pages of this section
    int my_pages = node.right - node.left + 1;
    // foreach node of my kids
    for(int i=0;i< node.sons.size();i++)
    {
        int idx = node.sons[i];

        // call the ith node with DFS
        DFS(sections[idx]);

        // updates the min
        if(sections[idx].min + my_pages < node.min)
            node.min = sections[idx].min + my_pages;
        // updates the max
        if(sections[idx].max + my_pages > node.max)
            node.max = sections[idx].max + my_pages;
    }
    return;
}



void print_sections()
{
    for(int i=0;i< sections.size();i++)
        {
           _section sec = sections[i];
           pf("[%d,%d]  min%d max:%d sons:%d\n",sec.left,sec.right,sec.min,sec.max,sec.sons.size());
        }
    pf("\n");
}

int bin_srch(int left,int right,int page)
{
    if(left == right)
        return left;

    int mid = (left+right)/2;
    _section sec = sections[mid];

    // if this section contains this page
    if(page>=sec.left && page<=sec.right)
        return mid;
    // if is on the left side
    if(page<sec.left)
        return bin_srch(left,mid,page);

    return bin_srch(mid+1,right,page);
}

bool comparer(_section sec1,_section sec2)
{
    return sec1.left < sec2.left;
}

int main()
{


    //freopen("d:\\lmo.in","r",stdin);

    int tc;
    sf("%d\n",&tc);

    for(int t=0;t<tc;t++)
    {
        // printing the case
        pf("Case %d:\n",t+1);

        // clear the sections vector
        sections.clear();

        int n,a,b,p,Q;
        sf("%d",&n);

        // reading sections
        for(int i=0;i< n;i++)
        {
            sf("%d%d%d",&a,&b,&p);
            sections.push_back( _section(a,b,p) );
        }

        // setting fathers
        for(int i=0;i< n;i++)
        {
           _section sec = sections[i];
           if(sec.father!=-1)
           {
               sections[sec.father].sons.push_back(i);
           }
        }

        // DFS to calculate the min and max for every node
        DFS(sections[0]);


        // sort sections
        sort(sections.begin(),sections.end(),comparer);

        //print_sections();

        // reading queries
        sf("%d",&Q);

        for(int i=0;i<Q;i++)
        {
            // page
            int page=0;
            sf("%d",&page);

            // index of the section containing this page
            int idx = bin_srch(0,sections.size()-1,page);

            //section containing this page
            _section sec = sections[idx];

            pf("%d %d\n",sec.min - (page-sec.left) , sec.max - (page-sec.left) );

        }

    }

}

