#include <bits/stdc++.h>
using namespace std;


void bfs( vector<vector<int>> edges) {
    int v;
    cout << "Enter starting Node : ";
    cin >> v;


    // cout << v << " ";
    vector<int> visited(edges.size() , false);
    visited[v] = true;

    queue<int> q ;

    q.push(v);


    while (q.size()) {
        int x = q.front();

        q.pop();
        cout << x << " ";

        for (int y : edges[x]) {
            if (visited[y] == false) {
                visited[y] = true;
                q.push(y);
            }
        }

    }

}

void dfs( vector<vector<int>> edges) {
    int v ;
    cout << "Enter starting Node : ";
    cin >> v;

    vector<int> visited(edges.size() , false);
    visited[v] = true;

    stack<int> q ;

    q.push(v);


    while (q.size()) {
        int x = q.top();

        q.pop();
        cout << x << " ";

        for (int y : edges[x]) {
            if (visited[y] == false) {
                visited[y] = true;
                q.push(y);
            }
        }

    }

}

int main() {

    vector<vector<int>> edges(4 , vector<int> ());

    edges[0].push_back(1);
    edges[0].push_back(2);
    edges[1].push_back(2);
    edges[2].push_back(0);
    edges[2].push_back(3);
    edges[3].push_back(3);

    int ans;
    do
    {
        cout << "1. dsf\n" << "2. bfs\n" << "0. Exit\n" << "Enter your ans : ";
        cin >> ans;




        if (ans == 1) dfs(edges);

        if (ans == 2) bfs(edges);

        cout << "\n\n";

    } while (ans != 0);


    return 0;
}