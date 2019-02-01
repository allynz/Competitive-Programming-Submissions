#include<bits/stdc++.h>
 
using namespace std ;
typedef long long ll ;
 
ll n, c, maxv, a[100005] ;
 
// binary search on the range to find ans
ll ans(){
	
	ll left = 0, right = maxv+1 ;
 
	while(left+1 < right){
 
		ll mid = (left + right) >> 1 ;
 
		ll cntr = 1, prev = a[0] ;
		for(ll i = 1 ; i < n ; i++){
			if(a[i]-prev >= mid){
				prev = a[i] ; cntr++ ;
			}
		}
 
		if(cntr >= c) left = mid ;
		else right = mid ;
 
	}
 
	return left ;
 
}
 
void solve(){
	
	cin >> n >> c ;
 
	maxv = 0 ;
	for(ll i = 0 ; i < n ; i++){ cin >> a[i] ; maxv = max(maxv, a[i]) ; }
	sort(a, a+n) ;
 
	cout << ans() << '\n' ;
 
}
 
int main(){
    
    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;
	
	ll t ; cin >> t ;
	while(t--) solve() ;
 
	return 0 ;
} 