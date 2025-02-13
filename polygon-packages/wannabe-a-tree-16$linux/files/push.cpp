#include "testlib.h"
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename K> using ordered_set = tree<K, null_type, std::less<K>, rb_tree_tag, tree_order_statistics_node_update>;

std::vector<ll> vec;
ordered_set<ll> st;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    ll ubd = opt<ll>("ubd");
    println(n);
	st.insert(1);
	for (int _ = 1; _ < n; _++) {
		int x = rnd.next(st.size());
		auto iter = st.find_by_order(x);
	    ll cur = *iter;
		st.erase(iter);
		if (cur * 4 >= ubd) vec.emplace_back(cur * 2), vec.emplace_back(cur * 2 + 1);
		else st.insert(cur * 2), st.insert(cur * 2 + 1);
	}
	for (auto &x:vec) st.insert(x);
	println(st);
}
