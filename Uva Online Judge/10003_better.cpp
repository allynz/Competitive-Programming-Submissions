// UVa 10003
// Better and much faster solution than previous
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

int cuts[55] ;
ll dp[55][55] ;

void solve(int) ;
ll mincost(int, int) ;
ll get_mincost(int, int) ;

int main(){

	int length ; cin >> length ;
	while(length){
		solve(length) ; cin >> length ;
	}

	return 0 ;
}

void solve(int length){
	
	int n ; cin >> n ;
	for(int i = 1 ; i <= n ; i++) cin >> cuts[i] ;
	cuts[0] = 0 ; cuts[n + 1] = length ;
	
	for(int i = 0 ; i < (n + 5) ; i++) for(int j = 0 ; j < (n + 5) ; j++) dp[i][j] = 0 ;

	ll ans = mincost(0, n + 1) ;

	cout << "The minimum cutting is " << ans << "." << endl ;

}

ll mincost(int i, int j){

	if(i >= j) return 0 ;
	else{

		ll val = 0, min_val = (ll)(1e6) ;
		for(int k = i + 1 ; k < j ; k++){
			val = get_mincost(i, k) + get_mincost(k, j) + (cuts[j] - cuts[i]) ;
			if(val < min_val) min_val = val ;
		}

		return min(val, min_val) ;

	}

}

ll get_mincost(int i, int j){
	
	if(i >= j) return 0 ;
	else{
		if(!dp[i][j]) dp[i][j] = mincost(i, j)  ;
		return dp[i][j] ;
	}

}