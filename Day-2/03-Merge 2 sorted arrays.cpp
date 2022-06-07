vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m,
                                 int n) {
    vector<int> v;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            v.push_back(arr1[i++]);

        }

        else {
            v.push_back(arr2[j++]);
        }
    }
    while (i < m) {
        v.push_back(arr1[i++]);
    }
    while (j < n) {
        v.push_back(arr2[j++]);
    }
    return v;
}