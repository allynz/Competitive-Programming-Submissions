// UVa 10943
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1884

#include<bits/stdc++.h>

using namespace std ;

#define mv 1000000

long int ways[105][105] ;

void precalc(){ 

	for(int i = 0 ; i < 105 ; i++) ways[0][i] = ways[i][1] = 1 ;
	ways[0][0] = 0 ;

	for(int i = 1 ; i <= 104 ; i++){
		for(int j = 2 ; j <= 104 ; j++){
			ways[i][j] = 0 ;
			for(int k = 0 ; k <= i ; k++){
				ways[i][j] +=  ways[i - k][j - 1] ; ways[i][j] %= mv ;
			}
			//cout << ways[i][j] << " " ;
		}
		//cout << endl ;
	}

}

int main(){
    
    precalc() ;
	
	int n, k ;
	cin >> n >> k ;
	while(n||k){

		cout << ways[n][k] << endl ;

		cin >> n >> k ;
	}

	return 0 ;
} 