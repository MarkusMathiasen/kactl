/**
 * Author: Markus Mathiasen
 * License: CC0
 * Source: LIS.h in kactl + blog post: https://codeforces.com/blog/entry/91581
 * Description: Computes the longest common subsequence between two strings.
 * Instead of the normal $O(N^2)$ dp solution, this solution depends on the total
 * number of matchings $K$ between the two strings (which in the worst case is $N^2$).
 * This is useful, if for example characters aren't repeated too many times.
 * Time: $O((N+K)\log N)$
 * Status: Tested on kattis:doubledeck, stress-tested
 */
#pragma once

template<class T> vector<T> lcs(vector<T>& A, vector<T>& B) {
    unordered_map<T, vi> rev; vector<vi> prev(sz(A));
    vector<vi> dp; rep(i, 0, sz(B)) rev[B[i]].push_back(i);
    rep(i, 0, sz(A)) prev[i].resize(sz(rev[A[i]]));
    rep(i, 0, sz(A)) for (int j = sz(rev[A[i]])-1; j >= 0; j--) {
        int y = rev[A[i]][j];
        auto it = lower_bound(all(dp), vi{y, 0, 0});
        if (it == dp.end()) dp.emplace_back(), it = dp.end()-1;
        *it={y,i,j};
        if(it!=dp.begin())prev[i][j]=(*(it-1))[1]*sz(B)+(*(it-1))[2];
    }
    if (dp.empty()) {return {};} int L=sz(dp);
    vector<T> res(L); int c=dp.back()[1]*sz(B)+dp.back()[2];
	while(L--)res[L]=A[c/sz(B)],c=prev[c/sz(B)][c%sz(B)];
	return res;
}