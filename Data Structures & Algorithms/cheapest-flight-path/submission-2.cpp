class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 1. Build a clean adjacency list: u -> list of {v, weight}
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // 2. Distance array initialized to infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // 3. Queue stores pairs of {current_node, current_cost}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

        // 4. BFS up to K + 1 levels (since K stops means at most K + 1 edges)
        while (!q.empty() && stops <= k) {
            int size = q.size();
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();

                for (const auto& [neighbor, weight] : adj[node]) {
                    // Only push to queue if we find a cheaper way to reach the neighbor
                    if (cost + weight < dist[neighbor]) {
                        dist[neighbor] = cost + weight;
                        q.push({neighbor, dist[neighbor]});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
