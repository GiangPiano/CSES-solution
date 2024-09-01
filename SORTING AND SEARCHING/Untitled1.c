#include <stdio.h>

int main() {
    long long m, n, k;
    scanf("%lld %lld %lld", &m, &n, &k);
    
    
    long long a[m][n], b[n][k], c[m][k];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            c[i][j] = 0;
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%lld", &b[i][j]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < n; l++) {
                c[i][j] += a[i][l]*b[l][j];
            }
            printf("%lld ", c[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
