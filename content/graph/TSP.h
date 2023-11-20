/**
 * Author: Markus Mathiasen
 * License: UPL
 * Source: Competetive Programming 4 (book 1)
 * Description: Give a distance matrix, computes the shortest Hamiltonian cycle,
 * finding the optimal solution to TSP.
 * Time: O(2^N N^2)
 * Status: Tested on kattis:beepers TODO: stress-test
 */
#pragma once

const ll MAX_DIST = 1e9;
vector<vi> memo, nxt;
vi tour;
ll dp(ll v, ll mask, vector<vi>& dist) {
    if (mask == 0) return dist[v][0];
    ll& res = memo[v][mask];
    if (res != MAX_DIST) return res;
    ll m = mask;
    while (m) {
        ll u_pow = m&(-m);
        ll u = __builtin_ctzll(u_pow)+1;
        ll val = dist[v][u] + dp(u, mask-u_pow, dist);
        if (val < res) {
            res = val;
            nxt[v][mask] = u;
        }
        m -= u_pow;
    }
    return res;
}
ll tsp(vector<vi>& dist) {
    ll n = sz(dist);
    memo.assign(n, vi(1<<(n-1), MAX_DIST));
    nxt.assign(n, vi(1<<(n-1), -1));
    ll res = dp(0, (1<<(n-1))-1, dist);
    ll p = 0, mask = (1<<(n-1))-1;
    while (mask) {
        tour.push_back(p);
        p = nxt[p][mask];
        mask -= (1 << (p-1));
    }
    return res;
}
