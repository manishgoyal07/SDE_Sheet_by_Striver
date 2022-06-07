
pair<int, int> missingAndRepeating(vector<int> &arr, int n) {
    pair<int, int> ans;
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= arr[i];
    }
    for (int i = 1; i <= n; i++) {
        xr ^= i;
    }
    int num1 = 0, num2 = 0, pos = xr & ~(xr - 1);
    for (int i = 0; i < n; i++) {
        if (arr[i] & pos) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i & pos) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }
    }
    for (auto i : arr) {
        if (i == num2) {
            ans.first = num1;
            ans.second = num2;
            return ans;
        } else if (i == num1) {
            ans.first = num2;
            ans.second = num1;
            return ans;
        }
    }
}
