bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
	if (matrix == NULL || matrixSize == 0)
		return false;

	int row = 0, col = *matrixColSize - 1;
	while (row<matrixSize && col >= 0){
		if (matrix[row][col] == target)
			return true;

		if (matrix[row][col]<target)
			row++;

		else
			col--;
	}
	return false;
}