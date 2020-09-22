
#include "dmfile.h"
#include <iostream>

int main()
{
    std::string strFileName = __FILE__;
    std::string s = DMLoadFile(strFileName);
    std::cout << s << std::endl;

    DMWriteFile(strFileName+ std::string(".TMP"), s);
    return 0;
}