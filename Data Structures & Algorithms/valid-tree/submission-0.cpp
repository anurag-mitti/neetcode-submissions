class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int nei : adj[node]) {
        
            if (!vis[nei]) {
                if (dfs(nei, node, adj, vis))
                    return true;
            }
            else if (nei != parent) {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        if (dfs(0, -1, adj, vis))
            return false;

    
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                return false;
        }

        return true;
    }
};
