#include "aspch.h"
#include "LayerStack.h"

namespace Asaurus
{
	LayerStack::LayerStack() {}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	void LayerStack::PushLayer(Layer* layer) 
	{ 
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer); 
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* layer) { m_Layers.emplace_back(layer); }

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
		else
		{
		#ifdef AS_DEBUG
			AS_CORE_WARN("Trying to pop layer that isn't in the LayerStack: {0}", layer->GetName());
		#else
			AS_CORE_WARN("Trying to pop layer that isn't in the LayerStack");
		#endif
		}
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
			m_Layers.erase(it);
		else
		{
		#ifdef AS_DEBUG
			AS_CORE_WARN("Trying to pop Overlay that isn't in the LayerStack: {0}", layer->GetName());
		#else
			AS_CORE_WARN("Trying to pop Overlay that isn't in the LayerStack");
		#endif
		}
	}
}