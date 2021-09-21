// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1000000007,inf=(9e17),MAX=2e5+5;
int n,m,i,j;


// This Is now has become the one onf most fav problems in dp
// Simply think there are two tourist at starting points
// And make them reach both of them to end therefore now problem is too simplfied

// Also Here dp optimisation will be needed as the manhaten distande of both tourist
// Will remain same there for only 3 statr will required to represent the dp states

int dp[101][101][101];  // dp[x1][y1][x1]  as we don't need to include y2 bcz y2 is dependent 
// variable of these three y2=x1+x2-x1 , simply observe both these are goind in same flow always
// either  R or D

int h,w;
char s[101][101];

int helper(int x1,int y1,int x2,int y2)
{
    // As the both have same movement so they will reach the ending point at same ponts
    if(x1==h and y1==w and x2==h and y2==w)
    {
        return (s[h][w]=='*');
    }
    // now for the movement there can be four possible movement are available

    if(x1>h or y1>w or x2>h or y2>w)return INT_MIN;

    if(s[x1][y1]=='#' or s[x2][y2]=='#')return INT_MIN;
    
    int &res=dp[x1][y1][x2]; 

    if(res!=-1)return res;

    res=0;

    // Now return for pont if collision of both the tourist here will will 
    // Return the only 1 Special point if it exist;
    int points=0;

    if(s[x1][y1]=='*')points++;
    if(s[x2][y2]=='*')points++;

    if(x1==x2 and s[x2][y2]=='*')points--;

    int rr=helper(x1,y1+1,x2,y2+1);
    int rd=helper(x1,y1+1,x2+1,y2);
    int dd=helper(x1+1,y1,x2+1,y2);
    int dr=helper(x1+1,y1,x2,y2+1);
    res=max({rr,rd,dd,dr})+points;
    return res;
}

void solve()
{
    cin>>w>>h;
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)cin>>s[i][j];
    }
    for(int i=1;i<=100;i++)
    for(int j=1;j<=100;j++)
    for(int k=1;k<=100;k++)
    dp[i][j][k]=-1;
    cout<<helper(1,1,1,1);
}

signed main(){
   
//    Every Champion was a contender that refused to give up :)
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
/* TODO_problems:
   Binary Lifting (Yash H/W)- https://codeforces.com/contest/1516/problem/D
*/