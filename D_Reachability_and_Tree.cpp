#include <bits/stdc++.h>
using namespace std;
using ll = long long;
  

void bfs(int start, vector<vector<int>>& adj, vector<int>& visited, vector<vector<int>>& edges,int layer ) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            int current = q.front(); q.pop();
            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    if (layer % 2 == 0) {
                        edges[current].push_back(neighbor);
                    } else {
                        edges[neighbor].push_back(current);
                    }
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        layer++;
    }
      
}
    


void solv() {
    ll n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, 0);
    vector<vector<int>> edges(n + 1,vector<int>());
    vector<int>degree(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    int mid_node=-1;
  for(int i = 1; i <= n; i++) {
        if (degree[i] == 2) {
            mid_node = i;
            break;
           
        }
    }
    if (mid_node == -1) {
        cout << "NO" << endl;
        return;
    }
  int node1=adj[mid_node][0];
  int node2=adj[mid_node][1];
   edges[mid_node].push_back(node2);
  edges[node1].push_back(mid_node);
  visited[mid_node] = 1;
  visited[node1] = 1;
  visited[node2] = 1;
  bfs(node1, adj, visited, edges, 0);
  bfs(node2, adj, visited, edges, 1);
 
  cout<<"YES" << endl;

  for(int i = 1; i <= n; i++) {
       for(int j = 0; j < edges[i].size(); j++) {
            cout<< i << " " << edges[i][j] << endl;
        }
    }
  



 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solv();
    }
}

   // for (int i = 1; i <= n; i++) {
    //     cout << edges[i].size() << " ";
    //     for (int j : edges[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }