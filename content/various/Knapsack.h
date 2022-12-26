/**
 * Author: Markus Mathiasen
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Knapsack_problem
 * Description: Given N items with associated weight w_i and value v_i,
 * find items s.t. the sum of the weights is at most W, while maximizing the total value.
 * Time: O(N*W)
 * Status: Tested on kattis:knapsack
 */
#pragma once

pair<int, vi> knapsack(vi& v, vi& w, int W) {
    vector<vi> dp(sz(v) + 1, vi(W + 1, 0));
    vector<vi> keep(sz(v) + 1, vi(W + 1, 0));
    rep(i, 1, sz(v) + 1) rep(j, 0, W+1) {
        dp[i][j] = dp[i-1][j];
        int val = j >= w[i-1] ? dp[i-1][j-w[i-1]] + v[i-1] : 0;
        if (j >= w[i-1] && dp[i][j] < val)
            dp[i][j] = val, keep[i][j] = 1;
    }
    int V = 0;
    int j = 0;
    rep(i, 0, W+1) if (V < dp[sz(v)][i])
        V = dp[sz(v)][i], j = i;
    vi res;
    for (int i = sz(v); i > 0; i--) {
        if (keep[i][j]) {
            j -= w[i-1];
            res.push_back(i-1);
        }
    }
    reverse(all(res));
    return {V, res};
}
