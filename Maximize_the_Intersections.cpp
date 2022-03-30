/* Author- Satyam_kumar_Yadav -Master by Feb:2023- づ(｡◕‿‿◕｡)づ */

#include <bits/stdc++.h>
using namespace std;

#define int                     long long
#define all(v)                  v.begin(),v.end()
#define sz(v)                   (int)(v).size()
#define endl                    "\n"

typedef pair<int,int>   pi; typedef vector<int>   vi;

const long long mod= 1e9+7,inf= (1e18),MAX= 2e5+5;

int n,m,i,k;

/* Damm geometry problem sucks */
// Still to hard to understand this intution to increase the max intersection of chord

//-> Also have leared about the intersection of tow line segment

/* 
however you choose 3 chords that connect 3 disjoint pairs of points, 
no point strictly inside the circle belongs to all 3 chords.

Means There DNE any point inside the circle that all three cords passers to it
*/

struct cord{
    int x,y;
};

bool intersection(cord a,cord b){
    if(a.x>b.x)swap(a,b);
    return (b.y>a.y and b.x<a.y);
}

void H_U_S_T_L_E()
{
    // Seen edutorial and the preety hard observation is that we optimal way of
    // drawing the point is opposite ones paring and the problem then just become count the intersection of chords
    cin>>n>>k; 

    // The opposite point to i will be (i+n-k) 
    bool used[2*n]{false};
    
    vector<cord> cords;

    for(int i=0;i<k;i++){
        int x,y;    cin>>x>>y;    x--;    y--;    // 0 base indexing
        if(x>y)swap(x,y); //x<y always
        cords.push_back({x,y});
        used[x]=used[y]=true; // Used points
    }

    vi unused;
    for(int i=0;i<2*n;i++)
    if(!used[i])
    unused.push_back(i);

    for(int i=0;i<sz(unused)/2;i++)
    cords.push_back({unused[i],unused[sz(unused)/2+i]}); // Already in smaller order

    // Time to find the intersection between the cords

    int ans=0;

    for(int i=0;i<sz(cords);i++)
    for(int j=i+1;j<sz(cords);j++)
    if(intersection(cords[i],cords[j]))ans++;

    cout<<ans;
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