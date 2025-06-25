//searching the prefix count of particluar given prefix 
#include<bits/stdc++.h>
using namespace std;
bool arr[26];
int k;

struct node{
    int child[26];
    int end_count;  //counts the no. of characters ending at that paricular node 
    int prefix_count;  // kitne elements or strings ka prefix hai wo 

    // note hmlog bina prefix maintain kiye bhi karsakte the kewal end_count se , 
    //hmlog ko dfs karna padta end count ka sum nikalne ke liye to lafda ho jata 
    // anways print karne keliye dfs karna hi hoga 
    node()
    {
        endcount=0;
        prefix=0; 
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
              
                node new_node;
                //change the new node 
                nodes.push_back(new_node);
                nodes[curr_idx].child[s[i]-'a'] =nodes.size()-1;
            }
            //child ko point karne se pehle , jo cur idx hai uspe prefix_count++;
            nodes[curr_idx].prefix_count++;
            curr_idx=nodes[curr_idx].child[s[i]-'a'];
        }

        // endcount maintain ke liye ek string khatam karne ke baad wo loop ke bahar aayega , jaise hi bahar aaye waise hi uske corresponding ind vale node pe end ho rha
        nodes[curr_id].end_count++;
     
    }

  // for printing we will require dfs so see the next code 
    
    void query (string s)
    {
       int curr_idx=0;
        for(int i=0;i<s.length();i++)
        {
            if(nodes[curr_idx].child[s[i]-'a']==-1)
            {
              cout <<0<<endl;  // no string match found 
            }
            curr_idx=nodes[curr_idx].child[s[i]-'a'];
        }
       cout<<"no. of exact matching : "<<nodes[curr_idx].end_count<<" no. of total prefix mathincg : "<<nodes[curr_idx].prefix_count<<endl;
    }
}trie;
void solve()
{
    int n ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        trie.insert(s); 
    }

    int q;
    //q queries given of the prefixes to search for 
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        trie.query(s);

    }

}
int main()
{

    solve();
    return 0;
}