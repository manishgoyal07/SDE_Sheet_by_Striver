// Problem:	 Find the repeating and missing numbers

/*---------------------------------------------------------------------------------------------------------------*/
// Code:

int *findTwoElement(int *arr, int n) {
    int i, it, xor1 = arr[0];
    for (it = 1; it < n; it++) {
        xor1 ^= arr[it];
    }
    for (i = 1; i <= n; i++) {
        xor1 ^= i;
    }
    int pos = xor1 & ~(xor1 - 1);
    int num1 = 0, num2 = 0;
    for (it = 0; it < n; it++) {
        if (arr[it] && pos) {
            num1 ^= arr[it];
        } else {
            num2 ^= arr[it];
        }
    }
    for (i = 1; i <= n; i++) {
        if (i && pos) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }
    }

    int num1_count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1) num1_count++;
    }
    if (num1_count == 0) {
        return new int[2]{num2, num1};
    } else {
        return new int[2]{num1, num2};
    }
}

/*---------------------------------------------------------------------------------------------------------------*/
// Time Complexity:  O(N)
// Auxillary Space Complexity:  O(1)