//main.cpp
//Test cases for LZWCompressor.hpp added

#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include "LZWCompressor.hpp"


int main(void)
{

	std::ifstream inFile("data.html", std::fstream::binary);
	std::ofstream outFile("compressed.lzw", std::fstream::binary);

	if(not inFile.is_open() or not outFile.is_open())
		std::cout << "Files can't be opened !\n";

	try
	{

        inFile.exceptions(std::ios_base::badbit);
        outFile.exceptions(std::ios_base::badbit | std::ios_base::failbit);

        LZWCompressor compressor(inFile, outFile);
        compressor.compress();
	}

	catch (const std::ios_base::failure &f)
    {
        std::cout << std::string("File input/output failure: ") + f.what() + '.';
        return -1;
    }
    catch (const std::exception &e)
    {
        std::cout << std::string("Caught exception: ") + e.what() + '.';
        return -1;
    }

    inFile.close();
    outFile.close();
    return 0;

}

