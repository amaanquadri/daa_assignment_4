#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

#define V 4 

int path[V];
bool visited[V];

int dist[V][V] = { {0, 20, 42, 25},
                   {20, 0, 30, 34},
                   {42, 30, 0, 10},
                   {25, 34, 10, 0}
                 };

int final_path[V];
int final_res = INT_MAX;

void copyToFinal(int currPath[])
{
    for (int i = 0; i < V; i++)
        final_path[i] = currPath[i];
    final_res = 0;
    for (int i = 0; i < V-1; i++)
        final_res += dist[final_path[i]][final_path[i+1]];
    final_res += dist[final_path[V-1]][final_path[0]];
}

void firstNode(int curr_pos, int n, int currPath[], int curr_res)
{
    if (curr_pos == n)
    {
        if (curr_res + dist[currPath[n-1]][currPath[0]] < final_res)
        {
            copyToFinal(currPath);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            int temp = curr_res + dist[currPath[curr_pos-1]][i];
            if (temp < final_res)
            {
                currPath[curr_pos] = i;
                visited[i] = true;

                firstNode(curr_pos+1, n, currPath, temp);

                visited[i] = false;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < V; i++)
        path[i] = -1;

    firstNode(1, V, path, 0);

    cout << "Minimum cost: " << final_res << endl;
    cout << "Path: ";
    for (int i = 0; i < V; i++)
        cout << final_path[i] << " ";

    return 0;
}