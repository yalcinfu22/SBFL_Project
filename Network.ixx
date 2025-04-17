export module Network;

import Layer;  // Because Network holds pointers to Layer
import Matrix; // Because Network::forward returns a Matrix

export class Network
{
public:
	Network(int);
	~Network();
	bool addLayer(Layer*);
	Matrix forward(Matrix) const;
	int getLayerCount() const { return m_layer_count; };
private:
	Layer** m_layers;
	const int m_MAX_layers;
	int m_layer_count;
};
