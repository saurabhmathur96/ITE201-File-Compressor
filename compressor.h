//LZWCompressor.hpp
#ifndef __LZWCOMPRESSOR_H_INCLUDED__
#define __LZWCOMPRESSOR_H_INCLUDED__


#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <ios>
#include <istream>
#include <limits>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

using CodeType=std::uint16_t; 

namespace globals {

/// Dictionary Maximum Size (when reached, the dictionary will be reset)
const CodeType dms {std::numeric_limits<CodeType>::max()};

}


class LZWCompressor
{
public:
	LZWCompressor(std::ifstream &inputFile, std::ofstream &outputFile);
	void compress();
private:
	std::ifstream *in;
	std::ofstream *out;
	std::map<std::vector<char>, CodeType> dictionary;
	void inline reset_dictionary();
};

#endif
