#include <iostream>
#include <fstream>
#include <exception>
#include <stdexcept>
#include <string>

#include "LZWCodec.hpp"


const std::string USAGE = "\nusage\n"
                          "lzw -flag input_file output_file\n"
                          "where flag is either -c for compress or -d for decompress\n"
                          "and input_file and output_file are distinct files\n\n";

int main(int argc, char *argv[])
{

    if(argc != 4)
    {
        std::cout << "invalid arguments\n"
                  << USAGE;
        return -1;
    }

    LZWMode m;

    if (std::string(argv[1]) == "-c")
        m = LZWMode::COMPRESS;
    else
    if (std::string(argv[1]) == "-d")
        m = LZWMode::DECOMPRESS;

	std::ifstream inFile(argv[2], std::fstream::binary);
	std::ofstream outFile(argv[3], std::fstream::binary);

	if(not inFile.is_open() or not outFile.is_open())
		std::cout << "Files can't be opened !\n";

	try
	{

        inFile.exceptions(std::ios_base::badbit);
        outFile.exceptions(std::ios_base::badbit | std::ios_base::failbit);

        LZWCodec lzw(inFile, outFile);
        lzw.encode(m);
        //LZWDecompressor decompressor(inFile, outFile);
        //decompressor.decompress();
	}

	catch (const std::ios_base::failure &f)
    {
        std::cout << std::string("File input/output failure: ") + f.what() + '.'
                  << USAGE;
        return -1;
    }
    catch (const std::exception &e)
    {
        std::cout << std::string("Caught exception: ") + e.what() + '.'
                  << USAGE;
        return -1;
    }

    inFile.close();
    outFile.close();
    return 0;

}

