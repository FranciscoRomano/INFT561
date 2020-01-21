#include "Win32.ConsoleInstance.h"

void empty_callback(FOCUS_EVENT_RECORD) {}
void empty_callback(KEY_EVENT_RECORD) {}
void empty_callback(MENU_EVENT_RECORD) {}
void empty_callback(MOUSE_EVENT_RECORD) {}
void empty_callback(WINDOW_BUFFER_SIZE_RECORD) {}

WINCALL void WINAPI Win32::BindConsoleInstanceFocusEvent(ConsoleInstance* instance, PFN_ConsoleFocusEvent callback)
{
    // set focus event callback
    instance->pfnFocusEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceKeyEvent(ConsoleInstance* instance, PFN_ConsoleKeyEvent callback)
{
    // set key event callback
    instance->pfnKeyEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceMenuEvent(ConsoleInstance* instance, PFN_ConsoleMenuEvent callback)
{
    // set menu event callback
    instance->pfnMenuEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceMouseEvent(ConsoleInstance* instance, PFN_ConsoleMouseEvent callback)
{
    // set mouse event callback
    instance->pfnMouseEvent = callback;
}

WINCALL void WINAPI Win32::BindConsoleInstanceResizeEvent(ConsoleInstance* instance, PFN_ConsoleResizeEvent callback)
{
    // set resize event callback
    instance->pfnResizeEvent = callback;
}

WINCALL void WINAPI Win32::GetConsoleInstance(ConsoleInstance* instance)
{
    // set defaults
    instance->hIn = GetStdHandle(STD_OUTPUT_HANDLE);
    instance->hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    instance->hWnd = GetConsoleWindow();
    instance->pfnFocusEvent = empty_callback;
    instance->pfnKeyEvent = empty_callback;
    instance->pfnMenuEvent = empty_callback;
    instance->pfnMouseEvent = empty_callback;
    instance->pfnResizeEvent = empty_callback;
}

WINCALL void WINAPI Win32::ReadConsoleInstanceEvents(ConsoleInstance* instance)
{
    static DWORD i;
    static DWORD length;
    static INPUT_RECORD ibuffer[128];

    // check if console events available
    if (ReadConsoleInputA(instance->hIn, ibuffer, 128, &length))
    {
        // iterate through each event
        for (i = 0; i < length; i++)
        {
            // check console event type
            switch (ibuffer[i].EventType)
            {
                // handle focus event
                case FOCUS_EVENT:
                    instance->pfnFocusEvent(ibuffer[i].Event.FocusEvent);
                    break;
                // handle key event
                case KEY_EVENT:
                    instance->pfnKeyEvent(ibuffer[i].Event.KeyEvent);
                    break;
                // handle menu event
                case MENU_EVENT:
                    instance->pfnMenuEvent(ibuffer[i].Event.MenuEvent);
                    break;
                // handle mouse event
                case MOUSE_EVENT:
                    instance->pfnMouseEvent(ibuffer[i].Event.MouseEvent);
                    break;
                // handle window buffer size event
                case WINDOW_BUFFER_SIZE_EVENT:
                    instance->pfnResizeEvent(ibuffer[i].Event.WindowBufferSizeEvent);
                    break;
                default:
                    break;
            }
        }
    }
}