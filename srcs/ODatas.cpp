#include "ODatas.hpp"

ODatas::ODatas(void)
{
    this->getHostName();
    this->getUserName();
    this->getOSInfos();
    this->getDatas();
    return;
}

ODatas::~ODatas(void)
{
    return;
}

void ODatas::getHostName(void)
{
    char hostname[256] = {0};

    if (!gethostname(hostname, 255))
        HostName = hostname;
    else
        HostName = hostname;
}

void ODatas::getUserName(void)
{
    char username[256] = {0};

    if (!getlogin_r(username, 255))
        UserName = username;
    else
        UserName = "Unkown";
}

void ODatas::getOSInfos(void)
{
    struct utsname infos;

    if (!uname(&infos))
    {
        OSInfos[0] = infos.sysname;
        OSInfos[1] = infos.release;
        OSInfos[2] = infos.version;
        OSInfos[3] = infos.machine;
    }
}

void ODatas::getTime(void)
{
    time_t rawdate;
    struct tm *localdate;
    char buf[1024] = {0};

    time(&rawdate);
    localdate = localtime(&rawdate);
    strftime(buf, 1023, "%F %T", localdate);
    Time = buf;
}

void ODatas::getDatas(void)
{
    FILE *top;
    char buf[512] = {0};
    std::stringstream topinfos;

    top = popen("top -n 0 -l 1 -s 0 | sed '2d' | grep -o ' \\d*\\.\\d*\\| \\d*' | tr -d '[:blank:]' | sed '/^$/d'", "r");
    if (top)
    {
        while (fgets(buf, sizeof(buf), top) != NULL)
            topinfos << buf;
        pclose(top);
        for (int i = 0; i < 5; ++i)
            topinfos >> Process[i];
        for (int i = 0; i < 3; ++i)
            topinfos >> LoadAvg[i];
        for (int i = 0; i < 3; ++i)
            topinfos >> CPUsage[i];
        for (int i = 0; i < 3; ++i)
            topinfos >> SharedLibs[i];
        for (int i = 0; i < 4; ++i)
            topinfos >> MemRegions[i];
        for (int i = 0; i < 3; ++i)
            topinfos >> PhyMem[i];
        for (int i = 0; i < 4; ++i)
            topinfos >> VM[i];
        for (int i = 0; i < 4; ++i)
            topinfos >> Network[i];
        for (int i = 0; i < 4; ++i)
            topinfos >> Disks[i];
    }
    getTime();
}
