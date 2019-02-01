/*
Even more challenging would be to find a subset in original sanskar array which would satisfy the condition. would it?

Below solution should not pass.
Time Complexity : O(k^n), max = 8^21 or 2^63 // this was achieved by taking the array global and not passing as state or making all element of array checks in recursive func

But this solution did take me a lot of time to come up with so i will store and learn from it
*/

#include<bits/stdc++.h>

using namespace std ;

int a[maxs], b[maxs], n, k, tsum ;

// i don't think i can use dp here as one state is also dependent on the array state which is changing
bool can_place(int index, int pos){

	if(index >= n) return 1 ; // all elements have been placed with condition satisfied so every sum must be k
	else if(pos >= k) return 0 ;
	
	bool flag1 = (a[pos] + val[index]) <= tsum ;

	if(flag1){
		a[pos] += val[index] ;
		bool next_flag = can_place(index + 1, 0) ;
		if(next_flag) return 1 ;
		else a[pos] -= val[index] ;
	}

	return can_place(index, pos+1) ;

}

void solve(){
	
	int n, k ; cin >> n >> k ;

	tsum = 0 ;
	for(int i = 0 ; i < n ; i++) cin >> b[i], tsum += b[i] ;

	if(tsum % k == 0) tsum /= k ;
	else cout << "no\n", return ;

	memset(a, 0, sizeof(a[0]) * k) ;

	bool flag = can_place(0, 0) ;

	if(flag) cout << "yes\n" ;
	else cout << "no\n" ;

}

int main(){
	
	int t ; cin >> t ;
	while(t--) solve() ;

	return 0 ;
}