#include <stdio.h>
#include <stdlib.h>

int isSafe(int mat[][10], int row, int col, int n) {
    int i, j;
    for (i = 0; i < row; i++) {
        if (mat[i][col]) {
            return 0;
        }
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (mat[i][j]) {
            return 0;
        }
    }
    for (i = row - 1, j = col + 1; j < n && i >= 0; i--, j++) {
        if (mat[i][j]) {
            return 0;
        }
    }

    return 1;
}

int placeQueens(int row, int mat[][10], int n) {
    if (row == n) {
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(mat, row, i, n)) {
            mat[row][i] = 1;
            if (placeQueens(row + 1, mat, n)) {
                return 1;
            }
            mat[row][i] = 0;
        }
    }
    return 0;
}

void nQueen(int n) {
    int mat[10][10] = {0};
    if (placeQueens(0, mat, n)) {
        printf("Solution: \n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    printf("%d ", j + 1);
                }
            }
        }
        printf("\n");
    } else {
        printf("No solution exists.\n");
    }
}

int main() {
    int n = 4;
    nQueen(n);
    return 0;
}
