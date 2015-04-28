#define CONFIGUTILS_H

using CodeType = std::uint16_t;

namespace globals {

const CodeType dms {std::numeric_limits<CodeType>::max()};



std::vector<char> operator + (std::vector<char> vc, char c)
{
    vc.push_back(c);
    return vc;
}

#endif

