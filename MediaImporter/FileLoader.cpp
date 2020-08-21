#include "FileLoader.h"
#include <fstream>
#include <sys/stat.h>

namespace sr {

	namespace FileLoader {

		inline std::size_t getFileSize(std::ifstream& t_input_file_stream)
		{
			t_input_file_stream.seekg(0, std::ios_base::end);
			std::size_t size = (size_t)t_input_file_stream.tellg();
			t_input_file_stream.seekg(0, std::ios_base::beg);

			return size;
		}

		inline bool fileExists(const char* t_filename) {
			struct stat buffer;
			return (stat(t_filename, &buffer) == 0);
		}

		std::vector<char> readFile(const char* t_filename)
		{
			if (fileExists(t_filename) == false) {
				throw Exceptions::invalid_filename();
			}

			//load file to stream
			std::ifstream is(t_filename);

			//get size of the file
			std::size_t size = getFileSize(is);

			if (size == 0) {
				throw Exceptions::empty_file();
			}

			//prepare buffer
			std::vector<char> buffer(size);

			//read the file into the buffer
			is.read(&buffer[0], size);

			//close the stream
			is.close();

			return buffer;
		}

	}

}