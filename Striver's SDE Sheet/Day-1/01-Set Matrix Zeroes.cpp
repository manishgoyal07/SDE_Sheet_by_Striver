void setZeros(vector<vector<int>> &matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int i, j, col0 = 1;
    for (i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            col0 = 0;
        }
        for (j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (i = rows - 1; i >= 0; i--) {
        for (j = cols - 1; j > 0; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}