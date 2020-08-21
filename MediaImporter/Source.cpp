#include "Bitmap.h"
#include <string>
#include <iostream>
#include "Color.h"
#include <Windows.h>

/*
TODO:

-add the different infoheaders
-add decompression algorithm
-add support for bitmasks
-add support for color tables
-add support for indexed colors

*/

int main()
{
	/*std::cout << "Path: ";
	std::string path;
	std::getline(std::cin, path);*/

	std::string path = "F:\\Downloads\\download (Custom).bmp";

	sr::Bitmap bmp;
	bmp.loadFromFile(path);
	const std::vector<std::uint8_t>& data = bmp.getData();


	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int i = 0;
	int bytePerPixel = bmp.hasAlpha() ? 4 : 3;
	for (int h = 0; h < bmp.getHeight(); h++) {
		for (int w = 0; w < bmp.getWidth(); w++) {
			ce::Color c(data[i + 2], data[i + 1], data[i]);
			SetConsoleTextAttribute(hConsole, c.toConsoleColor());
			std::cout << ' ';
			i += bytePerPixel;
		}
		std::cout << std::endl;
	}

	system("pause");
}