#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m  >> q;
    map <pair<int, int>, int> tgian;
    for(int i = 0; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tgian.insert({make_pair(a,b), c});
    }
    int timeline = 0;
    for(int i = 0; i < q; i++)
    {
        int start, end;
        cin >> start >> end;
        if(start > end)
        {
            int tmp = start;
            start = end;
            end = tmp;
        }
        int min_path = 0;
        for(int j = start; j <= end; j++)
        {
            map <pair<int, int>, int> ::iterator path_it = tgian.find(make_pair(start,end));
            if(min_path == 0 && path_it != tgian.end())
            {
                min_path = (*path_it).second;
            }
            else if(min_path < (*path_it).second)
            {
                min_path = (*path_it).second;
            }
            timeline+= min_path;

        }
        
        min_path = 0;

    }
    
}