// Author- satyam_kumar_yadav (Master by Feb 2023) *_*

// https://www.codechef.com/SNCKPE21/problems/DECSUBK (Problem Link)

#include <bits/stdc++.h>
using namespace std;
#define int                     long long
#define nl                      cout<<"\n";
#define deb(x)                  cout<<(#x)<<" = "<<(x)<<"\n";

const long long mod=1e9+7,inf=(1e18),MAX=2e5+5;
int n,m,i,j;

// After watching Priyansh Live Stream Realise it's a binary search on Answer 

bool helper(int place,int k,vector<int> res,int val)
{
    res.insert(res.begin()+place,val);  // This Is the position where we are inserting the val element
    vector<int> ans;    // This Is the vector which will store the length of max non decreasing subsequence
    ans.push_back(res[0]);
    for(int i=1;i<(int)res.size();i++)
    {
        if(res[i]>=ans.back()){
            ans.push_back(res[i]);
        }
        else // Time to search the 1st greatest value than
        {
            auto index=upper_bound(ans.begin(),ans.end(),res[i])-ans.begin();
            ans[index]=res[i];  // Optimise the longest subsequence bu making here small element
        }
    }
    return (ans.size()<=k);
}

void solve()
{
    cin>>n;  vector<int> v(n); int k;   cin>>k;
    for(i=0;i<n;i++)cin>>v[i];          sort(v.begin(),v.end());
    vector<int> ans;
    for(i=0;i<n;i++)
    {
        int start=0,end=i; bool possible=true; int found=-1;
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if(helper(mid,k,ans,v[i]))
            {
                found=mid; 
                start=mid+1;
            }
            else
            end=mid-1;    
        }

        if(found==-1)
        {
            cout<<-1;   return;
        }
        else
        ans.insert(ans.begin()+found,v[i]); // Inserting element in the best possible position    
    }

    for(auto x:ans)cout<<x<<" ";
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);int loser=1;
    cin>>loser; 
    while(loser--){
        solve(); nl 
    }
    return 0;
}
