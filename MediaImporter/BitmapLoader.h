#pragma once
#include <string>
#include <string_view>
#include <vector>

namespace sr {
	const struct BitmapCoreHeader {
		std::uint32_t size;
		std::int32_t  width;
		std::int32_t  height;
		std::uint16_t planes;
		std::uint16_t bits_per_pixel;
	};

	const struct BitmapFileHeader {
		std::uint16_t type;
		std::uint32_t size;
		std::uint32_t reserved;
		std::uint32_t off_bits;
	};

	namespace BitmapLoader {

			void loadBitmapFromFile(std::string_view t_filename, std::vector<std::uint8_t>& t_out_range, BitmapCoreHeader& t_out_coreheader);

			constexpr bool checkSignature(const std::uint16_t& t_type);
			const BitmapFileHeader getFileHeader(char* t_data_ptr);
			const BitmapCoreHeader getCoreHeader(char* t_data_ptr);
			void fillPixelArray(char* dataPtr, std::vector<std::uint8_t>& t_out_range,
				const std::uint32_t& t_off_bits, const BitmapCoreHeader& t_coreheader);
	}
}