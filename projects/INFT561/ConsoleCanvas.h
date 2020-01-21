#pragma once
/** Dependencies **********************************************************************************/
/** Declarations **********************************************************************************/

	#include "default.h"

	class ConsoleCanvas
	{
	public:
		// public structs
		struct Dot
		{
			vec4 v1;
			vec4 c1;
		};
		struct Text
		{
			char * cstring;
			vec4 v1;
			vec4 c1;
		};
		struct Line
		{
			vec4 v1, v2;
			vec4 c1, c2;
		};
		struct Triangle
		{
			vec4 v1, v2, v3;
			vec4 c1, c2, c3;
		};
		// public defaults
		~ConsoleCanvas();
		ConsoleCanvas(int width, int height);
		// public functions
		void clear();
		void render();
		void render(Dot data);
		void render(Text data);
		void render(Line data);
		void render(Triangle data);
		const int getWidth();
		const int getHeight();
	private:
		// variables
		int m_width;
		int m_height;
		int m_length;
		float * m_DBuffer;
		// protected functions
		void RASTERIZE(const ConsoleCanvas::Line& data);
		void RASTERIZE(const ConsoleCanvas::Triangle& data);
		void RASTERIZE(const ConsoleCanvas::Dot& data);
		void RASTERIZE(const ConsoleCanvas::Text& data);
		void WORLD_TO_SCREEN(vec4& point);
		bool RASTERIZE_CHECK(int x, int y, float z, int index);
		void TRIANGLE_SORT_BY_Y(ConsoleCanvas::Triangle& data);
		void TRIANGLE_SORT_BY_Y(vec4* v, vec4* c);
		vec4 LERP(const vec4& a, const vec4& b, float t);
	};

/**************************************************************************************************/