// 11742 - Social Constraints
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2842

#include<bits/stdc++.h>

using namespace std ;

int main(){
	
	int people[10] ;
	for(int i = 0 ; i < 10 ; i++){
			people[i] = i ;
	}
	
	while(1){
	
    	int n, m ; cin >> n >> m ;
    	
    	if((n == 0)&&(m == 0)) break ;
    
    	vector < tuple<int, int, int> > constraints ;
    
    	for(int i = 0 ; i < m ; i++){
    		int x, y, c ; cin >> x >> y >> c ;
    		constraints.push_back(make_tuple(x, y, c)) ;
    	}
    
    	long int counter = 0 ;
    
    	do{
    	    
    	    bool flag = 1 ;
    
    		// check all social constraints
    		for(int i = 0 ; i < m ; i++){
    		    
    		    int p1 = get<0>(constraints[i]) ;
    			int p2 = get<1>(constraints[i]) ;
    			int dist = get<2>(constraints[i]) ;
    			
    			int ind1 = 0 , ind2 = 0 ;
    			
    			for(int j = 0 ; j < n ; j++){
    				
    				if(people[j] == p1) ind1 = j ;
    				if(people[j] == p2) ind2 = j ;
    
    			}
    			
    			if(dist < 0){
    				if(abs(ind1 - ind2) < abs(dist)){
    				    flag = 0 ; break ;
    				}
    			} else{
    				if(abs(ind1 - ind2) > dist){
    				    flag = 0 ; break ;
    				}
    			}
    				
    		}
    		
    		if(flag) counter++ ;
    
    	} while(next_permutation(people, people + n)) ;
    	
    	cout << counter << endl ;
    	
    }

	return 0 ;
}
