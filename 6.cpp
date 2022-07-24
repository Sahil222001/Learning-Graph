//PRIMS ALGORITHM
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;i++)
    {
         int u,v,w;
         cin>>u>>v>>w;
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }
    cout<<"ADJACENCY LIST OF GRAPH :"<<endl;
for(int i=0;i<n;i++)
{
    cout<<i<<": ";
            for(auto it:adj[i])
            {
                cout<<it.first<<"["<<it.second<<"]"<<" ";
            }   
            cout<<endl;
}   
    
// 5 6
// 0 1 2
// 0 3 6
// 1 3 8
// 1 4 5
// 1 2 3
// 2 4 7
    
vector<int> parent(n,-1);
vector<int> key(n,INT_MAX);
vector<bool> mst(n,false);

key[0]=0;

for(int i=0;i<n-1;i++)
{
    int mini=INT_MAX;
    int minnode;
    for(int j=0;j<n;j++)
    {
         if(mst[j]==false && key[j]<mini)
         {
             mini=key[j];
             minnode=j;
         }
    }

    mst[minnode]=true;
    for(auto it:adj[minnode])
    {
        int node=it.first;
        int weight=it.second;
        if(mst[node]==false && weight<key[node])
        {
            parent[node]=minnode;
            key[node]=weight;
        }
    }
}
cout<<"MST EDGES WILL BE: "<<endl;
for(int i=1;i<n;i++)
{
    cout<<parent[i]<<"-"<<i<<"\n";
}

   int sum=0;
        for(int i=1;i<n;i++)
        {
            sum=sum+key[i];
        }
        cout<<sum;
    return 0;

}