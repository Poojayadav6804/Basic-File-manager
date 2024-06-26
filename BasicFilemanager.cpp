#include <iostream>
#include <windows.h>

void listFiles(const std::string& path) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((path + "/*").c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            std::cout << findFileData.cFileName << std::endl;
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    }
}

void createDirectory(const std::string& path) {
    if (!CreateDirectory(path.c_str(), NULL)) {
        std::cerr << "Failed to create directory" << std::endl;
    }
}

void copyFile(const std::string& source, const std::string& destination) {
    if (!CopyFile(source.c_str(), destination.c_str(), FALSE)) {
        std::cerr << "Failed to copy file" << std::endl;
    }
}

void moveFile(const std::string& source, const std::string& destination) {
    if (!MoveFile(source.c_str(), destination.c_str())) {
        std::cerr << "Failed to move file" << std::endl;
    }
}

int main() {
    std::string command;
    std::string path;
    std::string destination;

    while (true) {
        std::cout << "Enter a command (ls, mkdir, cp, mv): ";
        std::cin >> command;

        // create ls command

        if (command == "ls") {
            std::cout << "Enter directory path: ";
            std::cin >> path;
            listFiles(path); 

        // create mkdir command

        } else if (command == "mkdir") {
            std::cout << "Enter directory path: ";
            std::cin >> path;
            createDirectory(path);

        // create cp command

        } else if (command == "cp") {
            std::cout << "Enter source file path: ";
            std::cin >> path;
            std::cout << "Enter destination file path: ";
            std::cin >> destination;
            copyFile(path, destination);

        // create mv command
        } else if (command == "mv") {
            std::cout << "Enter source file path: ";
            std::cin >> path;
            std::cout << "Enter destination file path: ";
            std::cin >> destination;
            moveFile(path, destination);
        } 
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
