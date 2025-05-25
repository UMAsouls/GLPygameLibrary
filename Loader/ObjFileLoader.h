#include "Interfaces/IFileLoader.h"
#include "ObjFileChecker/ObjFileChecker.h"

class ObjFileLoader : public IFileLoader {
private:


public:
    ObjFileLoader() = default;
    ~ObjFileLoader() override = default;

    
    /**
     * @brief Objファイルの読み込み
     * 
     * @param filePath ファイルパス
     * @return true 読み込み成功　false 読み込み失敗
     */
    bool load(const std::string& filePath) override;
};