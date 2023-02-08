#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define V 4 

int path[V];

int dist[V][V] = { {0, 20, 42, 25},
                   {20, 0, 30, 34},
                   {42, 30, 0, 10},
                   {25, 34, 10, 0}
                 };

int VISITED_ALL = (1<<V) -1;

int tsp(int mask,int pos)
{
    if(mask == VISITED_ALL)
    return dist[pos][0];

    int ans = INT_MAX;

    for(int city = 0; city < V; city++)
    {
        if((mask&(1<<city)) == 0)
        {
            int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main()
{
    cout<<"Travelling Salesman Distance is "<<tsp(1, 0);
    return 0;
}