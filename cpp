class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1 || edges.empty()) {
            return {0};
        }
        vector<int> ans;
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        for (auto& [label, children] : graph) {
            if (children.size() == 1) {
                ans.push_back(label);
            }
        }
        while (n > 2) {
            n -= ans.size();
            vector<int> nextLeaves;
            for (auto& leaf : ans) {
                int u = *graph[leaf].begin();
                graph[u].erase(leaf);
                if (graph[u].size() == 1) {
                    nextLeaves.push_back(u);
                }
            }
            ans = nextLeaves;
        }
        return ans;
    }
};
