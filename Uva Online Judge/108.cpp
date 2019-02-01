// UVa 108
// Max 2D range sum in O(n^4) using dp
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44


#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;
#define f(i, n) for(int i = 1 ; i <= n ; i++)

int a[105][105] ;

void solve() ;
ll findMax(int, int, int, int) ;

int main(){
	
	int t_ ; t_ = 1 ;
	while(t_--) solve() ;

	return 0 ;
}

void solve(){ 
	
	int n ; cin >> n ;

	f(i, n) f(j, n) cin >> a[i][j] ;

	ll val = 0, max_val = -127 ;

	f(i, n) f(j, n){
		val = findMax(i, j, n, n) ;
		if(val > max_val) max_val = val ;
	}

	cout << max_val << endl ;
}

ll findMax(int r1, int c1, int r2, int c2){
	
	ll dp[r2 + 5][r2 + 5], col_dp[r2 + 5][r2 + 5] ;

	// pad first row and column with 0 so that dp equation is satisfied
	// store elements with index 1(useful when dp is used on a matrix)
	memset(dp, 0, sizeof dp) ; memset(col_dp, 0, sizeof col_dp) ; // all cells set to 0 anyway
	
	for(int i = r1 ; i <= r2 ; i++){
		for(int j = c1 ; j <= c2 ; j++){
			col_dp[i][j] = col_dp[i][j - 1] + a[i][j] ; // column wise dp table
		}
	}

	ll max_val = -127 ;
	for(int i = r1 ; i <= r2 ; i++){
		for(int j = c1 ; j <= c2 ; j++){
			dp[i][j] = dp[i - 1][j] + col_dp[i][j - 1] + a[i][j] ;
			if(dp[i][j] > max_val) max_val = dp[i][j] ;
		}
	}

	return max_val ;

}