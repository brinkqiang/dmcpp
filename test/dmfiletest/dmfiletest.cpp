
#include "dmfile.h"

int main() {
    std::string s = DMLoadFile(__FILE__);
    std::cout << s << std::endl;
    return 0;
}