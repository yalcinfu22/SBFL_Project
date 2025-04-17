module Layer;
import <iostream>;
#include <stdlib.h>
Layer::Layer(int inputSize, int outputSize, Activation& activation) 
	: m_weights(inputSize, outputSize), m_biases(1, outputSize), m_activation(activation) 
{
	initializeWeights();
	initializeBiases();
}

void Layer::initializeWeights()
{
	for (int i = 0; i < m_weights.getRows(); i++)
		for (int j = 0; j < m_weights.getCols(); j++)
			m_weights[i][j] = (float)rand() / (float)(RAND_MAX);
}

void Layer::initializeBiases()
{
	for (int i = 0; i < m_biases.getCols(); i++)
		m_biases[0][i] = (float)rand() / (float)(RAND_MAX);
}

Matrix Layer::forward(const Matrix& inputM)
{
	Matrix output = (inputM * m_weights + m_biases);
	for (int i = 0; i < output.getCols(); i++)
		output[0][i] = m_activation(output[0][i]);
	return output;
}

void Layer::printWeights() const
{
	for (int i = 0; i < m_weights.getRows(); i++)
	{
		for (int j = 0; j < m_weights.getCols(); j++)
			std::cout << m_weights[i][j];
		std::cout << '\n';
	}
}

void Layer::printBiases() const
{
	for (int i = 0; i < m_biases.getCols(); i++)
		std::cout << m_biases[0][i];
	std::cout << std::endl;
}
