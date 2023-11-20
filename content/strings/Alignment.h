/**
 * Author: Markus Mathiasen
 * License: UPL
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
    dp.assign(sz(A)+1, vi(sz(B)+1, 0));
    rep(i, 0, sz(A)+1) dp[i][0] = i*(-1); // delete score -1
    rep(j, 1, sz(B)+1) dp[0][j] = j*(-1); // insert score -1
    rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1) {
        // match and mismatch score (2 and -1)
        dp[i][j]=dp[i-1][j-1]+(A[i-1]==B[j-1]?2:-1);
        dp[i][j]=max(dp[i][j],dp[i-1][j]-1); // delete -1
        dp[i][j]=max(dp[i][j],dp[i][j-1]-1); // insert -1
    }
    return dp[sz(A)][sz(B)];
}