// 441 - Lotto
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=382

#include<bits/stdc++.h>

using namespace std ;

int main(){

	bool done = 0 ;

	while(1){

		int k ; cin >> k ;
		if(k == 0) break ;

		if(done) cout << endl ;
		done = 1 ;

		int a[20] ;

		for(int i = 0 ; i < k ; i++){
			cin >> a[i] ;
		}

		for(int i = 0 ; i < (k - 5) ; i++){
			for(int j = i + 1 ; j < (k - 4) ; j++){
				for(int k1 = j + 1 ; k1 < (k - 3) ; k1++){
					for(int l = k1 + 1 ; l < (k - 2) ; l++){
						for(int m = l + 1 ; m < (k - 1) ; m++){
							for(int n = m + 1 ; n < k ; n++){
								printf("%d %d %d %d %d %d\n", a[i], a[j], a[k1], a[l], a[m], a[n]) ;
							}
						}
					}
				}
			}
		}

		
	}


	return 0 ;
}
