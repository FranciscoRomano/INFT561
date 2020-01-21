#include "Win32.ConsoleBuffer.h"

WINCALL void WINAPI Win32::AllocConsoleBuffer(const COORD& size, ConsoleBuffer* buffer)
{
    UINT length = UINT(max(size.X, 0)) * UINT(max(size.Y, 0));

    // set defaults
    buffer->writeSize = size;
    buffer->writeCoord = { 0, 0 };
    buffer->writeRegion = { 0, 0, SHORT(size.X - 1), SHORT(size.Y - 1) };

    // allocate char buffer
    buffer->pCharInfo = length ? new CHAR_INFO[length] : nullptr;
}

WINCALL void WINAPI Win32::FreeConsoleBuffer(ConsoleBuffer* buffer)
{
    // free char buffer
    if (buffer->pCharInfo) delete[] buffer->pCharInfo;

    // clear buffer
    *buffer = {};
}

WINCALL void WINAPI Win32::SetConsoleBufferAttributes(ConsoleBuffer* buffer, const UINT& index, const WORD& value)
{
    // set char buffer attributes
    buffer->pCharInfo[index].Attributes = value;
}

WINCALL void WINAPI Win32::SetConsoleBufferBackground(ConsoleBuffer* buffer, const UINT& index, const CHAR& value)
{
    // set char buffer background attribute
    buffer->pCharInfo[index].Attributes = buffer->pCharInfo[index].Attributes & 0x0f | (value << 4);
}

WINCALL void WINAPI Win32::SetConsoleBufferCharacterA(ConsoleBuffer* buffer, const UINT& index, const CHAR& value)
{
    // set char buffer ascii character
    buffer->pCharInfo[index].Char.AsciiChar = value;
}

WINCALL void WINAPI Win32::SetConsoleBufferCharacterW(ConsoleBuffer* buffer, const UINT& index, const WCHAR& value)
{
    // set char buffer unicode character
    buffer->pCharInfo[index].Char.UnicodeChar = value;
}

WINCALL void WINAPI Win32::SetConsoleBufferCharInfo(ConsoleBuffer* buffer, const UINT& index, const CHAR_INFO& value)
{
    // set char buffer data
    buffer->pCharInfo[index] = value;
}

WINCALL void WINAPI Win32::SetConsoleBufferForeground(ConsoleBuffer* buffer, const UINT& index, const CHAR& value)
{
    // set char buffer foreground attribute
    buffer->pCharInfo[index].Attributes = buffer->pCharInfo[index].Attributes & 0xf0 | value;
}

WINCALL void WINAPI Win32::WriteConsoleBufferA(ConsoleInstance* instance, ConsoleBuffer* buffer)
{
    // write console buffer ascii characters
    WriteConsoleOutputA(instance->hOut, buffer->pCharInfo, buffer->writeSize, buffer->writeCoord, &buffer->writeRegion);
}

WINCALL void WINAPI Win32::WriteConsoleBufferW(ConsoleInstance* instance, ConsoleBuffer* buffer)
{
    // write console buffer unicode characters
    WriteConsoleOutputW(instance->hOut, buffer->pCharInfo, buffer->writeSize, buffer->writeCoord, &buffer->writeRegion);
}