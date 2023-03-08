#ifndef DEBUGPRINTF_HPP
#define DEBUGPRINTF_HPP

#define _DEBUG

void _printf(const char* s, ...);

#ifdef _DEBUG
#define DEBUG_PRINT(str) Serial.print(str)
#define DEBUG_PRINTF(str, ...) _printf(str, __VA_ARGS__)
#define DEBUG_PRINTLN(str) Serial.println(str)
#else
#define DEBUG_PRINT(x)
#define DEBUG_PRINTF(x, format)
#define DEBUG_PRINTLN(x)
#endif

#endif
