/* Author- Satyam_kumar_Yadav -Master by Feb:2023- づ(｡◕‿‿◕｡)づ */
// https://codeforces.com/problemset/problem/550/C
#include <bits/stdc++.h>
using namespace std;

#define int                     long long
#define all(v)                  v.begin(),v.end()
#define sz(v)                   (int)(v).size()
#define endl                    "\n"

typedef pair<int,int>   pi; typedef vector<int>   vi;

const long long mod= 1e9+7,inf= (1e18),MAX= 2e5+5;

int n,m,i;

/*
Divisibility Rule of 8
If the last three digits of a number are divisible by 8, 
then the number is completely divisible by 8. 
*/

// 100C3- 161700  There for we just have to select andy 3 

bool check(string r)
{   
    int n=stoll(r);
    return (n%8==0);
}

void H_U_S_T_L_E()
{
    string s;   cin>>s;

    // size 1
    for(int i=0;i<sz(s);i++){
        string r="";   r+=s[i];
        if(check(r)){
            cout<<"YES"<<endl;
            cout<<stoll(r); return;
        }
    }

    for(int i=0;i<sz(s);i++){
        string r="";   r+=s[i];
        for(int j=i+1;j<n;j++){
            r+=s[j];
            if(check(r))
            {
                cout<<"YES"<<endl;
                cout<<stoll(r); return;
            }
            r.pop_back();
        }
    }

    // Selecting 3 numbers in string s 
    for(int i=0;i<sz(s);i++){
        
        if(s[i]=='0')continue;

        string r="";    r.push_back(s[i]);

        for(int j=i+1;j<sz(s);j++){
            r.push_back(s[j]);
            for(int k=j+1;k<sz(s);k++)
            {
                r.push_back(s[k]);
                if(check(r))
                {
                    cout<<"YES"<<endl;
                    cout<<stoll(r); return;
                }
                r.pop_back();
            }
            r.pop_back();
        }
    }

    cout<<"NO";

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int loser=1,TT=clock();
    // cin>>loser; 
    while(loser--){
        H_U_S_T_L_E();  cout<<endl;
    }

    // cerr<<"\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";

    return 0;
}
