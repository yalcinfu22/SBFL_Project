export module Matrix;
import <iostream>; // If needed for your print function
import <cstdio>;   // If needed for printf

export class Matrix
{
public:
	Matrix(int, int);
	Matrix(const Matrix&);
	int getRows() const { return m_rows; };
	int getCols() const { return m_cols; };
	Matrix& operator=(const Matrix& rM);
	Matrix operator+(const Matrix& rM) const;
	Matrix operator*(const Matrix& rM) const;
	float* operator[](int index);
	const float* operator[](int index) const;
	void print() const;
	void randomize();
	~Matrix();

private:
	Matrix();
	float** m_data;
	int m_rows;
	int m_cols;
};
