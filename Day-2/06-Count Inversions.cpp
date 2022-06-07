#include <bits/stdc++.h>
long long int merge(long long arr[], long long s, long long e) {
    long long mid = s + (e - s) / 2;
    long long n1 = mid - s + 1;
    long long n2 = e - mid;
    long long arr1[n1], arr2[n2];
    long long k = s;
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[k++];
    }
    k = mid + 1;
    for (long long i = 0; i < n2; i++) {
        arr2[i] = arr[k++];
    }
    long long index1 = 0, index2 = 0, count = 0;
    k = s;
    while (index1 < n1 && index2 < n2) {
        if (arr1[index1] <= arr2[index2]) {
            arr[k++] = arr1[index1++];
        } else {
            arr[k++] = arr2[index2++];

            count = count + n1 - index1;
        }
    }
    while (index1 < n1) {
        arr[k++] = arr1[index1++];
    }
    while (index2 < n2) {
        arr[k++] = arr2[index2++];
    }
    return count;
}
long long int merge_sort(long long arr[], long long s, long long e) {
    long long count = 0;
    if (s < e) {
        long long mid = s + (e - s) / 2;
        count = count + merge_sort(arr, s, mid);
        count = count + merge_sort(arr, mid + 1, e);
        count = count + merge(arr, s, e);
    }
    return count;
}
long long getInversions(long long *arr, int n) {
    // Write your code here.
    return merge_sort(arr, 0, n - 1);
}