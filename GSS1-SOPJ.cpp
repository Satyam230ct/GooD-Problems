// Author- Grandmaster yaduvans_hi *_*
// Problem Link- https://www.spoj.com/problems/GSS1/

#include <bits/stdc++.h>
using namespace std;
#define int                     long long
int n,m,i,j;

int a[50004];

struct nodeTree{
    int pfxSum;
    int sufSum;
    int totalSum;
    int maxSum;
};

nodeTree tree[4*(50004)];

void build(int ss,int se,int index)
{
    if(ss==se)
    {
        tree[index]=(nodeTree){a[ss],a[ss],a[ss],a[ss]};
        return;
    }

    int mid=(ss+se)>>1;
    build(ss,mid,index<<1);
    build(mid+1,se,index<<1|1);
    
    // PrefixSum= max(leftPrefixSum , Total LeftSum + Right_Prefix_Sum)
    int _pfxSum=max( tree[index<<1].pfxSum , tree[index<<1].totalSum+tree[index<<1|1].pfxSum );
    
    // SuffixSum = max(RighSuffixSum , TotalRightSum + left_Suffix_Sum)
    int _sufSum=max( tree[index<<1|1].sufSum , tree[index<<1|1].totalSum+tree[index<<1].sufSum );

    // TotalSum= LeftSum+RightSum
    int _totalSum= tree[index<<1].totalSum+tree[index<<1|1].totalSum;

    // Maximum Sum = max(1,2,3)
    // 1- Left Maximum Sum
    // 2- Right Maximum Sum
    // 3- LeftSuffSum + Right Prefix Sum ~ Where They Are Mearging

    int _1=tree[index<<1].maxSum; int _2=tree[index<<1|1].maxSum;
    int _3=tree[index<<1].sufSum+tree[index<<1|1].pfxSum;
    int maxSum=max({_1,_2,_3});

    tree[index]=(nodeTree){_pfxSum,_sufSum,_totalSum,maxSum};
}

nodeTree query(int l,int r,int ss,int se,int index)
{
    // No Overlap Case
    if(l>r or l>se or r<ss)return (nodeTree){INT_MIN,INT_MIN,INT_MIN,INT_MIN};

    // Complete Overlap
    if(l<=ss and r>=se)return tree[index];

    // Partial Overlap Cases;

    int mid=(ss+se)>>1;

    nodeTree left=query(l,r,ss,mid,index<<1);
    nodeTree right=query(l,r,mid+1,se,index<<1|1);

    // Construction Of left and right---------

     // PrefixSum= max(leftPrefixSum , Total LeftSum + Right_Prefix_Sum)
    int _pfxSum=max( left.pfxSum , left.totalSum+right.pfxSum );
    
    // SuffixSum = max(RighSuffixSum , TotalRightSum + left_Suffix_Sum)
    int _sufSum=max( right.sufSum , right.totalSum+left.sufSum );

    // TotalSum= LeftSum+RightSum
    int _totalSum= left.totalSum+right.totalSum;

    // Maximum Sum = max(1,2,3)
    // 1- Left Maximum Sum
    // 2- Right Maximum Sum
    // 3- LeftSuffSum + Right Prefix Sum ~ Where They Are Mearging

    int _1=left.maxSum; int _2=right.maxSum;
    int _3=left.sufSum+right.pfxSum;
    int maxSum=max({_1,_2,_3});

    return (nodeTree){_pfxSum,_sufSum,_totalSum,maxSum};
}

void solve()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    build(1,n,1);
    int q;  cin>>q;
    while (q--)
    {
        int x,y;    cin>>x>>y;
        nodeTree t=query(x,y,1,n,1);
        cout<<t.maxSum<<endl;
    }
}

signed main(){
    solve();
    return 0;
}
