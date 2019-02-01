// UVa 11450 - Wedding Dress
// https://uva.onlinejudge.org/external/114/11450.pdf

#include<bits/stdc++.h>

using namespace std ;

int n, req_sum ;
int dp[25][225] ;
vector <int> a[25] ;

int get_msum(int, int) ;

int msum(int i, int sum){
	
	if(sum > req_sum) return 0 ;
	else if(i >= n) return sum ;

	int val = 0, m_val = 0 ;

	for(int j = 0 ; j < a[i].size() ; j++){
		val = get_msum(i + 1, sum + a[i][j]) ;
		if(val > m_val) m_val = val ;
	}
	
	//cout << m_val << " " ;

	return m_val ; 

}

int get_msum(int i, int j){
    
    if(j > req_sum) dp[i][j] = 0 ;
	else if(i >= n) dp[i][j] = j ;
    else if(dp[i][j] == -1) dp[i][j] = msum(i, j) ;
    
    return dp[i][j] ;
    
}

void solve(){
    
    cin >> req_sum >> n ;
    
    for(int i = 0 ; i < n + 5 ; i++){
        for(int j = 0 ; j < req_sum + 5 ; j++){
            dp[i][j] = -1 ;
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        int d ; cin >> d ; a[i].clear() ;
        for(int j = 0 ; j < d ; j++){
            int x ; cin >> x ; a[i].push_back(x) ;
        }
    }
    
    int ans = msum(0, 0) ;
    
    if(ans) cout << ans << endl ;
    else cout << "no solution" << endl ;
}

int main(){
    
    int t ; cin >> t ;
    while(t--) solve() ;
    
    return 0 ;
} 