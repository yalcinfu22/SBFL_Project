module Activation;

Activation::Activation(const char* str)
{
	int size = strlen(str) + 1;
	m_type = new char[size];
	for (int i = 0; i < size; i++)
		m_type[i] = str[i];
}

Activation::~Activation()
{
	delete[] m_type;
}

float Activation::operator()(float data)
{
	if (strcmp(m_type, "sigmoid") == 0)
		return sigmoid(data);
	else if (strcmp(m_type, "relu") == 0)
		return relu(data);
	else
		printf("No linked function found with the type\n");
	return -1; // problem indicator 
}

float Activation::relu(float data)
{
	return fmax(0, data);
}

float Activation::sigmoid(float data)
{
	return 1.0 / (1 + exp(-data));
}

const char* Activation::getType() const
{
	return m_type;
}

void Activation::printType() const
{
	const char* str = this->getType();
	for (int i = 0; str[i] != '\0'; i++)
		std::cout << str[i];
	std::cout << std::endl;
}
