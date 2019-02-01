// Uva 10004
// used bfs or dfs(same time : 0.000)
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945

#include<bits/stdc++.h>

using namespace std ;

#define pb push_back

vector < vector<int> > adjList ;
int color[205], n ;

bool bfs3(int one){
	
	queue <int> q ;
	color[one] = 0 ; q.push(one) ;
	while(!q.empty()){
		int node = q.front() ; q.pop() ;
		for(auto i : adjList[node]){
			if(color[i] == 2){ color[i] = !color[node] ; q.push(i) ; }
			else if(color[i] == color[node]) return 0 ;
		}
	}

	return 1 ;

}

// dfs bipartite function
bool dfs3(int node){

	bool isBipartite = 1 ;

	for(auto i : adjList[node]){
	    if(color[i] == 2){
			color[i] = !color[node] ;
			isBipartite = dfs3(i) ;
		} else if(color[i] == color[node]){
			isBipartite = 0 ;
		} else if(color[i] != color[node]){
			// already visited and valid so don't do anything(it forms a cycle)
		}
		if(isBipartite == 0) break ;
	}

	return isBipartite ;

}

bool check(){
    
    for(int i = 0 ; i < n ; i++) color[i] = 2 ;
            
    bool flag = 1 ;
	for(int i = 0 ; flag && i < n ; i++)
		if(color[i] == 2){ color[i] = 0 ; flag = dfs3(i) ; /*cout << " flag:" << flag << " " ;*/ }

	return flag ;
}

int main(){
    
	while(1){

		cin >> n ;
		if(n == 0) break ;

		adjList.resize(n+1) ; adjList.clear() ;

		int l ; cin >> l ;
		while(l--){
			int a, b ; cin >> a >> b ;
			adjList[a].pb(b) ; adjList[b].pb(a) ;
		}

		if(check()) cout << "BICOLORABLE.\n" ;
		else cout << "NOT BICOLORABLE.\n" ;

	}

}