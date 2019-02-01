// Finally understood this confusing problem
// Why do people wanna confuse without giving proper question statement
// This should not be a competitive programming question(question is good but should be straightforward)
// The brackets represent '^'(raised to) operation and everything is written in a power of 2
// 2 = 2^1 = 2
// 3 = 2^1 + 2^0 = 2 + 2(0)
// 4 = 2^2 = 2(2)
// 5 = 2^2 + 2^0 = 2(2) + 2(0)
// 100 = 2^6 + 2^5 + 2^2 = 2^(2^2 + 2) + 2^(2^2 + 2^0) + 2^2 =
// 100 = 2(2(2) + 2(0)) + 2(2(2) + 2(0)) + 2(2)
// Why is there source limit? can't even submit my correct solution!

#include<bits/stdc++.h>

using namespace std ;
typedef long long ll ;

// recursive function for finding answer for integer x
// can be stored with vector <string> dp
string func(int x){

	if(x == 2) return "2" ;
	else if(x == 1) return "2(0)" ;
	else if(x == 0) return "0" ;
	
	vector <int> vec ; vec.clear() ;
	int cnt = 0 ;
	while(x){
		if(x&1) vec.push_back(cnt) ;
		x/=2 ;
		cnt++ ; 
	}

	reverse(vec.begin(), vec.end()) ;
	string ans = "" ;
	for(int i = 0 ; i < vec.size() ; i++){
	    
	    if(vec[i] == 1) ans += "2" ;
		else ans += "2(" + func(vec[i]) + ")" ;
		
		if(i < vec.size()-1) ans += "+" ;
		
	}
	
	return ans ;

}

int main(){
	
	int a[] = {137, 1315, 73, 136, 255, 1384, 16385} ;
	for(int i = 0 ; i < 7 ; i++){
		cout << a[i] << "=" << func(a[i]) << '\n' ;
	}
	
	return 0 ;
}

/*string ans = "137=2(2(2)+2+2(0))+2(2+2(0))+2(0)\n\
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)\n\
73=2(2(2)+2)+2(2+2(0))+2(0)\n\
136=2(2(2)+2+2(0))+2(2+2(0))\n\
255=2(2(2)+2+2(0))+2(2(2)+2)+2(2(2)+2(0))+2(2(2))+2(2+2(0))+2(2)+2+2(0)\n\
1384=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2)+2(2(2)+2(0))+2(2+2(0))\n\
16385=2(2(2+2(0))+2(2)+2)+2(0)" ;
    //cout << ans ;*/