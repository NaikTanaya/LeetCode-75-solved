class Solution {
public:
    
void dfs(int currnode,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[currnode] = 1;
    for(int i=0;i<adj.size();i++)
    {
        if(adj[currnode][i] && !vis[i])
        dfs(i,adj,vis);
    }
}
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int count=0;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                count++;
            }
        }
    return count;       
    }
};

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
