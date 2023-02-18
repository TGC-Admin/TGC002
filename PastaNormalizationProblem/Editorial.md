# 概要
全探索をベースに，効率的に答えを求める工夫をしてみましょう．

問題原案：uni_kakurenbo

# 解説
分割の方法は，正確に $2^{N-1}$ 通りありますから，これらを全て試すことはできません．  
「明らかに不可能な分割方法」とはどのようなものでしょうか？

視点を変えて，$1$ 本目の中パスタを構成する小パスタを固定することを考えてみます．  
左からみて $1$ 以上 $D_1$ 以下の位置にある小パスタを用いて $1$ 本目の中パスタを構成するとします．  
すると，その中パスタの長さ $H_1 = \displaystyle \sum_{1 \leq i \leq D_1} L_i$ は一意に定まります．  

中パスタの長さは全て等しくなくてはなりませんから，$1$ 本目の長さが決まれば，全てのその長さになるように他の中パスタを前から順番に構成していくことを試せます．  
この操作で全ての小パスタを中パスタにすることができれば，そのときに限り可能です．

これは，[ABC265-D](https://atcoder.jp/contests/abc265/tasks/abc265_d) のように累積和と二分探索を用いることで $O(N \log N)$ 時間で可能です．$(A > 0)$

なお，$H_1$ が $\sum L$ の約数でなければ明らかに分割は不可能ですから，その場合を無視することで，より計算量を削減できます．


# 実装例
```cpp:C++
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve(int n, vector<ll>& l) {
    vector<ll> acc_l(n+1, 0);
    inclusive_scan(l.begin(), l.end(), next(acc_l.begin()));

    ll ans = 0;
    while(n--) {
        ll div_size = acc_l[i+1];

        if(*acc_l.rbegin() % div_size != 0) continue;

        auto div_begin = next(acc_l.begin(), i+1);
        bool can_div = false;

        while(true) {
            ll nxt = *div_begin + div_size;

            auto itr = lower_bound(div_begin, acc_l.end(), nxt);
            if(*itr != nxt or itr == acc_l.end()) break;

            div_begin = itr;

            if(itr == prev(acc_l.end())) {
                can_div = true;
                break;
            }
        }

        if(can_div) ans = max(ans, *acc_l.rbegin() / div_size);
    }

    return ans;
}

signed main() {
    int $; cin >> $;
    while($--) {
        int n; cin >> n;
        vector<ll> a(n); for(auto& v : a) cin >> v;
        cout << solve(n, a) << "\n";
    }
}
```
