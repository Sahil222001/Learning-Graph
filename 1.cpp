//Beginning to use and display a graph
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
int main(){
      int n,m;
      cout<<"Enter no. of vertices & edges :";
      cin>>n>>m;
//O(N^2)
      //**********************************************************   ADJACENCY MATRIX ************************************************************************//
    //  int adj[n+1][n+1];
    //  memset(adj,0,sizeof(adj));
    //   for(int i=0;i<m;i++)
    //   {
    //      int u,v;
    //      cout<<"Enter 2 nodes that will have an edge in ur graph:";
    //      cin>>u>>v;
    //      adj[u][v]=1;
    //      adj[v][u]=1;
    //   }
     
    //  for(int i=1;i<n+1;i++)
    //  {
    //      for(int j=1;j<n+1;j++)
    //      {
    //          cout<<adj[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }


///////////////////////////////////////////////////////
   //O(N+2E)
  //**********************************************************   ADJACENCY LIST ************************************************************************//
//    vector<int> adj[n+1];
//    memset(adj,0,sizeof(adj));
//    for(int i=0;i<m;i++)
//    {
//         int u,v;
//          cout<<"Enter 2 nodes that will have an edge in ur graph:";
//          cin>>u>>v;
//          adj[u].push_back(v);
//          adj[v].push_back(u);
//    }
//    for(int i=1;i<n+1;i++)
//    {
//        cout<<i<<": ";
//        for(auto it=adj[i].begin();it!=adj[i].end();it++)
//        {
//        cout<<*it<<" ";
//        }
//        cout<<endl;
//    }
   
//**********************************************************   ADJACENCY LIST with weights ************************************************************************//   
    vector<pair<int,int>> adj[n+1];
   memset(adj,0,sizeof(adj));
   for(int i=0;i<m;i++)
   {
        int u,v,w;
         cout<<"Enter 2 nodes that will have an edge in ur graph:";
         cin>>u>>v;
         cout<<"Enter weight between them : ";
         cin>>w;
         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
   }
   for(int i=1;i<n+1;i++)
   {
       cout<<i<<": ";
       for(int j=0;j<adj[i].size();j++)
       {
       cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<")";
       }
       cout<<endl;
   }
   
    return 0;
}