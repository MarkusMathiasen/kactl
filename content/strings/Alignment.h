/**
 * Author: Markus Mathiasen
 * License: UPL
 * Source: Competetive Programming 4 book 2 (Steven Halim, Felix Halim, Suhendry Effendy)
 * Description: Given two vectors, it will compute the alignment of the vectors, which minimizes the score.
 * The current configuration finds the "edit distance".
 * Insert and delete cost refers to inserting and deleting from A.
 * Also, one can solve LCS by setting del=0; ins=0; match=-1; mismatch=inf.
 * Time: O(NM)
 * Status: Tested on kattis:drunktexting, stress-tested
 */
#pragma once

template<class T>
int alignment(vector<T>& A, vector<T>& B, vector<vi>& dp) {
	int del=1,ins=1,match=0,mismatch=1; // edit distance
	dp.assign(sz(A)+1, vi(sz(B)+1, 0));
	rep(i, 0, sz(A)+1) dp[i][0] = i*del;
	rep(j, 1, sz(B)+1) dp[0][j] = j*ins;
	rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1) {
		dp[i][j]=dp[i-1][j-1]+(A[i-1]==B[j-1]?match:mismatch);
		dp[i][j]=min(dp[i][j],dp[i-1][j]+del);
		dp[i][j]=min(dp[i][j],dp[i][j-1]+ins);
	}
	return dp[sz(A)][sz(B)];
}