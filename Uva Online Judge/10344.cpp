#include<bits/stdc++.h>

using namespace std ;

int f(int a, int b, int i){
	
	switch(i){
		case 0 : return a+b ;
		case 1 : return a-b ;
		case 2 : return a*b ;
	}
	
	return 0 ;

}

int main(){
		
	int a1, b, c, d, e ;
	cin >> a1 >> b >> c >> d >> e ;
	while(a1|b|c|d|e){
	    
	    int a[5] = { a1, b, c, d, e } ;

		bool flag = 0 ;
		for(int i = 0 ; i < 3 && !flag ; i++)
			for(int j = 0 ; j < 3 && !flag ; j++)
				for(int k = 0 ; k < 3 && !flag ; k++)
				    for(int l = 0 ; l < 3 && !flag ; l++){
				        do{
				            int ans = f(f(f(f(a[0], a[1], i), a[2], j), a[3], k), a[4], l) ;
				            if(ans == 23){
				                flag = 1 ; break ;
				            }
				        } while(next_permutation(a, a+5)) ;
				        
				        //cout << ans << " " ;
				    }
					    

		if(flag) cout << "Possible\n" ;
		else cout << "Impossible\n" ;
		
		cin >> a1 >> b >> c >> d >> e ;

	}

	return 0 ;
}