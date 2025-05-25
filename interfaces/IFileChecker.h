#pragma once

#include <string>

class IFileChecker {
public:
    virtual ~IFileChecker() = default;

    // Checks if the file exists and is accessible
    virtual bool fileExists(const std::string& filePath) const = 0;

    // Checks if the file is readable
    virtual bool isReadable(const std::string& filePath) const = 0;

    // Checks if the file is writable
    virtual bool isWritable(const std::string& filePath) const = 0;
};