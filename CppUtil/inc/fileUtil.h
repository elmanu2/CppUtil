#pragma once

#include <string>

class FileUtil
{
public:
    FileUtil(void);

    ~FileUtil(void);

    static bool directoryExist(std::string path_);

    static void createDirectory(std::string path_);
};

