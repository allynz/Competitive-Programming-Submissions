// 11498 Division of Nlogonia
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2493
// https://uva.onlinejudge.org/external/114/11498.pdf

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

int main(){
	
	while(1){

		ll t ; cin >> t ;

		if(t){
		    
		    ll n, m ; cin >> n >> m ;

			while(t--){
			    
				ll x, y ; cin >> x >> y ;
				
				x -= n ; y -= m ;

				if(x&&y){

					if(x > 0){

						if(y > 0){
							cout << "NE" << endl ;
						} else{
							cout << "SE" << endl ;
						}

					} else{ // x < 0 as x!=0

						if(y > 0){
							cout << "NO" << endl ;
						} else{
							cout << "SO" << endl ;
						}

					}

				} else cout << "divisa" << endl ;
			}

		} else break ;

	}
	


	return 0 ;
}