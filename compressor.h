#ifndef COMPRESSOR_H
#define COMPRESSOR_H

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

class Compressor
{
  
  public:
    Compressor(string input_file, string output_file);
    void compress();
    ~Compressor();
    
  private:
    
    map<vector<char>, CodeType> dictionary;
    ofstream output_stream;
    ifstream input_stream;
    void reset_dictionary();
    
};



#endif
