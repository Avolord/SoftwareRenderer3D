#include "Bitmap.h"

namespace sr {
	Bitmap::Bitmap()
	{
	}

	Bitmap::Bitmap(const std::int32_t t_width, const std::int32_t t_height, const bool t_has_alpha)
		: m_width(t_width), m_height(t_height), m_alpha(t_has_alpha)
	{
		size_t bytes_per_pixel = t_has_alpha ? 4 : 3;
		m_data.resize((size_t)t_width * (size_t)t_height * bytes_per_pixel);
	}

	Bitmap::~Bitmap()
	{
	}

	void Bitmap::loadFromFile(std::string_view t_filename)
	{
		BitmapCoreHeader core_header;

		BitmapLoader::loadBitmapFromFile(t_filename, this->m_data, core_header);
		this->m_width = core_header.width;
		this->m_height = core_header.height;
		this->m_alpha = (core_header.bits_per_pixel / 8) == 4;
	}

	const std::vector<std::uint8_t>& Bitmap::getData() const
	{
		return m_data;
	}

	std::vector<std::uint8_t>& Bitmap::getData()
	{
		return m_data;
	}

	const std::int32_t Bitmap::getHeight() const
	{
		return m_height;
	}

	const std::int32_t Bitmap::getWidth() const
	{
		return m_width;
	}

	const bool Bitmap::hasAlpha() const
	{
		return m_alpha;
	}
}