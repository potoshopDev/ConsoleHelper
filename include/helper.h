// # need c++ 23
#pragma once

#include <print>
#include <string>
#include <string_view>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace hlp
{
    std::string load_string(unsigned int ID);

    enum class ccolor
    {
        none = 0,
        red,
        green,
        blue,
        yellow,
        magenta,
        cyan,
        white,
    };

    std::string get_color_str(ccolor _clr);
    std::string get_command_end();
    void color_print(std::string_view _str, ccolor _clr = ccolor::none);
    void color_println(std::string_view _str, ccolor _clr = ccolor::none);
    void enable_virtual_console();
    void move_cursor(int _dist);
    void hide_cursor(bool _visible);

    std::string load_string(unsigned int ID)
    {
        auto hInst{GetModuleHandle(nullptr)};
        TCHAR szBuffer[256];

        LoadString(hInst, ID, szBuffer, 256);

        return {szBuffer};
    }

    std::string get_color_str(ccolor _clr)
    {
        switch (_clr)
        {
        case ccolor::none:
            return {""};
            break;
        case ccolor::red:
            return {"\x1b[1;31m"};
            break;
        case ccolor::green:
            return {"\x1b[1;32m"};
            break;
        case ccolor::yellow:
            return {"\x1b[1;33m"};
            break;
        case ccolor::blue:
            return {"\x1b[1;34m"};
            break;
        case ccolor::magenta:
            return {"\x1b[1;35m"};
            break;
        case ccolor::cyan:
            return {"\x1b[1;36m"};
            break;
        case ccolor::white:
            return {"\x1b[1;37m"};
            break;
        }

        return {"\x1b[1;30m"};
    }

    std::string get_command_end()
    {
        return {"\x1b[0m"};
    }

    void color_print(std::string_view _str, ccolor _clr)
    {
        const auto str_color{get_color_str(_clr)};
        const auto str_color_end{get_command_end()};
        std::print("{}{}{}", str_color, _str, str_color_end);
    }

    void color_println(std::string_view _str, ccolor _clr)
    {
        color_print(_str, _clr);
        std::println("");
    }

    void enable_virtual_console()
    {
        auto handle{GetStdHandle(STD_OUTPUT_HANDLE)};
        DWORD dwMode{0};
        GetConsoleMode(handle, &dwMode);
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), dwMode);
    }

    void move_cursor(int _dist)
    {
        std::print("\x1b[{}D{}", _dist, get_command_end());
    }

    void hide_cursor(bool _visible)
    {
        std::print("\x1b[?25{} {}", (_visible ? "l" : "h"), get_command_end());
    }
}