#pragma once

#include <string>

class IFileLoader {
public:
    virtual ~IFileLoader() = default;
    virtual void SetFileChecker(IFileLoader* fileChecker) = 0;
    virtual bool load(const std::string& filePath) = 0;
};