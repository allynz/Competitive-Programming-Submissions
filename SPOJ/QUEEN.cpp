#include<bits/stdc++.h>

using namespace std ;
using ll = long long ;
using pii = pair <int, int> ;
const int INF = (int)1e7 ; // int will work, no need for ll as bfs stores only valid distances and only adds them, it ignores invalid ones

int n, m ;
string s[1005] ;
bool visited[1005][1005] ;
pii st ;

struct point{
    int x, y ;
    int dist ;
    pii ignore ; // ignore these directions as it cam from there
} ;

int bfs(){

    queue <point> q ;
    while(!q.empty())
        q.pop() ;

    visited[st.first][st.second] = 1 ;
    q.push({st.first, st.second, 0, {-1, -1}}) ;

    // keep same direction together, like left and right, up and down etc.
    int dirx[] = { 0, 0, -1, 1, -1, 1, -1, 1 } ;
    int diry[] = { -1, 1, 0, 0, -1, 1, 1, -1 } ;
    int pairs[] = { 1, 0, 3, 2, 5, 4, 7, 6 } ; // optimization - do not evaluate the direction where it came from

    int ans = INF ;

    // 8000 per node anyways
    // so don't worry about visited condition
    // as some nodes further in a direction may be unvisited but may have visited elements before
    while(!q.empty()){

        point top = q.front() ;
        q.pop() ;

        if(s[top.x][top.y] == 'F'){
            ans = min(ans, top.dist) ;
            break ; // can directly break
        }

        for(int i = 0 ; i < 8 ; ++i){

            if(i == top.ignore.first || i == top.ignore.second)
                continue ;

            bool flag = 1 ;
            int cnt = 1 ;

            while(flag){

                point nb = {
                    top.x + cnt*dirx[i],
                    top.y + cnt*diry[i],
                    top.dist + 1,
                    {
                        i, pairs[i]
                    }
                } ;

                flag = 0 ;

                if(nb.x >= 0 && nb.x < n && nb.y >= 0 && nb.y < m){
                    if(s[nb.x][nb.y] != 'X'){
                        flag = 1 ;
                        if(!visited[nb.x][nb.y]){
                            visited[nb.x][nb.y] = 1 ;
                            q.push(nb) ;
                        } else{
                            // don't put in queue
                            // as it is  already in queue
                            // knowed this from case 2 in sample test cases
                        }
                    }
                }

                ++cnt ;

            }

        }

    }

    return ans ;

}

void solve(){

    cin >> n >> m ;

    for(int i = 0 ; i < n ; ++i)
        cin >> s[i] ;

    for(int i = 0 ; i < n+5 ; ++i)
        for(int j = 0 ; j < m+5 ; ++j)
            visited[i][j] = 0 ;

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(s[i][j] == 'S')
                st = {i, j} ;

    int ans = bfs() ;

    if(ans >= INF){
        cout << "-1\n" ;
    } else{
        cout << ans << "\n" ;
    }

}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    #endif

    ios::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;

    int t ; cin >> t ;
    while(t--) solve() ;

    return 0 ;
}
