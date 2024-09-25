#include "GDI.h"

import bridge.shapes_bridge.Renderer;
import bridge.Point;

namespace bridge::shapes_bridge
{
	GDI::GDI()
	{
		m_hWnd.Show();
	}

	auto GDI::RenderCircle(Point position, float radius) -> void
	{
		m_hWnd.DrawCircle(position, radius);
	}

	auto GDI::RenderLine(Point start, Point end) -> void
	{
		m_hWnd.DrawLine(start, end);
	}

	auto GDI::Show() -> void
	{
		m_hWnd.Run();
	}
}
