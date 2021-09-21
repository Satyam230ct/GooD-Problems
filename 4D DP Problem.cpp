// Author- Grandmaster yaduvans_hi *_*
#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const int mod=1000000007,inf=(9e17),MAX=1e3+2;
int n=0,i=0,j=0,m=0;
string s,t;
// This is multidimensional dp problem

int dp[MAX][MAX][11][2];    // dp[idx s][idx t][remaining_substring][continuity]


int helper(int is,int it,int rem_sub,int cont)
{
    // Base Cases
    if(is==n or it==m)
    {
        // Means If we have no new sub string to generate so no new len we have to form
        return (rem_sub==0)?0:(-inf);
    }
    // This Couled also be happen that our rem become 0 before reaching to 
    // Ending index of there string so we have to handle it also

    if(rem_sub==0)return 0;

    // Now check this state we have store or not
    if(dp[is][it][rem_sub][cont]!=-1)return dp[is][it][rem_sub][cont];

    /*
        p1 p2 p3 p4 p5
        let we are at p3 having length 5
        p3= a b c d e
        let we are at b then we have 2 option here either continue this p3 or break it
    */
    int res=-inf;
    // Checking previous case of continuity

    if(cont==1) // We are comming with conttinuity in previous
    {
        // here we have rem-1 because break the continuity
        // These are case of generating new Pi 
        int skp_s=helper(is+1,it,rem_sub-1,0);
        res=max(res,skp_s);
        int skp_t=helper(is,it+1,rem_sub-1,0);
        res=max(res,skp_t);
        // Now Case if they are equal
        if(s[is]==t[it]){

            // Now here we have to option either break or continue this current pi
            int brk_p=1+helper(is+1,it+1,rem_sub-1,0);  // Adding 1 as we break cont and they are equal also
            int con_p=1+helper(is+1,it+1,rem_sub,1);    // Adding 1 and not breaking our current p
            res=max({res,brk_p,con_p});
        }
    }
    else if(cont==0)
    {
        // Same Cases   but no reduction in rem substring as we are not breaking any continuity
        int skp_s=helper(is+1,it,rem_sub,0);
        res=max(res,skp_s);
        int skp_t=helper(is,it+1,rem_sub,0);
        res=max(res,skp_t);

        if(s[is]==t[it])
        {
            int brk_p=1+helper(is+1,it+1,rem_sub-1,0);  // Adding 1 as we break cont and they are equal also
            int con_p=1+helper(is+1,it+1,rem_sub,1);    // Adding 1 and not breaking our current p
            res=max({res,brk_p,con_p});
        }
    }
    return dp[is][it][rem_sub][cont]=res;
}

void solve()
{
    cin>>n>>m;  int k;  cin>>k; memset(dp,-1,sizeof dp);
    cin>>s>>t;
    // Initial At index 0 want k substring generation and no continuity in previous
    cout<<helper(0,0,k,0); 
}

signed main(){
   
//     It's going to be hard But Hard does not mean Impossible :)
    
    ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
    int loser=1;
    // cin>>loser; 
    while(loser--){
        solve(); nl 
    }

    return 0;
}
