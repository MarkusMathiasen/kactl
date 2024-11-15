#include "../utilities/template.h"
#include "../../content/strings/Alignment.h"

vector<vi> dp;
template<class T> int edit_distance(vector<T>& A, vector<T>& B, int len_A, int len_B) {
    if (dp[len_A][len_B] != -1) return dp[len_A][len_B];
    if (len_A == 0) return dp[len_A][len_B] = len_B;
    if (len_B == 0) return dp[len_A][len_B] = len_A;
    if (A[len_A-1] == B[len_B-1]) return dp[len_A][len_B] = edit_distance(A, B, len_A-1, len_B-1);
    else return dp[len_A][len_B] = 1 + min({edit_distance(A, B, len_A-1, len_B),
                         edit_distance(A, B, len_A, len_B-1),
                         edit_distance(A, B, len_A-1, len_B-1)});
}

template<class T> int rec_edit_distance(vector<T>& A, vector<T>& B) {
    dp.assign(sz(A)+1, vi(sz(B)+1, -1));
    return edit_distance(A, B, sz(A), sz(B));
}

template<class T> string to_string(vector<T> A) {
    if (sz(A) == 0) return "[]";
    string res = "[";
    for (T x : A) res += to_string(x) + ", ";
    res.pop_back(); res.pop_back();
    return res + "]";
}

int main() {
    int its = 1e5;
    rep(it,0,its) {
        int n = rand() % 5, m = rand() % 5;
        if (it*2 >= its) n += 15, m += 15;
        vi A(n), B(m);
        for(auto &x: A) x = rand() % 4;
        for(auto &x: B) x = rand() % 4;
        int normal = rec_edit_distance(A, B);
        int edit = alignment(A, B, dp);
        if (normal != edit) {
            cout << "Edit distance between " << to_string(A) << " and " << to_string(B) << " is " << normal << " but got " << edit << endl;
            abort();
        }
    }
	cout << "Tests passed!" << endl;
}