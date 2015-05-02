//LZWCompressor.cpp

#include "LZWCompressor.hpp"

LZWCompressor::LZWCompressor(std::ifstream &inputFile, std::ofstream &outputFile)
{
	in = &inputFile;
	out = &outputFile;
}


void LZWCompressor::reset_dictionary()
{

	dictionary.clear();
  	const long int minc = std::numeric_limits<char>::min();
  	const long int maxc = std::numeric_limits<char>::max();
  
	for (long int c = minc; c <= maxc; ++c)
  	{
   		const CodeType dictionary_size = dictionary.size();
   		dictionary[{static_cast<char> (c)}] = dictionary_size;
  	}
}


void LZWCompressor::compress()
{
	reset_dictionary();


	std::vector<char> s;
	char c;

	while(in->get(c))
	{
		if(dictionary.size() == globals::dms)
		{
			reset_dictionary();
		}

		s.push_back(c);

		if(dictionary.count(s) == 0)
		{
			const CodeType dictionary_size = dictionary.size();
			dictionary[s] = dictionary_size;

			s.pop_back();

			out->write(reinterpret_cast<const char *>(&dictionary.at(s)), sizeof(CodeType));

			s = {c};
		}
	}

	if(!s.empty())
	{
		out->write(reinterpret_cast<const char *>(&dictionary.at(s)), sizeof(CodeType));
	}

}
