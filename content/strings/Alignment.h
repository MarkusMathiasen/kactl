/**
 * Author: Markus Mathiasen
 * License: CC0
 * Source: Competetive Programming 4 (book 2)
 * Description: Given two vectors, it will compute the alignment of the vectors, which maximizes the score.
 * This can be used to find the "edit distance". Insert and delete cost refers to inserting and deleting from A.
 * Also, one can solve LCS by setting delete=0; insert=0; match=1; mismatch=-inf.
 * Time: O(NM)
 * Status: Tested on kattis:declaration (TODO: stress-test)
 */
#pragma once

template<class T>
ll alignment(vector<T>& A, vector<T>& B, vector<vi>& dp) {
    ll del=-1,ins=-1,match=2,mismatch=-1;
    dp.assign(sz(A)+1, vi(sz(B)+1, 0));
    rep(i, 0, sz(A)+1) dp[i][0] = i*del;
    rep(j, 1, sz(B)+1) dp[0][j] = j*ins;
    rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1) {
        dp[i][j]=dp[i-1][j-1]+(A[i-1]==B[j-1]?match:mismatch);
        dp[i][j]=max(dp[i][j],dp[i-1][j]+del);
        dp[i][j]=max(dp[i][j],dp[i][j-1]+ins);
    }
    return dp[sz(A)][sz(B)];
}