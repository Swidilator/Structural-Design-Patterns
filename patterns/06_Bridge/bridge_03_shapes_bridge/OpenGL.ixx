
module;
#include <simple2d.h>
#include <vector>
#include <tuple>

export module birdge.shapes_bridge.OpenGL;

import bridge.shapes_bridge.Renderer;
import bridge.Point;

namespace bridge::shapes_bridge
{
	export class OpenGL :
		public Renderer
	{
		inline static std::vector<std::tuple<Point, float>> m_Circles{};
		inline static std::vector<std::tuple<Point, Point>> m_Lines{};
		S2D_Window* m_pWindow{};

	public:
		OpenGL()
		{
			m_pWindow = S2D_CreateWindow("MainWindow", 800, 600, nullptr, OpenGL::Render, S2D_RESIZABLE);
		}

		void RenderCircle(Point position, float radius) override
		{
			m_Circles.push_back(std::make_tuple(position, radius));
		}

		void RenderLine(Point start, Point end) override
		{
			m_Lines.push_back(std::make_tuple(start, end));
		}

		static void Render()
		{
			for (auto line : m_Lines)
			{
				auto [start, end] = line;
				S2D_DrawLine(start.x, start.y, end.x, end.y, 1,
				             1, 1, 1, 1,
				             1, 1, 1, 1,
				             1, 1, 1, 1,
				             1, 1, 1, 1
				);
			}

			for (auto circle : m_Circles)
			{
				auto [position, radius] = circle;
				S2D_DrawCircle(position.x, position.y, radius, 100, 1, 1, 0, 1);
			}
		}


		void Show() override
		{
			S2D_Show(m_pWindow);
		}
	};
}
