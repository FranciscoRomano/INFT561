#pragma once
/** Dependencies **********************************************************************************/

#include <ctime>
#include "ConsoleCanvas.h"

/** Declarations **********************************************************************************/

	// public defaults
	ConsoleCanvas::~ConsoleCanvas()
	{
		ccon::cconTerminate();
	}

	ConsoleCanvas::ConsoleCanvas(int width, int height) : console{ (SHORT)width, (SHORT)height }, m_DBuffer{ width * height }
	{
		// initialize values
		this->m_width = width;
		this->m_height = height;
		this->m_length = width * height;
	}

	// public functions
	void ConsoleCanvas::clear()
	{
		for (int i = 0; i < m_length; i++)
		{
			// clear buffers
			console[i] = {};
			m_DBuffer[i] = 0.0f;
		}
	}

	void ConsoleCanvas::render()
	{
		console.writeA();
	}

	void ConsoleCanvas::render(Dot data)
	{
		// world to screen
		WORLD_TO_SCREEN(data.v1);
		// rasterize point
		RASTERIZE(data);
	}

	void ConsoleCanvas::render(Text data)
	{
		// world to screen
		WORLD_TO_SCREEN(data.v1);
		// rasterize point
		RASTERIZE(data);
	}

	void ConsoleCanvas::render(Line data)
	{
		// world to screen
		WORLD_TO_SCREEN(data.v1);
		WORLD_TO_SCREEN(data.v2);
		// rasterize line
		RASTERIZE(data);
	}

	void ConsoleCanvas::render(Triangle data)
	{
		// check if flat triangle
		if (data.v1.y == data.v2.y)
		{
			// world to screen
			WORLD_TO_SCREEN(data.v1);
			WORLD_TO_SCREEN(data.v2);
			WORLD_TO_SCREEN(data.v3);
			// rasterize line
			RASTERIZE(data);
		}
		// calculate complex triangle
		else
		{
			// triangle sort
			TRIANGLE_SORT_BY_Y(data);
			// calculate v4 intersection
			vec2 vN = {
				(data.v1.x + ((data.v2.y - data.v1.y) / (data.v3.y - data.v1.y)) * (data.v3.x - data.v1.x)),
				data.v2.y,
			};
			// ratio between v1v4 - v1v3
			vec2 v1v4 = vN - vec2(data.v1.x, data.v1.y);
			vec2 v1v3 = vec2(data.v3.x - data.v1.x, data.v3.y - data.v1.y);
			float lengthSqrd1 = v1v4.x * v1v4.x + v1v4.y * v1v4.y;
			float lengthSqrd2 = v1v3.x * v1v3.x + v1v3.y * v1v3.y;
			float ratio = sqrtf(lengthSqrd1 / lengthSqrd2);
			// recalculate v4 intersection
			vec4 v4 = LERP(data.v1, data.v3, ratio);
			vec4 c4 = LERP(data.c1, data.c3, ratio);
			v4.y = data.v2.y;
			// fill bottom/top flat triangle
			render({ data.v2, v4, data.v3, data.c2, c4, data.c3 });
			render({ v4, data.v2, data.v1, c4, data.c2, data.c1 });
		}
	};

	const int ConsoleCanvas::getWidth()
	{
		// get width
		return m_width;
	};

	const int ConsoleCanvas::getHeight()
	{
		// get height
		return m_height;
	};

	// protected functions
	void ConsoleCanvas::RASTERIZE(const ConsoleCanvas::Dot & data)
	{
		int x = int(data.v1.x + 0.5f);
		int y = int(data.v1.y + 0.5f);
		int index = y * m_width + x;
		// rasterize check
		if (RASTERIZE_CHECK(x, y, data.v1.z, index) == false) return;
		// update depth buffer
		m_DBuffer[index] = data.v1.z;
		// [ccon] update colour buffer
		RASTERIZE(
			y * m_width + x,
			data.c1.x * data.c1.w,
			data.c1.y * data.c1.w,
			data.c1.z * data.c1.w
		);
	};

	void ConsoleCanvas::RASTERIZE(const ConsoleCanvas::Line & data)
	{
		// calculate steps
		vec2 dir = vec2(data.v2.x - data.v1.x, data.v2.y - data.v1.y);
		int steps = int(fmax(abs(dir.x), abs(dir.y)) + 1.0f);
		float delta = 1 / float(steps == 0 ? 1 : steps);
		// iterate through dots
		for (int i = 0; i <= steps; i++)
		{
			// calculate t
			float t = delta * float(i);
			// rasterize point
			RASTERIZE(Dot{
				LERP(data.v1, data.v2, t),
				LERP(data.c1, data.c2, t),
			});
		}
	};

	void ConsoleCanvas::RASTERIZE(const ConsoleCanvas::Text & data)
	{
		int x = int(data.v1.x + 0.5f);
		int y = int(data.v1.y + 0.5f);
		int index = y * m_width + x;
		// rasterize check
		if (RASTERIZE_CHECK(x, y, data.v1.z, index) == false) return;
		// update depth buffer
		m_DBuffer[index] = data.v1.z;
		// [ccon] update colour buffer
		RASTERIZE(
			y * m_width + x,
			data.c1.x * data.c1.w,
			data.c1.y * data.c1.w,
			data.c1.z * data.c1.w
		);
	};

	void ConsoleCanvas::RASTERIZE(const ConsoleCanvas::Triangle & data)
	{
		// calculate steps
		int steps = int(abs(data.v3.y - data.v1.y) + 1.0f);
		float delta = 1 / float(steps);
		// iterate through lines
		for (int i = 0; i <= steps; i++)
		{
			// calculate t
			float t = delta * float(i);
			// render line
			RASTERIZE(Line{
				LERP(data.v1, data.v3, t),
				LERP(data.v2, data.v3, t),
				LERP(data.c1, data.c3, t),
				LERP(data.c2, data.c3, t),
			});
		}
	};

	void ConsoleCanvas::RASTERIZE(const int& index, const float& r, const float& g, const float& b)
	{
		static CHAR ascii[] = { (CHAR)0x00, (CHAR)0xb0, (CHAR)0xb1, (CHAR)0xb2, (CHAR)0xDB };
		static float length = float(sizeof(ascii) - 1) + 0.015f;

		// calculate luminance (HSP Color Model)
		float l = sqrtf(0.299f * powf(r, 2) + 0.587f * powf(g, 2) + 0.114f * powf(b, 2));

		// calculate color
		WORD color = 0;
		if (l > 0.666f) color |= 0x88; else if (l > 0.333f) color |= 0x8;
		if (r > 0.666f) color |= 0x44; else if (r > 0.333f) color |= 0x4;
		if (g > 0.666f) color |= 0x22; else if (g > 0.333f) color |= 0x2;
		if (b > 0.666f) color |= 0x11; else if (b > 0.333f) color |= 0x1;

		// set char info
		console[index] = { (WCHAR)ascii[int(l * length)], color };
		//console.writeA();
	}

	void ConsoleCanvas::WORLD_TO_SCREEN(vec4 & point)
	{
		// calculate screen coordinates
		point.x = (point.x + 1.0f) * (float(m_width - 1) / 2.0f);
		point.y = (point.y + 1.0f) * (float(m_height - 1) / 2.0f);
	};

	bool ConsoleCanvas::RASTERIZE_CHECK(int x, int y, float z, int index)
	{
		// culling check
		if (x < 0 || x >(m_width - 1)) return false;
		if (y < 0 || y >(m_height - 1)) return false;
		// depth buffer check
		if (z < 0.0f || (m_DBuffer[index] != 0 && z > m_DBuffer[index])) return false;
		// all tests passed successully
		return true;
	};

	void ConsoleCanvas::TRIANGLE_SORT_BY_Y(ConsoleCanvas::Triangle & data)
	{
		// swap v1-v2
		TRIANGLE_SORT_BY_Y(&data.v1, &data.c1);
		// swap v2-v3
		TRIANGLE_SORT_BY_Y(&data.v2, &data.c2);
		// swap v1-v2
		TRIANGLE_SORT_BY_Y(&data.v1, &data.c1);
	};

	void ConsoleCanvas::TRIANGLE_SORT_BY_Y(vec4 * vec, vec4 * col)
	{
		// check lowest y
		if (vec[1].y < vec[0].y)
		{
			// swap points
			vec4 vtemp = vec[0];
			vec[0] = vec[1];
			vec[1] = vtemp;
			// swap colours
			vec4 ctemp = col[0];
			col[0] = col[1];
			col[1] = ctemp;
		}
	};

	vec4 ConsoleCanvas::LERP(const vec4 & a, const vec4 & b, float t)
	{
		return{
			a.x + (b.x - a.x) * t,
			a.y + (b.y - a.y) * t,
			a.z + (b.z - a.z) * t,
			a.w + (b.w - a.w) * t,
		};
	};

/**************************************************************************************************/