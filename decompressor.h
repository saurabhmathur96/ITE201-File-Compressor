#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <cstdint>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <limits>
#include <map>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "ConfigUtils.h"

using namespace std;

class Decompressor
{

  private:

    void reset_dictionary(vector<vector<char>> &dictionary);
    vector<vector<char>>, CodeType> dictionary;
    ofstream output_stream;
    ifstream input_stream;

  public:

    Decompressor(string input_file,string output_file);
    void decompress();
    ~Decompressor();

};


#endif
