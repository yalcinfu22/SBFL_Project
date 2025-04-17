export module Layer;
import Matrix;
import Activation;

export class Layer
{
public:
	Layer(int, int, Activation&);
	Matrix forward(const Matrix&);
	void initializeWeights();
	void initializeBiases();
	void printWeights() const;
	void printBiases() const;
private:
	Matrix m_weights; 
	Matrix m_biases;
	Activation& m_activation;
};
