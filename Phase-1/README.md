# Phase 1 — Environment Setup & Configuration Thresholds

## Goal
Set up the local development environment and define the storage rules
(thresholds) that will later decide what counts as a Large File, Old File,
Screenshot, or Archive — no actual folder scanning happens yet, this phase
is only about laying the foundation.

## Approach
- Created a `StorageConfig` class in `config.hpp` to hold all threshold
  values (large file size in MB, old file age in days, and category
  extension/keyword lists) as class members instead of scattering them as
  loose global constants.
- Added a `largeFileSizeBytes()` method to convert the human-readable MB
  threshold into bytes, since `std::filesystem::file_size()` reports sizes
  in bytes, not megabytes.
- Wrote `main.cpp` as an entry-point script that verifies `<filesystem>`
  works correctly (lists directory entries, checks the home directory
  exists) and confirms it can read values from `config.hpp`.
- Chose C++ for this project since I already know OOP in C++, using
  `std::filesystem` as the equivalent of Python's `os`/`pathlib` mentioned
  in the resource list.

## What I Learned
- How `std::filesystem::path`, `current_path()`, `directory_iterator`, and
  `exists()` work for filesystem access.
- The difference between MB and bytes when handling file sizes, and why
  that conversion should live in one central place (the config class)
  rather than being repeated later in scanning code.
- Basic C++ project structure: separating configuration/data (`config.hpp`)
  from the entry point (`main.cpp`).

## How to Run
```bash
g++ -std=c++17 main.cpp -o doomfolder
./doomfolder
```

## Output
See the `Output/` folder in this directory for screenshots and demo results.
