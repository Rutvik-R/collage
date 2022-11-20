#include <bits/stdc++.h>
using namespace std;



void add_edges(int a , int b , int val  , vector<vector<pair<int , int>>>	 &edges) {

	edges[a].push_back({b , val});
	edges[b].push_back({a , val});

}


vector<int> Dijkstra(int v , vector<vector<pair<int , int>>> edges) {

	vector<int> ans(edges.size() , -1) ;

	ans[v] = 0;

	vector<int> visited(edges.size() , false);
	visited[v] = true;

	queue<int> q ;

	q.push(v);

	int time = 1;

	while (q.size()) {
		int x = q.front();

		q.pop();


		for (auto y : edges[x]) {

			if (ans[y.first] == -1 ) {
				q.push(y.first);
				ans[y.first] = ans[x] + y.second ;
			}

			else {
				if (ans[y.first] > ans[x] + y.second) {
					ans[y.first] = ans[x] + y.second;
					q.push(y.first);
				}

			}
		}

	}

	return ans;
}


int main() {

	vector<vector<pair<int , int>>> edges(7 , vector<pair<int , int>> ());

	// Defualt input

	add_edges(1 - 1 ,  2 - 1  , 1 , edges);
	add_edges(1 - 1 ,  3 - 1  , 7 , edges);
	add_edges(1 - 1 ,  4 - 1  , 6 , edges);
	add_edges(2 - 1 ,  3 - 1  , 9 , edges);
	add_edges(2 - 1 ,  6 - 1  , 3 , edges);
	add_edges(4 - 1 ,  5 - 1  , 2 , edges);
	add_edges(5 - 1 ,  7 - 1  , 5 , edges);
	add_edges(6 - 1 ,  7 - 1  , 3 , edges);
	add_edges(3 - 1 ,  7 - 1  , 1 , edges);


	// User define input
	// if(ans == )
	// int n ;
	// cin >> n;

	// edges.resize(n);

	vector<vector<int>> path(edges.size() , vector<int> ());

	for (int i = 0; i < edges.size(); ++i)
	{
		path[i] = Dijkstra(i , edges);
	}

	int fix_space = 5 ;

	for (int i = 0; i < fix_space + 5; ++i) cout << " ";

	for (int i = 0; i < 7; ++i)
	{
		cout << i + 1 << "     ";
	}
	cout << "\n\n\n\n";
	int i = 1 ;

	for (auto x : path)
	{
		cout << i << "         ";
		for (auto y : x) {
			cout << y ;
			if (y == 0)
				for (int i = 0; i < fix_space; ++i) cout << " ";
			if (y < 0)
				for (int i = 0; i < fix_space - (int)log10(abs(y)) - 1; ++i) cout << " ";
			else
				for (int i = 0; i < fix_space - (int)log10(y); ++i) cout << " ";
		}
		cout << "\n\n";
		i++;
	}


	return 0;
}