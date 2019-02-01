// Uva 459
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

#include<bits/stdc++.h>

using namespace std ;

#define pb push_back

vector < vector<int> > adjList ;
vector < int > color ;
queue <int> q ;

void bfs(int source){
    
	q.push(source) ;
	color[source] = 1 ;

	while(!q.empty()){

		int node = q.front() ; q.pop() ;
		for(int i = 0 ; i < adjList[node].size() ; i++){
			int vertex = adjList[node][i] ;
			if(color[vertex] == 0){ q.push(vertex) ; color[vertex] = 1 ; }
		}

	}
	
}

void dfs(int node){

	if(color[node] == 1) return ;
	else{
		color[node] = 1 ;
		for(int i = 0 ; i < adjList[node].size() ; i++){
			int vertex = adjList[node][i] ;
			if(color[vertex] == 0) dfs(vertex) ;
		}
	}
	
}

void solve(){
    
    char c ; cin >> c ; scanf("%*c") ;
    string s ;

	int n = c-'A'+1 ;

	adjList.clear() ; color.clear() ;
	adjList.resize(c-'A'+1) ; color.resize(c-'A'+1) ;
        
        //cout << adjList.size() << " " << color.size() << '\n' ;
        
    int cc = 0 ;
	while(1){

		getline(cin, s) ;
		if(s == "") break ;

		int n1 = s[0] - 'A', n2 = s[1] - 'A' ;
                //cout << n1 << " " << n2 << '\n' ;
		adjList[n1].pb(n2) ; adjList[n2].pb(n1) ;

	}
        
        /*
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < adjList[i].size() ; j++){
                cout << adjList[i][j] << " " ;
            }
            cout << '\n' ;
        }
        */
        
        for(int i = 0 ; i < n ; i++){
            if(color[i] == 0){
		        dfs(i) ; cc++ ; // or bfs(i)
            }
	}

	cout << cc << "\n" ;
	
}

int main(){
	
	int t ; cin >> t ;
	while(t--){ 
	    solve() ;
	    if(t!=0)cout << '\n' ;
	}

	return 0 ;
}