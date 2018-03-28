#include <iostream>
#include <queue>
#include <set>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;

#define EDGE_WEIGHT 6

class PairCompare {
   public:
    bool operator()(pair<int, int> lhs, pair<int, int> rhs) { return lhs.second >= rhs.second; }
};

class Graph {
   public:
    Graph(int n) {
        for (int i = 0; i < n; ++i) {
            std::vector<pair<int, int>> temp;
            edges.push_back(temp);
        }
    }

    void add_edge(int u, int v) {
        edges[u].push_back(make_pair(v, EDGE_WEIGHT));
        edges[v].push_back(make_pair(u, EDGE_WEIGHT));
    }

    std::vector<int> shortest_reach(int start) {
        // Prep data structures
        std::set<int> visited;
        std::vector<int> distances;
        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, PairCompare> dijkstras;
        // initialize distances to -1
        for (int i = 0; i < edges.size(); ++i){
            distances.push_back(-1);
        }
        distances[start] = 0;
        dijkstras.push(make_pair(start, 0));

        // Search if there is a path, using dijkstras algorithm
        while (!dijkstras.empty()) {
            auto node = dijkstras.top();
            dijkstras.pop();
            // If node has already been visited just continue
            if (visited.find(node.first) != visited.end()) {
                continue;
            }
            // Add node to visited and set it's distance
            visited.insert(node.first);
            distances[node.first] = node.second;
            // Add all of it's other nodes to the queue
            for (auto pair : edges[node.first]) {
                dijkstras.push(make_pair(pair.first, node.second + pair.second));
            }
        }
        return distances;
    }

   private:
    // first entry is each node
    // second entry is list of nodes it has edge to and what edge distance is
    std::vector<std::vector<pair<int, int>>> edges;
};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        std::vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
