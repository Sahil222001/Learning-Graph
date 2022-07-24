
#include <bits/stdc++.h>
using namespace std;

 
class Solution {
  public:
    
    
    bool cycleBfs(int i,vector<int> adj[],vector<int> &vis)
    {
        queue<pair<int,int>> q;
        
        vis[i]=true;
        q.push({i,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                 if(!vis[it])
                 {
                     vis[it]=true;
                     q.push({it,node});
                 }
                 else if(parent!=it)
                 {
                     return true;
                 }
           }
            
        }
    return false;
        
        
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(cycleBfs(i,adj,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}