//# Kruskals

#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
    node(int first,int second, int weight)
    {
        u=first;
        v=second;
        w=weight;
    }
};

bool comp(node a, node b)  //A comparator which will help to sort according to weight
{
    return a.w<b.w;
}


int findPar(int node,vector<int> &parent)
{
    if(node==parent[node])
    {
        return node;
    }
    return parent[node]=findPar(parent[node],parent);
}

void do_union(int n1,int n2,vector<int> &parent,vector<int> &rank)
{
    int u=findPar(n1,parent);
    int v=findPar(n2,parent);
    if(rank[u]>rank[v])
    {
        parent[v]=u;
    }
    else if(rank[v]>rank[u])
    {
        parent[u]=v;
    }
    else{
        parent[v]=u;
    }
}




int main()
{
  int n,e;
  cin>>n>>e;
  vector<node> edges;
  for(int i=0;i<e;i++)
  {
      int u,v,w;
      cin>>u>>v>>w;
      edges.push_back(node(u,v,w));
  }  
  sort(edges.begin(),edges.end(),comp);//soerting the vector using comparator
  vector<int> parent(n);
  vector<int> rank(n,0);
  for(int i=0;i<n;i++)
  {
      parent[i]=i;  ///making every node their own parents
  }  
   vector<pair<int,int>> MST; 
   int cost=0;

   //Iterate over sorted edges and check if they belong to same component or not 
   for(auto it:edges)
   {
       if(findPar(it.u,parent)!=findPar(it.v,parent))   // Not belongs to same component
       {
           cost+=it.w;
           MST.push_back({it.u,it.v});
           do_union(it.u,it.v,parent,rank);//make them single component
       }
      
   }
    
     cout<<cost<<endl;
       for(auto it:MST)
       {
           cout<<it.first<<" "<<it.second<<endl;
       }
    
    return 0;
}