#ifndef CCN_GLOBAL_H
#define CCN_GLOBAL_H

#include <Python.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef _MSC_VER
// Alias para las funciones MinGW
int __mingw_vsscanf(const char* str, const char* format, va_list ap)
{
    return vsscanf(str, format, ap);
}

int __mingw_vfprintf(FILE* stream, const char* format, va_list ap)
{
    return vfprintf(stream, format, ap);
}

int __mingw_vsnprintf(char* buffer, size_t count, const char* format, va_list ap)
{
    return vsnprintf(buffer, count, format, ap);
}

int __mingw_vsprintf(char* buffer, const char* format, va_list ap)
{
    return vsprintf(buffer, format, ap);
}
// son necesarios si se compila para el VS mezclando el codigo con el byte code generado por mingw
#endif

#define __COLORS_C__
#define __DEBUG_C__
#define __ERROR_C__
#define __TIMER_C__
#define _ExceptionHandler // activar mecanismo de excepciones en el codigo C
#include "../lib/DebugLibC/time_code.h"

#ifdef DEBUG_ENABLE_CCN
#define debug_print_ccn(msg, ...) printf_color("#{FG:lgreen}[#{FG:cyan}%s#{FG:reset}:#{FG:red}%03d#{FG:green}]#{FG:reset} " msg , __FILE__, __LINE__, ##__VA_ARGS__)

#else
#define debug_print_ccn(msg, ...)
#endif

#endif