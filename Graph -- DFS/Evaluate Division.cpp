// needs revision
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < n; i++) {
            adj[equations[i][0]][equations[i][1]] = values[i];
            adj[equations[i][1]][equations[i][0]] = 1 / values[i];
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            double ans = 1;
            if (adj[queries[i][0]].size() == 0 ||
                adj[queries[i][1]].size() == 0)
                ans = -1;
            else {
                bool notFound =true;
                unordered_map<string, bool> vis;
                queue<pair<string, double>> q;
                q.push({queries[i][0], 1});
                while (!q.empty()) {
                    pair<string, double> temp = q.front();
                    q.pop();
                    string str = temp.first;
                    double currVal = temp.second;
                    vis[str] = 1;
                    if (str == queries[i][1]){
                        ans = currVal;
                        notFound =0;
                    }
                    for (auto it : adj[str]) {
                        if (!vis[it.first]) {
                            q.push({it.first, currVal*it.second});
                        }
                    }
                }
                if(notFound) ans=-1;
            }
        res.push_back(double(ans));
        }
        return res;
    }
};

// Example 1:

// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
// note: x is undefined => -1.0

// Example 2:

// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]

// Example 3:

// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
