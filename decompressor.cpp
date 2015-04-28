#include "decompressor.h"

using namespace std;

Decompressor::Decompressor(string input_file, string output_file)
{
	 input_stream.open(input_file, ios_base::binary);
  output_stream.open(output_file, ios_base::binary);
}

Decompressor::~Decompressor()
{
	input_stream.close();
	output_stream.close();
}

void Decompressor :: reset_dictionary()
{
	const long int minc = numeric_limits<char>::min();
    const long int maxc = numeric_limits<char>::max();

	dictionary.clear();


    dictionary.reserve(globals::dms);
        for (long int c = minc; c <= maxc; ++c)
            {
            	dictionary.push_back({static_cast<char> (c)});
            }
}

void Decompressor::decompress()
{
    reset_dictionary();

    vector<vector<char>> dictionary;
    vector<char> s;
    CodeType k;

    while (is.read(reinterpret_cast<char *> (&k), sizeof (CodeType)))
    {

        if (dictionary.size() == globals::dms)
            reset_dictionary();

        if (k > dictionary.size())
            throw runtime_error("invalid compressed code");

        if (k == dictionary.size())
            dictionary.push_back(s + s.front());
        else
        if (!s.empty())
            dictionary.push_back(s + dictionary.at(k).front());

        os.write(&dictionary.at(k).front(), dictionary.at(k).size());
        s = dictionary.at(k);
    }

    if (!is.eof() || is.gcount() != 0)
        throw runtime_error("corrupted compressed file");
}
}
