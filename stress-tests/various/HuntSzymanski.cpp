#include "../utilities/template.h"

#include "../../content/various/HuntSzymanski.h"

template<class T> ll normal_lcs(vector<T>& A, vector<T>& B) {
    vector<vi> dp(sz(A)+1, vi(sz(B)+1, 0));
    rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1)
        dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[sz(A)][sz(B)];
}

template<class T> bool is_subsequence(vector<T>& A, vector<T>& B) { // determines if B is a subsequence of A?
    if (sz(A) < sz(B)) return false;
    ll a=0;
    rep(b, 0, sz(B)) {
        if (a >= sz(A)) return false;
        while (B[b] != A[a++])
            if (a >= sz(A))
                return false;
    }
    return true;
}

template<class T> string to_string(vector<T> A) {
    if (sz(A) == 0) return "[]";
    string res = "[";
    for (T x : A) res += to_string(x) + ", ";
    res.pop_back(); res.pop_back();
    return res + "]";
}

int main() {
    ll its = 1e5;
    rep(it,0,its) {
        ll n = rand() % 7, m = rand() % 7;
        if (it*2 >= its) n += 7, m += 7;
        vi A(n), B(m);
        for(auto &x: A) x = rand() % 4;
        for(auto &x: B) x = rand() % 4;
        vi res = lcs(A, B);
        ll len = normal_lcs(A, B);
        if (sz(res) != len) {
            cout << "Exists common subsequence of size " << len << " but found only " << sz(res) << endl;
            abort();
        }
        if (!is_subsequence(A, res) || !is_subsequence(B, res)) {
            cout << to_string(res) << " is not a common subsequence of " << to_string(A) << " and " << to_string(B) << endl;
            abort();
		}
    }
	cout << "Tests passed!" << endl;
}
