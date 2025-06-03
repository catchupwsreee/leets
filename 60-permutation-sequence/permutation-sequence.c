char* getPermutation(int n, int k) {
    int fact[10];
    int used[10] = {0};
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i;

    char* res = malloc(n + 1);
    res[n] = '\0';
    k--;

    for (int i = 0; i < n; i++) {
        int idx = k / fact[n - 1 - i];
        k %= fact[n - 1 - i];

        int count = 0, j = 1;
        while (1) {
            if (!used[j]) {
                if (count == idx) break;
                count++;
            }
            j++;
        }

        res[i] = j + '0';
        used[j] = 1;
    }

    return res;
}
