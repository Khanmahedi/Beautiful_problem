#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll       long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 9223372036854775807 , nmax = 2501 , block = 350 , N = 3e6+20 , mod = 998244353;
#ifndef ONLINE_JUDGE
#include "algodebug.h"
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector < ll > ad[N] ;
ll a[N] , dp[N] , res[N] , sum[N] , s = 0  ;
void dfs(ll node, ll par){
  for(auto it: ad[node]){
    if(par != it){
      dfs(it, node) ;
    }
  }
  sum[par]+=(sum[node] + a[node]) ;
  if(par != -1)
  dp[par]+=dp[node]+(sum[node] + a[node]) ;
}

void dfs1(ll node, ll par){
    res[node] = dp[node] ;
  for(auto it: ad[node]){
     if(it == par) continue ;
     dp[node]-=(dp[it]+a[it]+sum[it]) ;
     s+=(sum[node] - sum[it] - a[it]) ;
     s+=a[node] ;
     debug(it, s, dp[node]) ;
     dp[it]+=(s+dp[node]);
     dfs1(it, node) ;
     dp[it]-=(s+dp[node]) ;
     s-=a[node] ;
     s-=(sum[node] - sum[it] - a[it]) ;
     dp[node]+=(dp[it]+a[it]+sum[it]) ;
  }


}



int main(){
  FastIo ;

  ll n , m ;
  cin >> n ;
  for( ll i = 1 ; i <= n  ;  i++){
    ll x ;
    cin >> x ;
    a[i] = x; 
  }
  for( ll i = 0 ; i < n -1 ; i++){
    ll x , y ;
    cin >> x >> y ;
    ad[x].pb(y) ;
    ad[y].pb(x) ;
  }

  dfs(1, -1) ;
  dfs1(1, -1) ;

  ll ans = 0 ;

  for( ll i = 1 ; i <= n ; i++)
   ans = max(ans, res[i]) ;

  cout << ans << endl ;

  }




 
 
