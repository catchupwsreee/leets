#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    int m = strlen(s), n = strlen(p);
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }
    
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++) {
        dp[0][j] = (p[j - 1] == '*' && dp[0][j - 1]);
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    
    bool result = dp[m][n];
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
