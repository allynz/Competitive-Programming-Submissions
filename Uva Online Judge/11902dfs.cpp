// UVa 11902
// Dominator with DFS
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3053

#include<bits/stdc++.h>

using namespace std ;

#define pb push_back

bool visited[105], mark[105], mat[105][105] ;
vector <int> adjList[105], dominates[105] ;

void dfs(int a){
	
	if(visited[a]) return ;
	else{
		visited[a] = 1 ;
		for(int i = 0 ; i < adjList[a].size() ; i++){
			int node = adjList[a][i] ;
			if(!visited[node]) dfs(node) ;
		}
	}

}

void solve(int test_case){
	
	int n ; cin >> n ;
	
	for(int i = 0 ; i < n + 5 ; i++){ adjList[i].clear() ; dominates[i].clear() ; }

	for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++){
		bool x ; cin >> x ; if(x) adjList[i].pb(j) ;
	}

	for(int j = 0 ; j < n + 5 ; j++){ visited[j] = 0 ; mark[j] = 0 ; }
	dfs(0) ;
	for(int i = 0 ; i < n ; i++) if(visited[i]) mark[i] = 1 ;

	for(int i = 0 ; i < n ; i++){
	    if(!mark[i]) continue ;
		// findDominators for ith node
		for(int j = 0 ; j < n + 5 ; j++) visited[j] = 0 ;
		visited[i] = 1 ;
		dfs(0) ;
		for(int j = 0 ; j < n ; j++){ if(!visited[j] && mark[j]) dominates[i].pb(j) ; }
	}
	
	for(int i = 0 ; i < n ; i++) for(int j = 0 ; j < n ; j++) mat[i][j] = 0 ;

	for(int i = 0 ; i < n ; i++){
		if(mark[i]){
		    mat[i][i] = 1 ;
    		for(int j = 0 ; j < dominates[i].size() && !dominates[i].empty() ; j++){
    			mat[i][dominates[i][j]] = 1 ;
    		}
		}
	}

	cout << "Case " << test_case << ":" << endl ;
	for(int i = 0 ; i < n ; i++){
		cout << "+" ; for(int i = 0 ; i < 2*n - 1 ; i++) cout << "-" ; cout << "+" << endl ;
		cout << "|" ;
		for(int j = 0 ; j < n ; j++){
			if(mat[i][j]) cout << "Y" ;
			else cout << "N" ;
			cout << "|" ;
		}
		cout << endl ;
	}
	cout << "+" ; for(int i = 0 ; i < 2*n - 1 ; i++) cout << "-" ; cout << "+" << endl ;

 
} 
 
int main(){
	
	int t ; cin >> t ;
	for(int i = 1 ; i <= t ; i++) solve(i) ;

	return 0 ;
} 