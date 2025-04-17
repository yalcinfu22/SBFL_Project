module Network;

Network::Network(int maxLayers) : m_MAX_layers(maxLayers)
{
  m_layers = new Layer*[maxLayers];
  m_layer_count = 0;
}

Network::~Network()
{
	delete[] m_layers;
}

bool Network::addLayer(Layer *newLayer)
{
    if (m_layer_count == m_MAX_layers) return false;
	m_layers[m_layer_count] = newLayer;
	m_layer_count++;
    return true;
}

Matrix Network::forward(Matrix input) const {
    for (int i = 0; i < m_layer_count; i++) {
        input = m_layers[i]->forward(input);
    }
    return input;
}
