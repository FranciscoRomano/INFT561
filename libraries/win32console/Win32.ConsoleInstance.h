#pragma once

#ifndef WINCALL
#define WINCALL __declspec(dllexport)
#endif//WINCALL

#include <Windows.h>

namespace Win32
{
    /// <summary> [win32] console focus event callback </summary>
    typedef void (*PFN_ConsoleFocusEvent)(FOCUS_EVENT_RECORD);

    /// <summary> [win32] console key event callback </summary>
    typedef void (*PFN_ConsoleKeyEvent)(KEY_EVENT_RECORD);

    /// <summary> [win32] console menu event callback </summary>
    typedef void (*PFN_ConsoleMenuEvent)(MENU_EVENT_RECORD);

    /// <summary> [win32] console mouse event callback </summary>
    typedef void (*PFN_ConsoleMouseEvent)(MOUSE_EVENT_RECORD);

    /// <summary> [win32] console resize event callback </summary>
    typedef void (*PFN_ConsoleResizeEvent)(WINDOW_BUFFER_SIZE_RECORD);

    /// <summary> [win32] console instance handle </summary>
    typedef struct ConsoleInstance {
        HANDLE                           hIn;                // input handle
        HANDLE                           hOut;               // output handle
        HWND                             hWnd;               // window handle
        PFN_ConsoleFocusEvent            pfnFocusEvent;      // focus event callback
        PFN_ConsoleKeyEvent              pfnKeyEvent;        // key event callback
        PFN_ConsoleMenuEvent             pfnMenuEvent;       // menu event callback
        PFN_ConsoleMouseEvent            pfnMouseEvent;      // mouse event callback
        PFN_ConsoleResizeEvent           pfnResizeEvent;     // resize event callback
    } ConsoleInstance;

    /// <summary> [win32] bind console focus event callback to instance </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="callback"> function pointer </param>
    WINCALL void WINAPI BindConsoleInstanceFocusEvent(ConsoleInstance* instance, PFN_ConsoleFocusEvent callback);

    /// <summary> [win32] bind console key event callback to instance </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="callback"> function pointer </param>
    WINCALL void WINAPI BindConsoleInstanceKeyEvent(ConsoleInstance* instance, PFN_ConsoleKeyEvent callback);

    /// <summary> [win32] bind console menu event callback to instance </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="callback"> function pointer </param>
    WINCALL void WINAPI BindConsoleInstanceMenuEvent(ConsoleInstance* instance, PFN_ConsoleMenuEvent callback);

    /// <summary> [win32] bind console mouse event callback to instance </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="callback"> function pointer </param>
    WINCALL void WINAPI BindConsoleInstanceMouseEvent(ConsoleInstance* instance, PFN_ConsoleMouseEvent callback);

    /// <summary> [win32] bind console resize event callback to instance </summary>
    /// <param name="instance"> instance pointer </param>
    /// <param name="callback"> function pointer </param>
    WINCALL void WINAPI BindConsoleInstanceResizeEvent(ConsoleInstance* instance, PFN_ConsoleResizeEvent callback);

    /// <summary> [win32] get console instance </summary>
    /// <param name="instance"> instance pointer </param>
    WINCALL void WINAPI GetConsoleInstance(ConsoleInstance* instance);

    /// <summary> [win32] read console instance input events </summary>
    /// <param name="instance"> instance pointer </param>
    WINCALL void WINAPI ReadConsoleInstanceEvents(ConsoleInstance* instance);
}