# KeyLogger Project

## Overview

This project is a simple keylogging tool built using C++. It records keyboard inputs, including special keys, and stores them in a log file for analysis. The program operates in the background, making it an effective demonstration of how keylogging techniques work.

**Important Disclaimer**:  
This project is for educational and research purposes only. Unauthorized use of keylogging software is illegal and unethical. Ensure you have explicit permission before deploying this software on any system.

---

## Features

- Captures alphanumeric key inputs.
- Tracks special keys such as Shift, Ctrl, Caps Lock, and Tab.
- Saves recorded keys into a log file (`keylog.txt`) for offline review.
- Runs in the background, hiding the console window upon execution.
- Demonstrates interaction with the Windows API for real-time input capture.

---

## Requirements

- **Operating System**: Windows (due to dependency on the Windows API).
- **Compiler**: A C++ compiler that supports Windows API (e.g., MinGW, Visual Studio).
- **Libraries**: Standard C++ libraries and Windows headers.

---

## Setup and Usage

1. **Compilation**:  
   Use a Windows-compatible C++ compiler to compile the program.
   ```bash
   g++ KeyLogger.cpp -o KeyLogger.exe
   ```

2. **Execution**:  
   Run the executable:
   ```bash
   KeyLogger.exe
   ```

   The program will start logging key inputs to the `keylog.txt` file and hide the console window.

3. **Log File**:  
   Open `keylog.txt` to review the logged keys.

---

## Key Features Breakdown

- **Keyboard Input Logging**:  
  Detects and logs key presses using the Windows `GetAsyncKeyState` function.
  
- **Special Key Handling**:  
  Maps common special keys (e.g., Tab, Shift, Ctrl) to human-readable labels.

- **Case Sensitivity**:  
  Differentiates between uppercase and lowercase characters based on the Caps Lock state and Shift key usage.

- **Background Execution**:  
  Uses the `ShowWindow` function to hide the console window, making the program inconspicuous.

---

## Ethical Considerations

This project serves as a learning tool to understand keylogging techniques and system-level programming. Unauthorized use of such software can violate privacy laws and ethical standards. Always operate within the boundaries of legality and ethical guidelines.

---

## Future Improvements

- Add encryption to the log file for secure storage.
- Implement a configuration file to allow customization of logging behavior.
- Extend compatibility to other operating systems.
- Integrate stealth features responsibly for ethical penetration testing.

---

## Disclaimer

This software is provided "as is," without warranty of any kind. The developer is not responsible for any misuse of this tool. Always use responsibly and with explicit permission.

--- 
