// Uva 11902

#include<bits/stdc++.h>

using namespace std ;
#define f(i, n) for(int i = 0 ; i < n ; i++)
#define pb push_back

vector <int> adjList[105] ;
bool visited[105] ;
bool m[105][105] ;

void dfs(int a){
	
	if(visited[a]) return ;
	else{
		visited[a] = 1 ;
		f(i, adjList[a].size()) if(!visited[adjList[a][i]]) dfs(adjList[a][i]) ;
	}

}

void solve(int t){
    
    int n ; cin >> n ;
	
	f(i, n) f(j, n){
		bool x ; cin >> x ;
		if(x) adjList[i].pb(j) ;
	}

	vector <int> req ; req.clear() ; // vertices reachable from 0

	dfs(0) ;
	f(i, n) if(visited[i]) req.pb(i) ; // assign only those vertices which are reachable from 0

	f(i, req.size()){

		f(j, req.size()) visited[req[j]] = 0 ; // clear visited array

		visited[req[i]] = 1 ; // visit this node already so cannot visit in dfs
		dfs(0) ;
                
        visited[req[i]] = 0 ;
		// now check which nodes in req were unreachable
		f(j, req.size()) if(!visited[req[j]]) m[req[i]][req[j]] = 1 ;                

	}

        cout << "Case " << t+1 << ":\n" ;
        
        cout << "+" ; f(i, 2*n - 1) cout << "-" ; cout << "+\n" ;

	for(int i = 0 ; i < n ; i++){
                
            cout << "|" ;
                for(int j = 0 ; j < n ; j++){
                    if(m[i][j] == 1) cout << "Y|" ;
                    else cout << "N|" ;
                }
                
		cout << "\n+" ; f(i, 2*n - 1) cout << "-" ; cout << "+\n" ;

	}
        
        // clear adjList, m and visited
        f(i, n){
            visited[i] = 0 ;
            f(j, n){ adjList[i].clear() ; m[i][j] = 0 ; }
        }

}

int main(){

	int t ; cin >> t ;
	f(i, t) solve(i) ;
	
	return 0 ;
}