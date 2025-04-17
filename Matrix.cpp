module Matrix;
import std;
using std::cout;
#include <stdlib.h>;

Matrix::Matrix(int rows, int cols) : m_rows((rows > 0) ? rows : 1), m_cols((cols > 0) ? cols : 1)
{
	m_data = new float* [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_data[i] = new float[m_cols];
		for (int j = 0; j < m_cols; j++)
		{
			m_data[i][j] = 0.0f;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; i++)
	{
	  delete[] m_data[i];
    }
	delete[] m_data;
}

Matrix::Matrix() : m_rows(0), m_cols(0), m_data(0) {};

Matrix Matrix::operator+(const Matrix& rM) const
{
	if (m_rows != rM.m_rows || m_cols != rM.m_cols)
	{
	  printf("Invalid sizes\n");
	  return Matrix(); // error matrix
    }

	Matrix newM(m_rows, m_cols);

	for(int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
		  newM.m_data[i][j] = rM.m_data[i][j] + m_data[i][j];
	return newM;
}

Matrix Matrix::operator*(const Matrix& rM) const
{
	if (m_cols != rM.m_rows)
		return Matrix();

	Matrix newM(m_rows, rM.m_cols);
	for (int i = 0; i < rM.m_cols; i++)
	{
		for (int j = 0; j < m_rows; j++)
		{
			float sum = 0.0f;
			for (int k = 0; k < m_cols; k++)
			{
				sum += rM.m_data[k][i] * m_data[j][k];
			}
			newM.m_data[j][i] = sum;
		}
	}
	return newM;
}

Matrix::Matrix(const Matrix& M) : m_rows((M.m_rows > 0) ? M.m_rows : 1), m_cols((M.m_cols > 0) ? M.m_cols : 1) 
{
	m_data = new float* [m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_data[i] = new float[m_cols];
		for (int j = 0; j < m_cols; j++)
			m_data[i][j] = M.m_data[i][j];
	}
}

float* Matrix::operator[](int index)
{
  return m_data[index];
}

const float* Matrix::operator[](int index) const
{
  return m_data[index];
}

void Matrix::print() const
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			cout << m_data[i][j] << " ";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

Matrix& Matrix::operator=(const Matrix& rM)
{
	if (this == &rM)
		return *this;

	if (rM.m_cols != m_cols || rM.m_rows != m_rows)
	{
		for (int i = 0; i < m_rows; i++)
		{
			delete[] m_data[i];
		}
		delete[] m_data;

		m_rows = rM.m_rows;
		m_cols = rM.m_cols;

		m_data = new float* [rM.m_rows];
		for (int i = 0; i < rM.m_rows; i++)
		{
			m_data[i] = new float[rM.m_cols];
			for (int j = 0; j < rM.m_cols; j++)
				m_data[i][j] = rM.m_data[i][j];
		}
    }
	else
	{
		for (int i = 0; i < rM.m_rows; i++)
		{
			for (int j = 0; j < rM.m_cols; j++)
				m_data[i][j] = rM.m_data[i][j];
		}
	}
	return *this;
}

void Matrix::randomize()
{

	for (int i = 0; i < m_rows; ++i) {
		for (int j = 0; j < m_cols; ++j) {
			m_data[i][j] = (float)rand() / (float)0x7fff;
		}
	}
}
