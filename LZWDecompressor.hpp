//LZWDecompressor.hpp
#ifndef __LZWDECOMPRESSOR_H_INCLUDED__
#define __LZWDECOMPRESSOR_H_INCLUDED__

#include "LZWGlobals.hpp"

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




class LZWDecompressor
{
public:
	LZWDecompressor(std::ifstream &inputFile, std::ofstream &outputFile);
	void decompress();
private:
	std::ifstream *in;
	std::ofstream *out;
	std::vector<std::vector<char>> dictionary;
	void inline reset_dictionary();
};

#endif
