#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int>& mystore)
{
    mystore.push_back(node);
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,vis,adj,mystore);
        }
    }

}
vector<int> dfs_help(int n,vector<int> adj[])
{
    vector<int> mystore;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,mystore);
        }
    }
    cout<<mystore.size()<<endl;
    return mystore;
    
}
int main()
{
    int n,e;
    cout<<"Enter no. of nodes & edges: ";
    cin>>n>>e;
    vector<int> adj[n+1];
    vector<int> traversed;
    memset(adj,0,sizeof(adj));
    for(int i=0;i<e;i++)
    {
        int u,v;
        cout<<"Enter the 2 nodes which will have an edge between them: ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<i<<": ";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    traversed=dfs_help(n,adj);
    cout<<"After DFS TRAVERSAL THROUGH OUR GRAPH:::"<<endl;
    
    for(int i=0;i<traversed.size();i++)
    {
        cout<<traversed[i];
    }

return 0;
}