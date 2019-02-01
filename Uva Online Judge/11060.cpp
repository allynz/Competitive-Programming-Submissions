// kahn's algorithm using priority queue
// Uva 11060
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2001

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int n ;
string s ;
map <string, int> m ;
vector < vector <int> > adjList ;
vector <int> indegree, ans ;
priority_queue < int, vector<int>, greater<int> > pq ;
vector <string> alcohol ;

void take_input(){
	
	for(int i = 0 ; i < n ; i++){
		cin >> s ; m[s] = i ;
		alcohol.push_back(s) ;
	}

	int k ; cin >> k ;
	while(k--){
		string a, b ; cin >> a >> b ;
		adjList[m[a]].push_back(m[b]) ;
		indegree[m[b]]++ ;
	}

}

bool modified_kahn(){
	
	for(int i = 0 ; i < n ; i++) if(indegree[i] == 0) pq.push(i) ;

	while(!pq.empty()){

		int node = pq.top() ; pq.pop() ;
		ans.push_back(node) ;
		for(auto i : adjList[node]){
			indegree[i]-- ;
			if(indegree[i] == 0) pq.push(i) ;
		}

	}

	if(ans.size() == n) return 1 ; // required toposort done successfully
	else return 0 ; // cannot do toposort(cycle ma be present)

}

void solve(){
	
	alcohol.clear() ;
	m.clear() ; //pq.clear() ;
	adjList.resize(n+1) ; adjList.clear() ;
	indegree.resize(n+1) ; indegree.clear() ;
	ans.clear() ;
	
	take_input() ;

	bool flag = modified_kahn() ;

	for(int i = 0 ; i < ans.size() ; i++){ cout << alcohol[ans[i]] ; if(i != ans.size()-1) cout << " " ; }
	cout << ".\n" ;

}

int main(){
    
    int i = 1 ;
	while(cin >> n){
	    cout << "Case #" << i++ << ": Dilbert should drink beverages in this order: " ;
		solve() ;
		cout << '\n' ;
	}

	return 0 ;
}