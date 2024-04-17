git:

git submodule add https://github.com/potoshopDev/ConsoleHelper.git

_____________________________________________

CMakeLists.txt


add_subdirectory(ConsoleHelper)   ...   include_directories(ConsoleHelper/include)
_____________________________________________

Example:
```cpp
#include "helper.h"

int main(int, char **)
{
    hlp::enable_virtual_console();
    hlp::color_println("Hello world!", hlp::ccolor::red);

    return 0;
}
_____________________________________________
Output:
Hello World!
