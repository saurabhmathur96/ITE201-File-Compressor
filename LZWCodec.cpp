//LZWCodec.cpp
#include "LZWCodec.hpp"


LZWCodec::LZWCodec(std::ifstream &inputFile, std::ofstream &outputFile)
:LZWCompressor(inputFile, outputFile), LZWDecompressor(inputFile, outputFile){}

void LZWCodec::encode(LZWMode mode)
{
	if(mode == LZWMode::COMPRESS)
		compress();
	else if(mode == LZWMode::DECOMPRESS)
		decompress();
	else
		throw std::runtime_error("invalid mode");
}
