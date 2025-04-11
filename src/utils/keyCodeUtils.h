#ifndef ENGINE_KEYCODE_UTILS_H
#define ENGINE_KEYCODE_UTILS_H

#include <string>
#include <sstream>
#include "KeyCodes.h"

inline std::string KeyCodeToString(int keycode)
{
    switch (keycode)
    {
        // Alfabeto
        case ENGINE_KEY_A: return "A";
        case ENGINE_KEY_B: return "B";
        case ENGINE_KEY_C: return "C";
        case ENGINE_KEY_D: return "D";
        case ENGINE_KEY_E: return "E";
        case ENGINE_KEY_F: return "F";
        case ENGINE_KEY_G: return "G";
        case ENGINE_KEY_H: return "H";
        case ENGINE_KEY_I: return "I";
        case ENGINE_KEY_J: return "J";
        case ENGINE_KEY_K: return "K";
        case ENGINE_KEY_L: return "L";
        case ENGINE_KEY_M: return "M";
        case ENGINE_KEY_N: return "N";
        case ENGINE_KEY_O: return "O";
        case ENGINE_KEY_P: return "P";
        case ENGINE_KEY_Q: return "Q";
        case ENGINE_KEY_R: return "R";
        case ENGINE_KEY_S: return "S";
        case ENGINE_KEY_T: return "T";
        case ENGINE_KEY_U: return "U";
        case ENGINE_KEY_V: return "V";
        case ENGINE_KEY_W: return "W";
        case ENGINE_KEY_X: return "X";
        case ENGINE_KEY_Y: return "Y";
        case ENGINE_KEY_Z: return "Z";

        // Números
        case ENGINE_KEY_0: return "0";
        case ENGINE_KEY_1: return "1";
        case ENGINE_KEY_2: return "2";
        case ENGINE_KEY_3: return "3";
        case ENGINE_KEY_4: return "4";
        case ENGINE_KEY_5: return "5";
        case ENGINE_KEY_6: return "6";
        case ENGINE_KEY_7: return "7";
        case ENGINE_KEY_8: return "8";
        case ENGINE_KEY_9: return "9";

        // Pontuação
        case ENGINE_KEY_SPACE: return "Space";
        case ENGINE_KEY_APOSTROPHE: return "'";
        case ENGINE_KEY_COMMA: return ",";
        case ENGINE_KEY_MINUS: return "-";
        case ENGINE_KEY_PERIOD: return ".";
        case ENGINE_KEY_SLASH: return "/";
        case ENGINE_KEY_SEMICOLON: return ";";
        case ENGINE_KEY_EQUAL: return "=";
        case ENGINE_KEY_LEFT_BRACKET: return "[";
        case ENGINE_KEY_BACKSLASH: return "\\";
        case ENGINE_KEY_RIGHT_BRACKET: return "]";
        case ENGINE_KEY_GRAVE_ACCENT: return "`";

        // Especiais
        case ENGINE_KEY_ENTER: return "Enter";
        case ENGINE_KEY_TAB: return "Tab";
        case ENGINE_KEY_BACKSPACE: return "Backspace";
        case ENGINE_KEY_ESCAPE: return "Escape";
        case ENGINE_KEY_INSERT: return "Insert";
        case ENGINE_KEY_DELETE: return "Delete";
        case ENGINE_KEY_HOME: return "Home";
        case ENGINE_KEY_END: return "End";
        case ENGINE_KEY_PAGE_UP: return "Page Up";
        case ENGINE_KEY_PAGE_DOWN: return "Page Down";
        case ENGINE_KEY_CAPS_LOCK: return "Caps Lock";
        case ENGINE_KEY_SCROLL_LOCK: return "Scroll Lock";
        case ENGINE_KEY_NUM_LOCK: return "Num Lock";
        case ENGINE_KEY_PRINT_SCREEN: return "Print Screen";
        case ENGINE_KEY_PAUSE: return "Pause";

        // Setas
        case ENGINE_KEY_LEFT: return "Arrow Left";
        case ENGINE_KEY_RIGHT: return "Arrow Right";
        case ENGINE_KEY_UP: return "Arrow Up";
        case ENGINE_KEY_DOWN: return "Arrow Down";

        // F1–F25
        case ENGINE_KEY_F1: return "F1";
        case ENGINE_KEY_F2: return "F2";
        case ENGINE_KEY_F3: return "F3";
        case ENGINE_KEY_F4: return "F4";
        case ENGINE_KEY_F5: return "F5";
        case ENGINE_KEY_F6: return "F6";
        case ENGINE_KEY_F7: return "F7";
        case ENGINE_KEY_F8: return "F8";
        case ENGINE_KEY_F9: return "F9";
        case ENGINE_KEY_F10: return "F10";
        case ENGINE_KEY_F11: return "F11";
        case ENGINE_KEY_F12: return "F12";
        case ENGINE_KEY_F13: return "F13";
        case ENGINE_KEY_F14: return "F14";
        case ENGINE_KEY_F15: return "F15";
        case ENGINE_KEY_F16: return "F16";
        case ENGINE_KEY_F17: return "F17";
        case ENGINE_KEY_F18: return "F18";
        case ENGINE_KEY_F19: return "F19";
        case ENGINE_KEY_F20: return "F20";
        case ENGINE_KEY_F21: return "F21";
        case ENGINE_KEY_F22: return "F22";
        case ENGINE_KEY_F23: return "F23";
        case ENGINE_KEY_F24: return "F24";
        case ENGINE_KEY_F25: return "F25";

        // Teclado numérico
        case ENGINE_KEY_KP_0: return "NumPad 0";
        case ENGINE_KEY_KP_1: return "NumPad 1";
        case ENGINE_KEY_KP_2: return "NumPad 2";
        case ENGINE_KEY_KP_3: return "NumPad 3";
        case ENGINE_KEY_KP_4: return "NumPad 4";
        case ENGINE_KEY_KP_5: return "NumPad 5";
        case ENGINE_KEY_KP_6: return "NumPad 6";
        case ENGINE_KEY_KP_7: return "NumPad 7";
        case ENGINE_KEY_KP_8: return "NumPad 8";
        case ENGINE_KEY_KP_9: return "NumPad 9";
        case ENGINE_KEY_KP_DECIMAL: return "NumPad .";
        case ENGINE_KEY_KP_DIVIDE: return "NumPad /";
        case ENGINE_KEY_KP_MULTIPLY: return "NumPad *";
        case ENGINE_KEY_KP_SUBTRACT: return "NumPad -";
        case ENGINE_KEY_KP_ADD: return "NumPad +";
        case ENGINE_KEY_KP_ENTER: return "NumPad Enter";
        case ENGINE_KEY_KP_EQUAL: return "NumPad =";

        // Modificadores
        case ENGINE_KEY_LEFT_SHIFT: return "Left Shift";
        case ENGINE_KEY_RIGHT_SHIFT: return "Right Shift";
        case ENGINE_KEY_LEFT_CONTROL: return "Left Ctrl";
        case ENGINE_KEY_RIGHT_CONTROL: return "Right Ctrl";
        case ENGINE_KEY_LEFT_ALT: return "Left Alt";
        case ENGINE_KEY_RIGHT_ALT: return "Right Alt";
        case ENGINE_KEY_LEFT_SUPER: return "Left Super";
        case ENGINE_KEY_RIGHT_SUPER: return "Right Super";
        case ENGINE_KEY_MENU: return "Menu";

        default:
            return "Unknown(" + std::to_string(keycode) + ")";
    }
}

#endif // ENGINE_KEYCODE_UTILS_H
