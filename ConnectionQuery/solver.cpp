#include <cstdint>
#include <optional>
#include <atcoder/lazysegtree.hpp>
#include <atcoder/dsu.hpp>

using i32 = std::int32_t;
using i64 = std::int64_t;

__attribute__((constructor)) inline void fast_io() { std::ios::sync_with_stdio(false), std::cin.tie(nullptr); }


template<class T>
struct table_impl {  // 一転取得, 区間更新 のためのモノイドと作用素を定義 (厳密にはモノイドをなさない)
    using value_type = T;
    using action_type = std::optional<T>;

    static inline value_type e() { return 0; }
    static inline value_type op(value_type x, value_type y) { return x + y; }

    static inline action_type id() { return {}; }
    static inline value_type map(action_type f, value_type x) { return f.value_or(x); }
    static inline action_type composite(action_type f, action_type g) { return f ?: g; }
};

template<class T>
using table_base = atcoder::lazy_segtree<
    typename table_impl<T>::value_type, table_impl<T>::op, table_impl<T>::e,
    typename table_impl<T>::action_type, table_impl<T>::map, table_impl<T>::composite, table_impl<T>::id
>;

template<class T> struct table : table_base<T> {
    using table_base<T>::lazy_segtree;

    inline void fill(const i32 l, const i32 r, const T v) { this->apply(l, r, v); }
    inline T operator[](const i32 p) { return this->get(p); }
};

i32 unique() {  // 呼び出す度に新しい値を (昇順に) 返す関数．
    static i32 id = 0;
    return id++;
}

constexpr i32 N = 200'000;  // 高々 2*10^5 個の要素が必要．

table<i32> id(N);
atcoder::dsu ds(N);

void solve() {
    id.fill(0, N, -1);  // -1 でいずれの要素にも対応しないことを表す．
    i32 q; std::cin >> q;

    while(q--) {
        i32 t, x, y; std::cin >> t >> x >> y;

        if(id[x] < 0) id.set(x, unique());  // -1 なら新しく要素を割り当てる．
        if(id[y] < 0) id.set(y, unique());  // -1 なら新しく要素を割り当てる．

        if(t == 0) ds.merge(id[x], id[y]);  // 併合
        if(t == 1) id.fill(x, y, -1);  // 分離
        if(t == 2) std::cout << (ds.same(id[x], id[y]) ? "Yes" : "No") << "\n";  // 判定
    }
}

signed main() {
    i32 $; std::cin >> $;
    while($--) solve();
}
