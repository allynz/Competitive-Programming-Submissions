// 11727 Cost Cutting
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
// https://uva.onlinejudge.org/external/117/11727.pdf

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

int main(){
	
	ll t ; cin >> t ;
	for(ll i = 1 ; i <= t ; i++){
	    
	    ll a[3] ; cin >> a[0] >> a[1] >> a[2] ;
	    sort(a, a + 3) ;
	    cout << "Case " << i << ": " << a[1] << endl ;
	    
	}

	return 0 ;
}