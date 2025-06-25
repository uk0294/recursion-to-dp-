// counting the no. of good no.s 
#include<bits/stdc++.h>
using namespace std;
bool arr[26];
int k;

struct node{
    int child[26];
    bool isValid;
    int count_bad;
    node()
    {
        isValid=true;
        count_bad=0;
        memset(child,-1,sizeof(child));
    }
};

struct tries{
    vector<node>nodes;
    tries()
    {
        node rootnode;
        //fill for root , this may be used in future 
        nodes.push_back(rootnode);
    }

    void insert(string s)
    {
        int curr_idx=0;
        for(int i=0;i<s.length();i++)
        {
            if(nodes[curr_idx].child[s[i]-'a']==-1)
            {
                if(arr[s[i]-'a']==0)
                {
                    nodes[curr_idx].count_bad++;
                }

                if(nodes[curr_idx].count_bad>k)
                 {  nodes[curr_idx].isValid=false;
                    break;
                 }

                node new_node;

                //change the new node 
                nodes.push_back(new_node);
                nodes[curr_idx].child[s[i]-'a'] =nodes.size()-1;
            }
            curr_idx=nodes[curr_idx].child[s[i]-'a'];
        }
     
    }

    int get_count()
    {
         int total=0;
        for (int i=0;i<nodes.size();i++)
        {
              if(nodes[i].isValid)
              {
                total++;
              }
        }

        return total;
    }
}trie;
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<26;i++)
       cin>>arr[i];

    cin>>k;
    for(int i=0;i<s.length();i++)
    {
        trie.insert(s.substr(i));
    }

    cout<<trie.get_count()<<endl;

}
int main()
{

    solve();
    return 0;
}