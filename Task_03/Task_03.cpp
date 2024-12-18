#include <iostream>

constexpr unsigned short MATRIX_MAX_ROWS = 100;
constexpr unsigned short MATRIX_MAX_COLS = 100;

void enterMatrixValues(int matrix[MATRIX_MAX_ROWS][MATRIX_MAX_COLS], const unsigned short rows, const unsigned short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(const int matrix[MATRIX_MAX_ROWS][MATRIX_MAX_COLS], const unsigned short rows, const unsigned short cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}

		std::cout << '\n';
	}
}

void rotateMatrixColumns(int matrix[MATRIX_MAX_ROWS][MATRIX_MAX_COLS], const unsigned short rows, const unsigned short cols)
{
	int currentColumn = 0;

	for (int row = 0; row < cols; row++)
	{
		for (int rotateCount = 0; rotateCount < currentColumn + 1; rotateCount++)
		{
			int temp = matrix[rows - 1][currentColumn];

			for (int col = rows - 1; col >= 0; col--)
			{
				matrix[col + 1][row] = matrix[col][row];
			}

			matrix[0][currentColumn] = temp;
		}

		currentColumn++;
	}
}

int main()
{
	int matrix[MATRIX_MAX_COLS][MATRIX_MAX_COLS];

	unsigned short rows, cols;
	std::cin >> rows;
	std::cin >> cols;

	while (rows > MATRIX_MAX_ROWS || cols > MATRIX_MAX_COLS)
	{
		std::cout << "Invalid input! Make sure the rows and columns are less than 100!";
	}

	enterMatrixValues(matrix, rows, cols);

	std::cout << '\n';

	rotateMatrixColumns(matrix, rows, cols);

	printMatrix(matrix, rows, cols);
}