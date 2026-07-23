#include <iostream>
#include <filesystem>
#include <cstdlib>
#include "config.hpp"

namespace fs = std::filesystem;

void verifyEnvironment(const StorageConfig& settings) {
    std::cout << "=== DoomFolder Environment Check ===\n";

    fs::path currentDir = fs::current_path();
    std::cout << "Current directory (filesystem): " << currentDir << "\n";


    int count = 0;
    for (const auto& entry : fs::directory_iterator(currentDir)) {
        (void)entry;
        count++;
    }
    std::cout << "directory_iterator found " << count << " entries in this folder.\n";


    const char* home = std::getenv("HOME");
    if (!home) {
        home = std::getenv("USERPROFILE");
    }
    if (home) {
        fs::path homeDir(home);
        std::cout << "Home directory: " << homeDir << "\n";
        std::cout << "Home directory exists?: " << std::boolalpha
                   << fs::exists(homeDir) << "\n";
    } else {
        std::cout << "Home directory: (could not detect HOME/USERPROFILE)\n";
    }

    std::cout << "\n=== Config Check ===\n";
    std::cout << "Large file threshold: " << settings.largeFileSizeMB << " MB\n";
    std::cout << "Old file threshold: " << settings.oldFileDays << " days\n";

    std::cout << "\nEnvironment check complete: <filesystem> and config all working.\n";
}

int main() {
    StorageConfig settings;
    verifyEnvironment(settings);
    return 0;
}
