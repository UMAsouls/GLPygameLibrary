#pragma once

#include <string>

class IFileLoader {
public:
    virtual ~IFileLoader() = default;
    virtual bool load(const std::string& filePath) = 0;
};