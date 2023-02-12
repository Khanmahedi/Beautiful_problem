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
ll n , q  , p1[N] , p2[N] , l[N] , r[N];
vector < pair < ll , ll > > v ;

ll solve(ll indx){
  for( ll i = 0 ; i <= n ; i++) p1[i] = p2[i] = 0 ;
  for( ll i = 0 ; i < q ; i++){
    if(i == indx) continue ;
    p1[l[i]]++ ;
    p1[r[i]+1]-- ;
  }
  for( ll i = 1 ; i <= n ; i++) p1[i]+=p1[i - 1] ;
  for( ll i = 1 ; i <= n ; i++) p2[i] = p2[i - 1] + (p1[i] == 1) ;
  ll ans = LONG_MAX ;
  for( ll i = 0 ; i < q ; i++){
    if(i == indx) continue ;
    ans = min(ans, (p2[r[i]] - p2[l[i]-1])) ;
  }

  ll tot = 0 ;
  for( ll i = 1 ; i <= n ; i++) tot+=(p1[i] > 0) ;
  return tot - ans ;
}

int main(){
   FastIo ;

   cin >> n >> q ;
   for( ll i = 0 ;  i < q ; i++){
    ll x,  y ;
    cin >> l[i] >> r[i] ;
   }
  ll ans = 0 ;
   for( ll i = 0 ; i < q ; i++){
      ans = max(ans, solve(i)) ;
   }
   cout << ans << endl ;
   

}
