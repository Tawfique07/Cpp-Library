/* Tawfique007
 *
 * Toufiqul Islam
 * CSE (18-19) - Rajshahi University
 *
 **/

#ifndef OPT
/* #pragma GCC optimize("O3") */
#pragma GCC optimize("Ofast,unroll-loops")
/* #pragma GCC target("avx,avx2,avx512,fma") */
#endif

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*--- Basic Macros ---*/
#define endl "\n"
#define ll int64_t
#define ull uint64_t
#define ld long double
#define vt vector
#define vti vt<int>
#define vtl vt<ll>
#define ar array
#define pb push_back
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define srt(x) sort(all((x)))
#define rsrt(x) sort(rall((x)))
#define sz(x) static_cast<int>((x).size())

/*--- For Loop Macros ---*/
#define F_OR(i, a, n, s) \
    for (int i = (a); (s) > 0 ? i < (n) : i > (n); i += (s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, n) F_OR(i, 0, n, 1)
#define F_OR3(i, a, n) F_OR(i, a, n, 1)
#define F_OR4(i, a, n, s) F_OR(i, a, n, s)
#define W_FOR(a, b, c, d, e, ...) e
#define F_ORC(...) W_FOR(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto &x : a)

/*--- Read Functions ---*/

int nxt() {
    int x = 0;
    bool negative = false;
    int c = getchar_unlocked();
    while ((c < '0' || c > '9') && c != '-') {
        c = getchar_unlocked();
    }

    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - 48;
        c = getchar_unlocked();
    }

    if (negative) {
        return -x;
    }

    return x;
}

string nxts() {
    string i = "";
    int temp = getchar_unlocked();
    while (temp < '!' || temp > '~') temp = getchar_unlocked();
    while (temp >= '!' && temp <= '~') {
        i += static_cast<char>(temp);
        temp = getchar_unlocked();
    }
    return i;
}

int64_t nxtl() {
    int64_t x = 0;
    bool negative = false;
    int c = getchar_unlocked();
    while ((c < '0' || c > '9') && c != '-') {
        c = getchar_unlocked();
    }

    if (c == '-') {
        negative = true;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - 48;
        c = getchar_unlocked();
    }

    if (negative) {
        return -x;
    }

    return x;
}

void read(string &s) { s = nxts(); }
void read(int &x) { x = nxt(); }
void read(int64_t &x) { x = nxtl(); }

template <class A>
void read(vt<A> &v);
template <class A, size_t S>
void read(ar<A, S> &a);
template <class T>
void read(T &x) {
    cin >> x;
}
void read(double &d) {
    string t;
    read(t);
    d = stod(t);
}

void read(long double &d) {
    string t;
    read(t);
    d = stold(t);
}

template <class H, class... T>
void read(H &h, T &...t) {
    read(h);
    read(t...);
}
template <class A>
void read(vt<A> &x) {
    EACH(a, x) { read(a); }
}
template <class A, size_t S>
void read(array<A, S> &x) {
    EACH(a, x) { read(a); }
}

/*--- To-String Functions ---*/
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char *s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vt<bool> v) {
    string res;
    FOR(sz(v))
    res += static_cast<char>('0' + v[i]);
    return res;
}

template <size_t S>
string to_string(bitset<S> b) {
    string res;
    FOR(S)
    res += static_cast<char>('0' + b[i]);
    return res;
}
template <class T>
string to_string(T v) {
    bool f = 1;
    string res;
    EACH(x, v) {
        if (!f) res += ' ';
        f = 0;
        res += to_string(x);
    }
    return res;
}

/*--- Write Functions ---*/
void write(string x) {
    EACH(c, x) { putchar_unlocked(c); }
}

template <class A, class B>
void write(pair<A, B> x);

template <class A>
void write(A x) {
    write(to_string(x));
}
template <class H, class... T>
void write(const H &h, const T &...t) {
    write(h);
    write(t...);
}

template <class A, class B>
void write(pair<A, B> p) {
    write(p.ff, " ", p.ss);
}

/*--- Print Functions ---*/
void print() { write("\n"); }
template <class H, class... T>
void print(const H &h, const T &...t) {
    write(h);
    if (sizeof...(t)) write(' ');
    print(t...);
}

/*--- Debug Functions ---*/
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }

template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

/*-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-%-=-*/

void solve() {}

int32_t main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc = 1;
    read(tc);
    FOR(tc) {
        /* write("Case #", i+1 , ": "); */
        solve();
    }
    return 0;
}
