
class Node{
  public:
    Node* *child;   // Containing the child 0 and i is present of not
    Node()
    {
        child=new Node* [2]{NULL};
    }
};

class Trie{
    Node* root;
public:
    Trie()
    {
        root= new Node();

    }
    void insert(int num)
    {
        Node* tmp=root;
        for(int i=31;~i;i--)
        {
            int sbit=(1<<i)&num; if(sbit!=0)sbit=1;

            if(tmp->child[sbit]!=NULL)
            {
                tmp=tmp->child[sbit];
            }
            else
            {
                Node* adr=new Node();
                tmp->child[sbit]=adr;
                tmp=adr;
            }
        }
    }

    int findMX(int num)
    {
        Node* tmp=root; int ans=0;
        for(int i=31;~i;i--)
        {
            int sbit=(1<<i)&num; 
            if(sbit)
            {
                if(tmp->child[0]!=NULL)
                {
                    tmp=tmp->child[0];
                    ans+=(1<<i);
                }
                else tmp=tmp->child[1];   
            }
            else
            {
                if(tmp->child[1]!=NULL)
                {
                    tmp=tmp->child[1];
                    ans+=(1<<i);
                }
                else tmp=tmp->child[0];   
            }
        }
        return ans;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
        int n=v.size();
        // Time To create the trie of 32 bit size;
        int ans=0;
        Trie t; //t.insert(v[0]);
        for(int i=0;i<n;i++)
        {
            t.insert(v[i]);
            ans=max(ans,t.findMX(v[i]));
        }
        return ans;
    }
};
