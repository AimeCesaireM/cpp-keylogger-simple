#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cassert>

using namespace std;

#define LOG_FILE "test.txt"

// Mock function to simulate saving data to a file.
void saveDataTest(string data) {
    fstream file;
    file.open(LOG_FILE, ios::app);
    file << data;
    file.close();
}

// Function to clear the log file for a clean test slate.
void clearLogFile() {
    fstream file;
    file.open(LOG_FILE, ios::out | ios::trunc);
    file.close();
}

// Function to read the log file and verify contents.
string readLogFile() {
    fstream file;
    string data, line;

    file.open(LOG_FILE, ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            data += line;
        }
        file.close();
    }
    return data;
}

void testKeyLogging() {
    // Clear previous test data.
    clearLogFile();

    // Simulated input data and expected output.
    map<int, string> testInputs = {
        {32, " "},  // Space
        {13, "\n"}, // Enter
        {8, "[BACKSPACE]"},
        {9, "[TAB]"},
        {65, "A"}, // Uppercase 'A'
        {97, "a"}  // Lowercase 'a'
    };

    // Test special keys.
    saveDataTest(testInputs[32]); // Space
    saveDataTest(testInputs[13]); // Enter
    saveDataTest(testInputs[8]);  // Backspace
    saveDataTest(testInputs[9]);  // Tab

    // Test alphanumeric keys.
    saveDataTest(testInputs[65]); // 'A'
    saveDataTest(testInputs[97]); // 'a'

    // Read log and verify contents.
    string expected = " \n[BACKSPACE][TAB]Aa";
    string actual = readLogFile();
    assert(expected == actual);

    cout << "All tests passed successfully." << endl;
}

int main() {
    cout << "Starting KeyLogger Tests..." << endl;

    testKeyLogging();

    return 0;
}
