void _printf(const char* s, ...)
{
    va_list args;
    va_start(args, s);
    int n = vsnprintf(NULL, 0, s, args);
    char* str = new char[n + 1];
    vsprintf(str, s, args);
    va_end(args);
    Serial.print(str);
    delete[] str;
}