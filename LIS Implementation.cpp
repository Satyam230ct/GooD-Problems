int best_candidate(map<int,int> &mp,int v)
{
    auto it=mp.upper_bound(v);  // Similary we use lower bond if he ask for strictly Increasing.
    if(it==mp.begin())return 0;
    it--;
    return it->second;
}

int cal_lis(vector<int> &a)
{
    int dp[(int)a.size()+1];  dp[0]=1;
    map<int,int> mp;    mp.insert({a[0],1});
    int ans=1;
    for(int i=1;i<n;i++)
    {
        int best=best_candidate(mp,a[i]);
        dp[i]=best+1;
        // Now Time To Delet Unused candidate
        auto it=mp.lower_bound(a[i]);
        while (it!=mp.end() and it->first>=a[i] and it->second<=best)
        {
            auto tmp=it;
            it++;
            mp.erase(tmp);
        }
        mp[a[i]]=dp[i];
        ans=max(ans,dp[i]);
    }
    return ans;
}

void solve()
{
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    int lis=cal_lis(a); 
    cout<<lis;
}

// Codechef Problem - Non-Decreasing subsequence of size at max k
// Snackdown 2021- https://www.codechef.com/viewsolution/54269707
