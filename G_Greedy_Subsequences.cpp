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
ll tin[N+10] , tout[N+10] , Tmax[5*N +10] , Tadd[5*N + 10] , timer = 0;
vector < ll > ad[N] ;
void dfs(ll node , ll par){
  tin[node] = ++timer ;
   for(auto child: ad[node]){
    if(child != par) dfs(child , node) ;
   }
   tout[node] = timer ;
  }
 ll getmax(ll node){
  return Tmax[node] + Tadd[node] ;
 }
 void pushdown(ll node){
  Tadd[node*2]+=Tadd[node] ;
  Tadd[node*2 + 1]+=Tadd[node] ;
  Tadd[node] = 0 ;
 }
 ll add(ll node , ll b , ll e, ll l , ll r,  ll val){
  // debug(b , e );
     if(b == l and e == r){
      Tadd[node]+=val ;
      return 0;
     }
     ll mid = (b + e) / 2 ;
     pushdown(node) ;
     if(l <= mid) add(node*2 , b , mid , l , min(mid , r) , val) ;
     if(r > mid) add(node*2 +1 , mid+1 , e , max(mid+1 , l) , r , val) ;
     return Tmax[node] = max(getmax(node*2) , getmax(2*node+1)) ;
 }

 int main(){
   ll n , k ;
   cin >> n >> k ;
   vector < ll > v(n+1), st ;
   for( ll i = 1 ; i <= n; i++) cin >> v[i] ;

   for( ll i = n  ; i >= 1 ; i--){
      while(!st.empty() and v[st.back()] <= v[i]) 
        st.pop_back() ;
      ll next = st.empty() ? n+1 : st.back() ;
      ad[next].pb(i) ;
      st.push_back(i);
   }
   dfs(n+1 , -1) ;
  

   for( ll i = 1 ; i <= k - 1 ; i++) add(1 , 1 , n+1 , tin[i] , tout[i] , 1) ;
   debug(timer) ;
   for( ll i = 1 ; (i+k-1) <= n ; i++){
     add(1, 1, n+1 , tin[i+k-1] , tout[i+k-1] , 1) ;
     cout << getmax(1) << " " ;
     add(1, 1, n+1 , tin[i] , tout[i] , -1);
   }
   cout << endl ;


}
 
