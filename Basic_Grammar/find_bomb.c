#include <stdio.h>
#include <stdlib.h>


int di[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dj[] = { 0, 0, 1, -1, 1, -1, 1, -1 };


int count_bomb(char **arr, int i, int j, int n, int m) {
    int cnt = 0;
    
    for (int k = 0; k < 8; k++) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || ni > n - 1 || nj < 0 || nj > m - 1)
            continue;
        else
            if (arr[ni][nj] == '*')
                cnt++;
    }
    return cnt;   
}

int main() {
    int m, n;  // m: 가로(렬) , n: 세로(행)
    scanf("%d %d", &m, &n);

    char **arr = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(sizeof(char) * (m + 1));
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        arr[i][m] = '\0';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '*')
                printf("%c", arr[i][j]);
            else
                printf("%d", count_bomb(arr, i, j, n, m));
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);    

    return 0;
}