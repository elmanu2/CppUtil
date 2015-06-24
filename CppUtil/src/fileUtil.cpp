#include "fileUtil.h"
#include "windows.h"
#include "logger.h"
#include "helper.h"

FileUtil::FileUtil(void)
{
}


FileUtil::~FileUtil(void)
{
}

void FileUtil::createDirectory(std::string path_)
{
    if(CreateDirectory(path_.c_str(), NULL) == 0)
    {
        LOG_ERROR("Directory creation failure : " + path_);
        LOG_ERROR(Helper::windowsError(GetLastError()));
    }
}
