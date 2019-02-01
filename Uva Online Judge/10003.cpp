// UVa 10003
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
#define INF (ll)(1e6)

int cuts[55] ;
ll dp[1005][55][55] ;

void solve(int) ;
ll mincost(int, int, int) ;
ll get_mincost(int, int, int) ;

int main(){ 

	int l ; cin >> l ;

	while(l){
		solve(l) ;
		cin >> l ;
	}

	return 0 ;
}

void solve(int l){
	
	int n ; cin >> n ;
	
	for(int i = 0 ; i <= l + 5 ; i++){
	    for(int j = 0 ; j < n + 5 ; j++){
	        for(int k = 0 ; k < n + 5 ; k++) dp[i][j][k] = 0 ;
	    }
	}
    
    cuts[0] = 0 ;
	for(int i = 1 ; i <= n ; i++) cin >> cuts[i] ;
	cuts[n + 1] = l ;

	ll ans = mincost(l, 1, n) ;

	cout << "The minimum cutting is " << ans << "." << endl ;

}

ll mincost(int length, int start_indx, int end_indx){
	
	if(start_indx > end_indx) return 0 ;
	else{
		ll min_cost = INF, val = 0 ;

		for(int i = start_indx ; i <= end_indx ; i++){

			val = get_mincost(cuts[i] - cuts[start_indx - 1], start_indx, i - 1) ;
			val += get_mincost(cuts[end_indx + 1] - cuts[i], i + 1, end_indx) ;
			val += length ;

			if(val < min_cost) min_cost = val ;

		}
		
		//cout << min_cost << " " ;

		return min_cost ;
	}
	
}

ll get_mincost(int a, int b, int c){ 
    
    if(b > c) return 0 ;
    
    if(dp[a][b][c] == 0){
        dp[a][b][c] = mincost(a, b, c) ;
    }
    
    return dp[a][b][c] ;
    
} 