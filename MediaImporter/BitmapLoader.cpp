#include "BitmapLoader.h"
#include "FileLoader.h"
#include <iostream>

namespace sr {

	namespace BitmapLoader {

		void loadBitmapFromFile(std::string_view t_filename, std::vector<std::uint8_t>& t_out_range, BitmapCoreHeader& t_out_coreheader)
		{
			std::vector<char> buffer;
			try {
				buffer = FileLoader::readFile(t_filename.data());
			}
			catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				return;
			}

			if (buffer.size() < 30) {
				std::cerr << "File deemed invalid - too short!" << std::endl;
				return;
			}

			BitmapFileHeader fileheader = getFileHeader(buffer.data());

			if (checkSignature(fileheader.type) == false) {
				std::cerr << "Signature-test failed!" << std::endl;
				return;
			}

			BitmapCoreHeader coreheader = getCoreHeader(buffer.data());
			t_out_coreheader = coreheader;

			//check if the file is complete
			int min_filesize = coreheader.width * coreheader.height * (coreheader.bits_per_pixel / 8) + fileheader.off_bits;
			if (buffer.size() < min_filesize) {
				std::cerr << "File deemed invalid - to short for the given dimensions!" << std::endl;
				return;
			}

			fillPixelArray(buffer.data(), t_out_range, fileheader.off_bits, coreheader);
		}

		constexpr bool checkSignature(const std::uint16_t& t_type)
		{
			char charA = *((char*)&t_type);
			char charB = *(((char*)&t_type) + 1);

			return charA == 'B' && charB == 'M';
		}

		const BitmapFileHeader getFileHeader(char* t_data_ptr)
		{
			BitmapFileHeader header;
			std::memcpy(&header.type, t_data_ptr, 2);
			std::memcpy(&header.size, t_data_ptr + 2, 4);
			std::memcpy(&header.reserved, t_data_ptr + 6, 4);
			std::memcpy(&header.off_bits, t_data_ptr + 10, 4);

			return header;
		}

		const BitmapCoreHeader getCoreHeader(char* t_data_ptr)
		{
			BitmapCoreHeader header;
			std::memcpy(&header, t_data_ptr + 14, 16);

			return header;
		}

		void fillPixelArray(char* t_data_ptr, std::vector<std::uint8_t>& t_out_range,
			const std::uint32_t& t_off_bits, const BitmapCoreHeader& t_coreheader)
		{
			std::int8_t bytePerPixel = t_coreheader.bits_per_pixel / 8;
			std::int8_t padding = t_coreheader.width % 4;

			//bool hasAlpha = bytePerPixel == 4;

			t_out_range.resize((std::size_t)t_coreheader.width * t_coreheader.height * bytePerPixel);

			int pixelIndex = 0;
			std::size_t outIndex = 0;

			//iterate from the bottom to the top
			for (std::int32_t h = t_coreheader.height - 1; h >= 0; h--) {
				//iterate from the left to the right
				for (std::int32_t w = 0; w < t_coreheader.width; w++) {
					//the index relative to the two current 2D position in the image-matrix
					std::int32_t positionIndex = (h * t_coreheader.width + w) * bytePerPixel + h * padding;

					char* pixelPtr = &t_data_ptr[t_off_bits + positionIndex];

					//add the components of the pixel [r,g,b,(a)] to the outRange
					for (std::int8_t byte = 0; byte < bytePerPixel; byte++) {
						t_out_range[outIndex] = (std::uint8_t)pixelPtr[byte];
						outIndex = outIndex + 1;
					}
				}
			}
		}

	}
}