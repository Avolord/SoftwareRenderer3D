#pragma once
#include <exception>

namespace sr {

	namespace Exceptions {

		const struct invalid_filename : public std::exception {
			const char* what() const throw ()
			{
				return "Invalid Filename!";
			}
		};

		const struct empty_file : public std::exception {
			const char* what() const throw ()
			{
				return "Empty File!";
			}
		};

	}

}

