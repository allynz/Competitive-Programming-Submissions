// UVa 507
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=448

#include<bits/stdc++.h>

using namespace std ;

#define sc(x) int x ; cin >> x ;
#define pb push_back
#define f(i, n) for(int i = 0 ; i < n ; i++)
#define vll vector <int>

void solve(int r) ;

int main(){

	sc(t) 

	f(i, t) solve(i + 1) ;

	return 0 ;
}

void solve(int r){ 
	
	sc(n) vll vec ; vec.clear() ;

	f(i, n - 1){ sc(x) vec.pb(x) ; }

	int currSum = 0, max_val = 0, start_indx = -1, end_indx = 0, max_start_indx = -1, max_range = 0 ;

	f(i, n - 1){

		currSum += vec[i] ;
		if(currSum < 0) start_indx = i ;
		currSum = max(currSum, 0) ; 
		if(currSum > max_val){ max_val = currSum ; end_indx = i ; max_start_indx = start_indx ; max_range = end_indx - max_start_indx ; }
		else if(currSum == max_val){
		    if((i - start_indx) >  max_range){
		        end_indx = i ; max_start_indx = start_indx ; max_range = end_indx - max_start_indx ;
		    }
		}
		    

	}

	if(max_val)	cout << "The nicest part of route " << r << " is between stops " << max_start_indx + 2 << " and " << end_indx + 2 << endl ;
	else cout << "Route " << r << " has no nice parts" << endl ;
	//cout << max_val << endl ;

} 