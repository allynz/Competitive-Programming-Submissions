// 725 Division
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=666

#include<bits/stdc++.h>

using namespace std ;

bool all_used(int, int) ;

int main(){
    
    int counter = 0 ;

	while(1){
	    
        counter++ ;
        
		int n ; cin >> n ;

		if(n == 0) break ;
		else if(counter > 1) cout << endl ;

		int count = 0 ;

		for(int B = 1234 ; B <= (98765 / n) ; B++){

			int A = B * n ;

			if(all_used(A, B)){
				printf("%0.5d / %0.5d = %d\n", A, B, n) ;
				count++ ;
			}

		}

		if(count == 0) cout << "There are no solutions for " << n << "." << endl ;
        
	}


	return 0 ;
}

bool all_used(int A, int B){

	int count[10] ;
	for(int i = 0 ; i < 10 ; i++) count[i] = 0 ;

	while(A){
		count[A % 10]++ ;
		A /= 10 ;
	}

	while(B){
		count[B % 10]++ ;
		B /= 10 ;
	}

	bool flag = 1 ; 
	for(int i = 1 ; i < 10 ; i++){
		if(count[i] != 1){
			flag = 0 ;
			break ;
		}
	}

	return flag ;

}