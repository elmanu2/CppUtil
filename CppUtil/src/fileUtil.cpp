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

bool FileUtil::directoryExist(std::string path_)
{
  DWORD ftyp = GetFileAttributesA(path_.c_str());
  if (ftyp == INVALID_FILE_ATTRIBUTES)
    return false;  //something is wrong with your path!

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
    return true;   // this is a directory!

  return false;    // this is not a directory!
}

void FileUtil::createDirectory(std::string path_)
{
    if(directoryExist(path_))
    {
        return;
    }

    BOOL errCode = CreateDirectory(path_.c_str(), NULL);
    
    if(errCode == 0)
    {
        LOG_ERROR("Directory creation failure : " + path_);
        LOG_ERROR(Helper::windowsError(GetLastError()));
    }
}
