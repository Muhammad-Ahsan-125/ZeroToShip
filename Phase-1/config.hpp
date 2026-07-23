#pragma once

#include <string>
#include <vector>
#include <cstdint>

using std::string;
using std::vector;
using std::uintmax_t;

class StorageConfig {
public:

    int largeFileSizeMB = 50;
    int oldFileDays = 180;

    // --- Category Definitions ---
    vector<string> screenshotKeywords = {
        "screenshot", "screen shot", "capture"
    };

    vector<string> archiveExtensions = {
        ".zip", ".rar", ".7z", ".tar", ".gz"
    };

    vector<string> documentExtensions = {
        ".pdf", ".docx", ".doc", ".txt", ".xlsx", ".pptx", ".csv"
    };

    vector<string> imageExtensions = {
        ".png", ".jpg", ".jpeg", ".gif", ".bmp", ".webp"
    };

    uintmax_t largeFileSizeBytes() const {
        return static_cast<uintmax_t>(largeFileSizeMB) * 1024 * 1024;
    }
};