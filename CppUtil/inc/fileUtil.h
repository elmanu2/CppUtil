#pragma once

#include <string>

class FileUtil
{
public:
    FileUtil(void);

    ~FileUtil(void);

    static void createDirectory(std::string path_);
};

