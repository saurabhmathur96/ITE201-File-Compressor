#include "compressor.h"

using namespace std;

Compressor::Compressor(string input_file, string output_file)
{
  input_stream.open(input_file, ios_base::binary);
  output_stream.open(output_file, ios_base::binary);
}

Compressor::~Compressor()
{
  input_stream.close();
  output_stream.close();
}

void Compressor::reset_dictionary()
{
  dictionary.clear();
  const long int minc = numeric_limits<char>::min();
  const long int maxc = numeric_limits<char>::max();
  
  for (long int c = minc; c <= maxc; ++c)
  {
    const CodeType dictionary_size = dictionary.size();
    dictionary[{static_cast<char> (c)}] = dictionary_size;
  }
}

void Compressor::compress()
{
  reset_dictionary();
  
  vector<char> str;
  char c;
  while(input_stream.get(c))
  {
    if (dictionary.size() == globals::dms)
    {
      reset_dictionary();
    }
    
    str.push_back(c);
    
    if (dictionary.count(str) == 0)
    {
      const CodeType dictionary_size = dictionary.size();
      
      dictionary[str]  = dictionary.size();
      str.pop_back();
      output_stream.write(reinterpret_cast<const char *> (&dictionary.at(str)), sizeof (CodeType));
      str = {c};
      
    }
  }
  if (!str.empty())
  {
    output_stream.write(reinterpret_cast<const char *> (&dictionary.at(str)), sizeof (CodeType));
  }
}

