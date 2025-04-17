export module Activation;

import <cmath>;     // for std::exp
import <cstdio>;    // for printf
import <cstring>;   // for std::strcmp
import <algorithm>; // for std::max if needed
import <iostream>;
export class Activation
{
public:
	Activation(const char*);
	~Activation();
	float operator()(float);
	static float relu(float);
	static float sigmoid(float);
	void printType() const;
private:
	const char* getType() const;
	char* m_type;
};
