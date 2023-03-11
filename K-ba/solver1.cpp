#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,n) for (long long i=0;i<(long long)(n);i++)
#define all(v) v.begin(),v.end()
using ll=long long;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll,ll>;
const ll INF=(1ll<<60);
template<class T> void chmin(T &a,T b){
    if(a>b){
        a=b;
    }
}
template<class T> void chmax(T &a,T b){
    if(a<b){
        a=b;
    }
}
int main(){
    ll test;
    cin >> test;
    while(test--){
        ll k,t;
        cin >> k >> t;
        vector<ll> d(k,0),v(k-1);
        rep(i,k-1) cin >> d[i+1];
        rep(i,k-1) d[i+1]+=d[i];
        rep(i,k-1) cin >> v[i];
        vector<ll> sum(k,0);
        rep(i,k-1) sum[i+1]=sum[i]+v[i];
        vector<ll> p(k);
        rep(i,k) p[i]=t*sum[i]-d[i];
        tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> s;
        for(ll i=1;i<k;i++) s.insert({p[i],i});
        ll ans=0;
        rep(i,k-1){
            ans+=s.size()-s.order_of_key({p[i]+t-1,INF});
            s.erase({p[i+1],i+1});
        }
        cout << ans << endl;
    }
}
