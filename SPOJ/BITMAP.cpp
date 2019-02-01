// BITMAP
// https://www.spoj.com/problems/BITMAP/

#include<bits/stdc++.h>
 
using namespace std ;
typedef long long ll ;
#define INF ((int)1e9)
 
char a[205][205] ;
bool color[205][205] ;
int dist[205][205] ;
 
void solve(){
 
	int n, m ; cin >> n >> m ;
 
	queue < pair<int, int> > q ;
 
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
 
			cin >> a[i][j] ;
 
			dist[i][j] = INF ;
			color[i][j] = 0 ;
 
			if(a[i][j] == '1'){
				q.push(make_pair(i, j)) ;
				dist[i][j] = 0 ;
				color[i][j] = 1 ;
			}
 
		}
 
	int dr[] = { 0, 0, -1, 1 } ;
	int dc[] = { 1, -1, 0, 0 } ;
 
	while(!q.empty()){
 
		pair <int, int> p = q.front() ;
		q.pop() ;
 
		for(int i = 0 ; i < 4 ; i++){
			int x = p.first + dr[i], y = p.second + dc[i] ;
			if(x < 0 || x >= n || y < 0 || y >= m || color[x][y]) continue ;
			dist[x][y] = dist[p.first][p.second] + 1 ;
			color[x][y] = 1 ;
			q.push(make_pair(x, y)) ;
		}
 
	}
 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++)
			cout << dist[i][j] << " " ;
		cout << "\n" ;
	}
 
}
 
int main(){
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin) ;
	#endif
 
	ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
 
	int t ; cin >> t ;
	while(t--) solve() ;
 
	return 0 ;
}