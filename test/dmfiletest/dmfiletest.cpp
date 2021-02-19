
#include "dmfile.h"
#include <iostream>
#include "gtest.h"

TEST(dmfiletest,dmfiletest )
{
    std::string strFileName = __FILE__;
    std::string s = DMLoadFile(strFileName);
    std::cout << s << std::endl;

    DMWriteFile(strFileName+ std::string(".TMP"), s);
}