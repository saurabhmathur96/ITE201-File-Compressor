//LZWGlobals.hpp
#ifndef __LZWGLOBALS_H_INCLUDED__
#define __LZWGLOBALS_H_INCLUDED__


#include <cstdint>
#include <cstdlib>
#include <limits>


using CodeType=std::uint16_t; 


namespace globals {

/// Dictionary Maximum Size (when reached, the dictionary will be reset)
extern const CodeType dms; 

}


#endif
