git:

git submodule add https://github.com...

_____________________________________________

CMakeLists.txt

add_subdirectory(ConsoleHelper)
...
include_directories(ConsoleHelper/include)
_____________________________________________

Example:

#include "helper.h"

int main(int, char **)
{
    hlp::enable_virtal_console();
    hlp::color_println("Hello world!", hlp::ccolor::red);

    return 0;
}
_____________________________________________
Output:
Hello World!
