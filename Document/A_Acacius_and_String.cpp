/* Author- Satyam_kumar_Yadav -Master by Feb:2023- づ(｡◕‿‿◕｡)づ */
// https://codeforces.com/problemset/problem/1379/A

#include <bits/stdc++.h>
using namespace std;

#define int                     long long
#define all(v)                  v.begin(),v.end()
#define sz(v)                   (int)(v).size()
#define endl                    "\n"

typedef pair<int,int>   pi; typedef vector<int>   vi;

const long long mod= 1e9+7,inf= (1e18),MAX= 2e5+5;

int n,m,i;

// "abacaba" occurs as a substring in a resulting string exactly once

bool check(string &r){
    return (r=="abacaba");
}

void H_U_S_T_L_E()
{
    cin>>n; string s;   cin>>s;
    int ct=0;
    for(int i=0;i<n-6;i++){
        string r=s.substr(i,7);
        if(check(r))ct++;
    }

    if(ct>=2)cout<<"No";
    else if(ct==1){
        cout<<"Yes"<<endl;  
        for(int i=0;i<n;i++)
        if(s[i]!='?')cout<<s[i];
        else cout<<'z';
    }
    else    // ct=0; means now we have to form substring r by relacing the '?
    {   // cout<<"Nikalo";
        
        string tmp="abacaba";

        for(int i=0;i<n-6;i++){
            
            string r=s.substr(i,7);
            bool flag=false;
            for(int p=0;p<7;p++)
            if(r[p]!=tmp[p])
            {
                if(r[p]!='?'){
                    flag=true;  break;
                }
                r[p]=tmp[p];
            }

            if(flag)continue;

            // Otherwise check the construction possibilities as we got the matching of required string
            
            for(int t=i;t<i+7;t++)
            s[t]=tmp[t-i];
            int ct=0;
            for(int st=max(0LL,i-7);st<min(n,i+14);st++){
                string rtmp=s.substr(st,7);
                if(check(rtmp))ct++;
            }

            if(ct==1){  // Gotcha babe
                cout<<"Yes"<<endl;  
                for(int i=0;i<n;i++)
                if(s[i]!='?')cout<<s[i];
                else cout<<'z';
                return;
            }

            for(int t=i;t<i+7;t++) // Restoring s again back to original
            s[t]=r[t-i];
         }

         cout<<"No";

    }

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int loser=1,TT=clock();
    cin>>loser; 
    while(loser--){
        H_U_S_T_L_E();  cout<<endl;
    }

    // cerr<<"\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";

    return 0;
}