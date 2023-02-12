#include<bits/stdc++.h>
using namespace std;
#define ll      long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll mod =   1e9+7  , N = 1e6+10 , INF = 5e18, block = 400 ;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
ll dp[3000][3000] ;
int main(){

ll n, m , k , x, y;
cin >> n >> m >> k ;
vector < pair < ll , ll >> v ;
vector < ll > ar(n) ;
for( ll i = 0 ; i < n ; i++) cin >> ar[i] ;
map < ll , ll > mp ;
sort(ar.begin(), ar.end()) ;
ar.resize(k) ;
reverse(ar.begin(), ar.end());
ll offer[n+10] = {} ;

for( ll i = 0 ; i < m ; i++){
  cin >>x >> y ;
  if(x <= k) offer[x] = max(offer[x] , y) ;
}

ll pre[n+10] = {} ;
for( ll i = 1 ; i <= k ; i++){
  pre[i] = pre[i - 1] + ar[i - 1] ;
}

ll dp[n+10] ;
dp[0] = 0 ;
for( ll i =1 ; i <= k ; i++) dp[i] = INF ;
for( ll i = 0 ; i < k ; i++){
  dp[i+1] = min(dp[i+1], ar[i]+dp[i]) ;
  for( ll j = 1 ; j <= k ; j++){
    if(offer[j] == 0) continue ;
    if((i + j) > k) break ;
    dp[i+j] = min(dp[i+j], dp[i] + (pre[i + j - offer[j]] - pre[i])) ;
  }
}

cout << dp[k] << endl ;





  
  
}
