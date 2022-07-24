#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//BREADTH FIRST SEARCH

vector<int> bfs(int n,vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(n+1,0);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
          queue<int> q;
          q.push(i);
          vis[i]=1;
          while(!q.empty())
          {
             int node=q.front();
             q.pop();
             bfs.push_back(node);
          

            for(auto it:adj[node]) 
           {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;                   
                } 
           } 
          }
        }
    }
    return bfs;
}



int main()
{
      int n,m;
      cout<<"Enter no. of vertices & edges :";
      cin>>n>>m;
      vector<int> traversed;
      vector<int> adj[n+1];
      memset(adj,0,sizeof(adj));
        for(int i=0;i<m;i++)
        {
                int u,v;
                cout<<"Enter 2 nodes that will have an edge in ur graph:";
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
        }
        for(int i=1;i<n+1;i++)
        {
            cout<<i<<": ";
            for(auto it=adj[i].begin();it!=adj[i].end();it++)
            {
            cout<<*it<<" ";
            }
            cout<<endl;
        }
        traversed=bfs(n,adj);
        cout<<"Traverse list"<<endl;
        for(int i=0;i<traversed.size();i++)
        {
            cout<<traversed[i]<<"-";
        }
    return 0;
}