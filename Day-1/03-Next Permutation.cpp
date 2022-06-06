vector<int> nextPermutation(vector<int> &permutation, int n) {
    int idx1, idx2;
    for (idx1 = n - 2; idx1 >= 0; idx1--) {
        if (permutation[idx1] < permutation[idx1 + 1]) {
            break;
        }
    }
    if (idx1 == -1) {
        reverse(permutation.begin(), permutation.end());
    }

    else {
        for (idx2 = n - 1; idx2 > idx1; idx2--) {
            if (permutation[idx2] > permutation[idx1]) {
                break;
            }
        }
        swap(permutation[idx1], permutation[idx2]);
        reverse(permutation.begin() + idx1 + 1, permutation.end());
    }
    return permutation;
}