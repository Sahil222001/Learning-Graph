// Shortest Distance from src to destination in an DAG

#include<bits/stdc++.h>
using namespace std;

void findTopoSortDFS(int i, vector<pair<int,int>> adj[], int vis[], stack<int> &st)
{
    vis[i]=1;   // 1. Mark the curr node as 1
    for(auto it:adj[i])     //2. Iterate the adjacency list 
    {
        if(!vis[it.first])     //Check for not visited adjacency element. first
        {
            findTopoSortDFS(it.first,adj,vis,st);   //call topo sort for that unvisited element
        }
    }
    st.push(i);   //after completing adjacent elements push node into stack
}




void findShortPath(int src, int n, vector<pair<int,int>> adj[])
{
    int vis[n]={0};        //1. Take a visited array and mark all eles as 0

    stack<int> st;        //2. Take  a stack

    for(int i=0;i<n;i++)
    {
        if(!vis[i])        //3. Check for non visited elements
        {
            findTopoSortDFS(i,adj,vis,st);    //4. if elements not visited call Topo Sort
        }
    }
// Now the stack is in topological order

//5. Take a distance array size node and initialize it to infinity/10e9

int dist[n];

for(int i=0;i<n;i++)
{
    dist[i]=1e9;
}

//6. Mark the src distance as 0

dist[src]=0;


//7. While stack doesnt become empty , take a node from stack pop it and check if distance of node is not infinity.

//8. If distance is not infinity check for the adjacent nodes of that node 

//9. Update distance by adding the distance of that node + distance till the adjacent node which is iterator & check if it is less


while(!st.empty())
{
    int node=st.top();
    st.pop();


    if(dist[node]!=1e9)
    {
        for(auto it:adj[node])
        {
            if(dist[node]+it.second<dist[node])
            {
                dist[it.first]=dist[node]+it.second;
            }
        }
    }
}


for(int i=0;i<n;i++)
{
    if(dist[i]==1e9)
    {
        cout<<"INF"<<" ";
    }
    else{
        cout<<dist[i]<<" ";
    }
}


}
int main()
{  
    cout<<"Code to find shortest path in DAG"<<" "<<endl;
    int n, e;
    cout<<"Enter no. of Nodes and Edges: ";
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<e;i++)
    {
       int u,v,w;
       cout<<"Enter 2 nodes which will have an edge and associated weight: ";
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
    }

    int src;
    cout<<"Enter the src from which u want to calculate shortest path: ";
    cin>>src;
    findShortPath(src,n,adj);
    

    return 0;
}