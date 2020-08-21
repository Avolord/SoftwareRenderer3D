#pragma once

namespace ce {

	class Color
	{
	public:
		Color();
		Color(const unsigned char red, const unsigned char green, const unsigned char blue);

		virtual ~Color() = default;

		unsigned short toConsoleColor() const;

	public:
		unsigned char red;
		unsigned char green;
		unsigned char blue;

	public:
		static const Color BLACK;
		static const Color DARK_BLUE;
		static const Color DARK_GREEN;
		static const Color TURQUOISE;
		static const Color DARK_RED;
		static const Color PURPLE;
		static const Color DARK_YELLOW;
		static const Color GREY;
		static const Color DARK_GREY;
		static const Color BLUE;
		static const Color GREEN;
		static const Color CYAN;
		static const Color RED;
		static const Color PINK;
		static const Color YELLOW;
		static const Color WHITE;
	};
}
