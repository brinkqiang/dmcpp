
#include "dmcpp.h"

int main( int argc, char* argv[] ) {

    Idmcpp* module = dmcppGetModule();
    if (module)
    {
        module->Test();
        module->Release();
    }
    return 0;
}
