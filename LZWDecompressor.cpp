#include "LZWDecompressor.hpp"


std::vector<char> operator + (std::vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}


LZWDecompressor::LZWDecompressor(std::ifstream &inputFile, std::ofstream &outputFile)
{
	in = &inputFile;
	out = &outputFile;
}


void LZWDecompressor::reset_dictionary()
{
	dictionary.clear();
    dictionary.reserve(globals::dms);

    const long int minc = std::numeric_limits<char>::min();
    const long int maxc = std::numeric_limits<char>::max();

    for (long int c = minc; c <= maxc; ++c)
    	dictionary.push_back({static_cast<char> (c)});
}


void LZWDecompressor::decompress()
{
	reset_dictionary();

    std::vector<char> s; // String
    CodeType k; // Key

    while (in->read(reinterpret_cast<char *> (&k), sizeof (CodeType)))
    {
        // dictionary's maximum size was reached
        if (dictionary.size() == globals::dms)
            reset_dictionary();

        if (k > dictionary.size())
            throw std::runtime_error("invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else
        if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        //std::cout << dictionary.at(k).front();
        out->write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!in->eof() || in->gcount() != 0)
        throw std::runtime_error("corrupted compressed file");

}
