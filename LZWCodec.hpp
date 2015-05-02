//LZWCodec.hpp
#ifndef __LZWCODEC_H_INCLUDED__
#define __LZWCODEC_H_INCLUDED__

#include "LZWCompressor.hpp"
#include "LZWDecompressor.hpp"

#include <exception>
#include <stdexcept>

enum class LZWMode{COMPRESS, DECOMPRESS};

class LZWCodec:public LZWCompressor, public LZWDecompressor
{
public:
	LZWCodec(std::ifstream &inputFile, std::ofstream &outputFile);
	void encode(LZWMode mode);
};

#endif
