#include "Color.h"

namespace ce
{
	//some predefined colors
	const Color Color::BLACK = Color(0, 0, 0);
	const Color Color::DARK_BLUE = Color(0, 0, 128);
	const Color Color::DARK_GREEN = Color(0, 128, 0);
	const Color Color::TURQUOISE = Color(0, 128, 128);
	const Color Color::DARK_RED = Color(128, 0, 0);
	const Color Color::PURPLE = Color(128, 0, 128);
	const Color Color::DARK_YELLOW = Color(128, 128, 0);
	const Color Color::GREY = Color(192, 192, 192);
	const Color Color::DARK_GREY = Color(128, 128, 128);
	const Color Color::BLUE = Color(0, 0, 255);
	const Color Color::GREEN = Color(0, 255, 0);
	const Color Color::CYAN = Color(0, 255, 255);
	const Color Color::RED = Color(255, 0, 0);
	const Color Color::PINK = Color(255, 0, 255);
	const Color Color::YELLOW = Color(255, 255, 0);
	const Color Color::WHITE = Color(255, 255, 255);

	/**
	 * \brief default constructor that initializes to black
	 */
	Color::Color() : red(0), green(0), blue(0)
	{
	}

	/**
	 * \brief constructor
	 * \param red the amount of red 0-255
	 * \param green the amount of green 0-255
	 * \param blue the amount of blue 0-255
	 */
	Color::Color(const unsigned char red, const unsigned char green, const unsigned char blue)
		:
		red(red), green(green), blue(blue)
	{
	}

	/**
	 * \brief converts an rgb-color into one of the 16 available colors
	 * \return a color that the console can display
	 */
	unsigned short ce::Color::toConsoleColor() const
	{
		unsigned short color = ((red > 128) | (green > 128) | (blue > 128)) ? 8 : 0; // bright bit
		color |= (red > 64) ? 4 : 0; // red bit
		color |= (green > 64) ? 2 : 0; // green bit
		color |= (blue > 64) ? 1 : 0; // blue bit
		return color << 4;
	}
}
