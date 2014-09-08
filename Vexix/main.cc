#include "CApplication.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main(int argc, char **argv) {
    auto result = g_application.OnExecute();
    _CrtDumpMemoryLeaks();
    return result;
}