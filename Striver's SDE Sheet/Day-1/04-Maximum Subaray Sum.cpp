long long maxSubarraySum(int arr[], int n) {
    long long sum = 0, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum < 0) {
            sum = 0;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}