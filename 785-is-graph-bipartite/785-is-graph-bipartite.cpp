class Solution {
private:
    bool checkDFS(int src, vector<vector<int>>& graph, vector<int>& color) {
        for (auto it: graph[src]) {
            if (color[it] == -1) {
                color[it] = (color[src] == 0 ? 1 : 0);
                if (!checkDFS(it, graph, color)) return false; 
            } else if (color[it] == color[src]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkBFS(int src, int n, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it: graph[node]) {
                if (color[it] == -1) {
                    color[it] = (color[node] == 0 ? 1 : 0);
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i=0; i<n; i++) {
            if (color[i] == -1) {
                // if (!checkBFS(i, n, graph, color)) return false;
                color[i] = 0;
                if (!checkDFS(i, graph, color)) return false;
            }
        }
        return true;
    }
};