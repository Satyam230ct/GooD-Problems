// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e17),MAX=405;
int n,m,i,j;

// Really 1st time i'm using adjency matrix 2d form

int mat[MAX][MAX],idx[MAX][MAX],ans[MAX],par[MAX],cnt[MAX][MAX];

// First Going to apply the bellman formd to find the all the shortest distance 

int bfs(int u,int v)
{
    if(u>-1)
    {
      // Here we are blocking the edges that we are going to use why we create 2 bfs for seperate problems
        if(cnt[u][v]==1)
        mat[u][v]=inf;
    }
    // Time to apply standard O(n^2) BFS
    queue<int> qe; qe.push(0);
    vector<int> dis(n,inf); dis[0]=0;
    while (!qe.empty())
    {
        int root=qe.front();    qe.pop();
        
        for(int i=0;i<n;i++)
        {
            // If ther is no mapping bt root to i
            if(mat[root][i]==inf)continue;
            
            // If mapping exist then check for the shortest distance
            if(dis[i]>dis[root]+1)
            {
                dis[i]=dis[root]+1;
                qe.push(i);   
                par[i]=root;
            }
        }
    }
    if(u>-1)mat[u][v]=1;    // Means restoring the blocked path we have done
    return dis[n-1];    // Shortest distance form 0 to n-1 (i.e 1 to n)
}

void solve()
{
    for(i=0;i<MAX;i++)
    for(j=0;j<MAX;j++)mat[i][j]=inf;    // Makingadjancy matrix

    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;    cin>>a>>b; a--; b--;
        idx[a][b]=i;    // Easy for us to store it as answer printing in future
        mat[a][b]=1;    // making distace travel from a to b is 1
        cnt[a][b]++;
    }
    
    // Now time to find answer when all edges are free
    int res=bfs(-1,-1);

    if(res==inf)    // It not possible to reach n from 1
    {
        for(i=0;i<m;i++)cout<<-1<<"\n";
        return;
    }

    vector<int> shortest_path={n-1};
    do
    {
        shortest_path.push_back(par[shortest_path.back()]);
    } while(shortest_path.back()!=0);
    reverse(shortest_path.begin(),shortest_path.end());

    // Now time to fill the answers for the shortest path visited edges
    // memset(ans,-1,sizeof ans);
    vector<int> ans(m,-1);
    for(i=1;i<(int)shortest_path.size();i++)
    {
        int u=shortest_path[i-1],v=shortest_path[i];
        ans[idx[u][v]]=bfs(u,v);
    }

    // Now time to fill the all the other edges which are not in the shortest path of 0 and n-1

    for(i=0;i<m;i++)
    {
        if(ans[i]==-1)ans[i]=res;
        else
        {
            ans[i]=(ans[i]<inf?ans[i]:-1);
        }
    }

    for(i=0;i<m;i++)
    {
        cout<<ans[i];   nl
    }
}

signed main(){
   
//    Every Champion was a contender that refused to give up :)
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
/* TODO_problems:
   Binary Lifting (Yash H/W)- https://codeforces.com/contest/1516/problem/D
*/
