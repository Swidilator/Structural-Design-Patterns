#pragma once

#include "../Window.h"

import bridge.shapes_bridge.Renderer;
import bridge.Point;

namespace bridge::shapes_bridge
{
	class GDI :
		public Renderer
	{
		Window m_hWnd{};

	public:
		GDI();
		auto RenderCircle(Point position, float radius) -> void override;
		auto RenderLine(Point start, Point end) -> void override;
		auto Show() -> void override;
	};
}
