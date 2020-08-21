#pragma once
#include "BitmapLoader.h"

namespace sr {
	class Bitmap
	{
	public:
		explicit Bitmap();
		explicit Bitmap(const std::int32_t t_width, const std::int32_t t_height, const bool t_has_alpha = false);
		virtual ~Bitmap();

		void loadFromFile(std::string_view t_filename);

		const bool hasAlpha() const;
		const std::int32_t getHeight() const;
		const std::int32_t getWidth() const;
		const std::vector<std::uint8_t>& getData() const;
		std::vector<std::uint8_t>& getData();

	private:
		std::vector<std::uint8_t> m_data{ };
		std::int32_t m_width{ 0 };
		std::int32_t m_height{ 0 };
		bool m_alpha{ false };
	};
}