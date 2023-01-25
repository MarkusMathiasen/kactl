/**
 * Author: Markus Mathiasen
 * License: CC0
 * Source: Competetive Programming 4 (book 1)
 * Description: Give a distance matrix, computes the shortest Hamiltonian cycle,
 * finding the optimal solution to TSP. One example of such tour is saved in variable tour.
 * Time: O(2^N N^2)
 * Status: Tested on kattis:beepers
 */
#pragma once

const int MAX_DIST = 1e9;
vector<vi> memo, nxt;
vi tour;
int dp(int v, int mask, vector<vi>& dist) {
    if (mask == 0) return dist[v][0];
    int& res = memo[v][mask];
    if (res != MAX_DIST) return res;
    int m = mask;
    while (m) {
        int u_pow = m&(-m);
        int u = __builtin_ctz(u_pow)+1;
        int val = dist[v][u] + dp(u, mask-u_pow, dist);
        if (val < res) {
            res = val;
            nxt[v][mask] = u;
        }
        m -= u_pow;
    }
    return res;
}
int tsp(vector<vi>& dist) {
    int n = sz(dist);
    memo.assign(n, vi(1<<(n-1), MAX_DIST));
    nxt.assign(n, vi(1<<(n-1), -1));
    int res = dp(0, (1<<(n-1))-1, dist);
    int p = 0, mask = (1<<(n-1))-1;
    while (mask) {
        tour.push_back(p);
        p = nxt[p][mask];
        mask -= (1 << (p-1));
    }
    return res;
}
