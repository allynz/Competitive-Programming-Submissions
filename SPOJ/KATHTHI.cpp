// KATHTHI
// https://www.spoj.com/problems/KATHTHI/
// 0-1 BFS
// this took such a long time because of TLE even though solution was correct. give optimized solution and don't do recursion too much, prune it as early as you can.
 
#include<bits/stdc++.h>
 
using namespace std ;
typedef pair <int, int> pii ;
#define fi first
#define se second
#define INF INT_MAX
#define GC getchar
 
char s[1005][1005] ;
int dist[1005][1005] ;
bool color[1005][1005] ;
 
template<class T>inline bool read(T &x) {
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9') {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
 
bool check(pii a, int r, int c){
	if(a.fi >= 0 && a.fi < r){
		if(a.se >= 0 && a.se < c){
			return 1 ;
		}
	}
	return 0 ;
}
 
void modified_bfs(int r, int c){
 
	deque < pair <int, int> > dq ;
	dq.push_back({0, 0}) ;
 
	int color[r][c] ;
	for(int i = 0 ; i < r ; i++)
		for(int j = 0 ; j < c ; j++){
            color[i][j] = 0 ;
            dist[i][j] = INF ;
		}
 
    dist[0][0] = 0 ;
 
	while(!dq.empty()){
 
		pair <int, int> pt = dq.front() ;
		dq.pop_front() ;
		color[pt.fi][pt.se] = 1 ;
 
		pii p[4] = {
			{pt.fi+1, pt.se},
			{pt.fi-1, pt.se},
			{pt.fi, pt.se+1},
			{pt.fi, pt.se-1}
		} ;
 
		for(int i = 0 ; i < 4 ; i++)
			if(check(p[i], r, c)) // in bounds and not visited
				if(s[p[i].fi][p[i].se] == s[pt.fi][pt.se] && dist[p[i].fi][p[i].se] > dist[pt.fi][pt.se]){
					dq.push_front(p[i]) ;
					dist[p[i].fi][p[i].se] = dist[pt.fi][pt.se] ;
				} else if(dist[p[i].fi][p[i].se] > dist[pt.fi][pt.se] + 1){
					dq.push_back(p[i]) ;
					dist[p[i].fi][p[i].se] = dist[pt.fi][pt.se] + 1 ;
				}
 
	}
 
}
 
void solve(){
 
	int r, c ; read(r) ; read(c) ;
	//scanf("%*c") ;
	for(int i = 0 ; i < r ; i++){
        scanf("%s", s[i]) ;
	}
 
	modified_bfs(r, c) ;
	int ans = dist[r-1][c-1] ;
 
	printf("%d\n", ans) ;
 
}
 
int main(){
 
	int t ; read(t) ;
	while(t--) solve() ;
 
	return 0 ;
}
