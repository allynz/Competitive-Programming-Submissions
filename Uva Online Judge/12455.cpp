// 12455 - Bars
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886

// Brute force - Analyzing all subsets

#include<bits/stdc++.h>

using namespace std ;

void solve(){
	
	int tsum ; cin >> tsum ;
	int p ; cin >> p ;
    
    int bar[25] ;
	for(int i = 0 ; i < p ; i++){
		cin >> bar[i] ;
	}
	
	bool flag = 0 ;

	for(long int i = 0 ; i < (1 << p) ; i++){

		int sum = 0 ;

		for(long int j = 0 ; j < p ; j++){
			if(i & (1 << j)) sum += bar[j] ;
			if(sum > tsum) break ;
		}

		if(sum == tsum){
			flag = 1 ; break ;
		}

	}

	if(flag){
		cout << "YES" << endl ;
	} else cout << "NO" << endl ;

}

int main(){
	
	int t ; cin >> t ;
	while(t--) solve() ;

	return 0 ;
}
