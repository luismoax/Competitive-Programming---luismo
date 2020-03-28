#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n=0;
    bool barr[1000002];
    int IDs [1009], lst[1009];
    int idsCount=0;

    scanf("%d",&n); // read n

    for(int t=0;t< n;t++) //Reading Ids
    {
        int id = 0;
        scanf("%d",&id);
        lst[t]=id;
        // If ids doesn't exit
        if(barr[id]== false)
        {
            IDs[idsCount] = id;
            idsCount++;
            barr[id] = true;
        }
    }


    // foreach id in ids
    int max_cnt = 0;
    for(int k=0;k<idsCount;k++)
    {
        int cnt=0,last_val=-15;

        for(int i=0;i<n;i++)
        {
            if(IDs[k] != lst[i])
            {
                if(lst[i] == last_val)
                cnt++;
                else
                {
                    last_val = lst[i];
                    cnt=1;
                }
                
                if(cnt > max_cnt)
                        max_cnt = cnt;
            }
        }
    }
    printf("%d\n",max_cnt);

    return 0;
}
