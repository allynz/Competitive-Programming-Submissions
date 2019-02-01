// 11565 - Simple Equations
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2612

// Optimized code

#include<bits/stdc++.h>

using namespace std ;

typedef long long ll ;

void solve() ;

int main(){
	
	ll t ; cin >> t ;
	while(t--) solve() ;

	return 0 ;
}

void solve(){

	ll A, B, C ; cin >> A >> B >> C ;

	bool flag = 0 ;
	
	for(ll x = -100 ; x <= 100 ; x++){
		for(ll y = -100 ; y <= 100 ; y++){

				ll sqz = C - ((x*x) + (y*y)) ;
				if(sqz < 0) continue ;

				double dz = sqrt(sqz) ;
				ll z1, z2 ;

				if((dz - (ll)dz) != 0){
					continue ;
				} else{
					z1 = (ll)dz ;
					z2 = -z1 ;
				}
						
				bool c11 = ((x + y + z1) == A) ;
				bool c21 = ((x * y * z1) == B) ;

				bool c12 = ((x + y + z2) == A) ;
				bool c22 = ((x * y * z2) == B) ;

				if(c11&&c21){
				    if((x != y)&&(y != z1)&&(x != z1)){
			        
			        } else continue ;
					cout << x << " " << y << " " << z1 << endl ;
					flag = 1 ;
					break ;
				} else if(c12&&c22){
				    if((x != y)&&(y != z2)&&(x != z2)){
			        
			        } else continue ;
					cout << x << " " << y << " " << z2 << endl ;
					flag = 1 ;
					break ;
				}


		} if(flag) break ;
	}

	if(!flag) cout << "No solution." << endl ;

}

