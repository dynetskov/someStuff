#include "init.h"

int main()
{
    try
    {
        initGame();
    }
    catch (std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
    }

    return 0;
}
