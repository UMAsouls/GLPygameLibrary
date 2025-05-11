#include "../Interfaces/IFileLoader.h"

class ObjFileLoader : public IFileLoader {
public:
    ObjFileLoader() = default;
    ~ObjFileLoader() override = default;

    bool load(const std::string& filePath) override;
};