// revise again
class Solution {
public:
    void dfs(int node, vector<pair<int,int>>adj[], vector<int>&vis, int &c){
        vis[node]=1;
        for(auto it: adj[node]){
            int v=it.first;
            int dir=it.second;
            if(!vis[v]){
                if(dir==1)c++; //counting no. of forward edges
                dfs(v,adj,vis,c);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back({v,1});  //1 means forward edge
            adj[v].push_back({u,2}); //2 means edge towards you
        }
        
        int c=0;
        vector<int>vis(n,0);
        dfs(0,adj,vis,c);
        return c;
    }
};

// Example 1:

// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

// Example 2:

// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

// Example 3:

// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
