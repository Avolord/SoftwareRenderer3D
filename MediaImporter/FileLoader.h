#pragma once
#include <vector>
#include "Exceptions.h"

namespace sr {

	namespace FileLoader{

		std::vector<char> readFile(const char* t_filename);

	}

}