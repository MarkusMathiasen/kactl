#include "../utilities/template.h"

#include "../../content/strings/Alignment.h"

int main() {
    vector<char> A = {'A', 'C', 'A', 'A', 'T', 'C', 'C'};
    vector<char> B = {'A', 'G', 'C', 'A', 'T', 'G', 'C'};
    vector<vi> table;
    ll x = alignment(A, B, table);
    assert(x == 7);
    printf("Tests passed!\n");
}