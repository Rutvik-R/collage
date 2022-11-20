#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

void add_edges(int a , int b , int val  , vector<vector<pair<int , int>>>	 &edges) {

	edges[a].push_back({b , val});
	edges[b].push_back({a , val});

}

class myComp {
public:
	int operator()(const pair<int, pair<int , int>> &p1 , const pair<int, pair<int , int>> &p2 ) {
		return p1.first > p2.first;
	}
};

int prims(vector<vector<pair<int , int>>> edges) {
	int ans = 0;

	priority_queue < pair<int , pair<int , int>> , vector<pair<int, pair<int , int>>> , myComp > pq ;

	set<int> node ;

	node.insert(0);

	for (auto x : edges[0]) {
		pq.push({x.ss , {x.ff , 0}});
	}

	while (node.size() != edges.size() && pq.size()) {
		auto a = pq.top() ;
		pq.pop();

		if (node.count(a.ss.ff) == 0) {
			cout << a.ff << " -> ( " << a.ss.ss + 1 << " - " << a.ss.ff + 1 << " )" << endl;
			node.insert(a.ss.ff);
			ans += a.ff ;
			for (auto x : edges[a.ss.ff]) pq.push({x.ss , {x.ff , a.ss.ff}});
		}

	}


	cout << "Ans :  ";
	return ans;
}


int Kruskal(vector<vector<pair<int , int>>> edges) {

	int ans = 0;

	vector<pair<int , pair<int , int>>> weight;

	for (int i = 0; i < 7; ++i)
	{
		for (auto x : edges[i])
		{
			if (i < x.ff)	weight.push_back({x.ss , {i , x.ff}});
		}
	}

	sort(weight.begin() , weight.end());

	vector<set<int>> visited ;

	set<int> f1;
	int s1 , s2 ;
	for (auto e : weight) {
		f1.clear();
		f1.insert(e.ss.ff);
		f1.insert(e.ss.ss);
		s1 = -1 ;
		s2 = -1 ;
		for (int i = 0 ; i < visited.size() ; i++) {
			if (visited[i].count(e.ss.ff)) s1 = i ;
			if (visited[i].count(e.ss.ss)) s2 = i ;
		}

		if (s1 == -1 && s2 == -1) {
			cout << e.ff << " -> ( " << e.ss.ss + 1 << " - " << e.ss.ff + 1 << " )" << endl;
			ans += e.ff ;

			visited.push_back(f1);
		}
		else if (s1 == s2) continue;

		else if (s1 == -1) {

			cout << e.ff << " -> ( " << e.ss.ss + 1 << " - " << e.ss.ff + 1 << " )" << endl;
			ans += e.ff;
			visited[s2].insert(e.ss.ff);
		}
		else if (s2 == -1) {
			cout << e.ff << " -> ( " << e.ss.ss + 1 << " - " << e.ss.ff + 1 << " )" << endl;
			ans += e.ff;
			visited[s1].insert(e.ss.ss);
		}
		else {
			cout << e.ff << " -> ( " << e.ss.ss + 1 << " - " << e.ss.ff + 1 << " )" << endl;
			ans += e.ff ;
			if (s1 < s2) {
				visited[s1].insert(visited[s2].begin(), visited[s2].end());
				visited.erase(visited.begin() + s2);
			}
			else {
				visited[s2].insert(visited[s1].begin(), visited[s1].end());
				visited.erase(visited.begin() + s1);
			}
		}

	}
	cout << "Ans :  ";
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



	cout << "Kruskal's Algorithm : \n" << Kruskal(edges) << endl << endl;
	cout << "Prim's Algorithm : \n" << prims(edges) << endl << endl;







	return 0;
}