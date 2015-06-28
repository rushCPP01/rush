#include "ODatas.hpp"

ODatas::ODatas(void)
{
    this->getHostName();
    this->getUserName();
    this->getOSInfos();
    this->getDatas();
    this->getCPUInfos();
    return;
}

ODatas::~ODatas(void)
{
    return;
}

void ODatas::getCPUInfos(void)
{
    char buf[2048] = {0};
    size_t blen = 2048;
    size_t len = sizeof(int);
    sysctlbyname("hw.ncpu", &ncpu, &len, NULL, 0);
    sysctlbyname("machdep.cpu.brand_string", buf, &blen, NULL, 0);
    CPUInfos[0] = buf;
    sysctlbyname("machdep.cpu.vendor", buf, &blen, NULL, 0);
    CPUInfos[1] = buf;
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
    int tmp;
    float ftmp;
    std::stringstream topinfos;

    top = popen("top -n 0 -l 1 -s 0 | sed '2d' | grep -o ' \\d*\\.\\d*\\| \\d*' | tr -d '[:blank:]' | sed '/^$/d'", "r");
    if (top)
    {
        while (fgets(buf, sizeof(buf), top) != NULL)
            topinfos << buf;
        pclose(top);
        for (int i = 0; i < 5; ++i)
        {
            topinfos >> tmp;
            Process.emplace_back(tmp);
        }
        for (int i = 0; i < 3; ++i)
        {
            topinfos >> ftmp;
            LoadAvg.emplace_back(ftmp);
        }
        for (int i = 0; i < 3; ++i)
        {
            topinfos >> ftmp;
            CPUsage.emplace_back(ftmp);
        }
        for (int i = 0; i < 3; ++i)
        {
            topinfos >> tmp;
            SharedLibs.emplace_back(tmp);
        }
        for (int i = 0; i < 4; ++i)
        {
            topinfos >> tmp;
            MemRegions.emplace_back(tmp);
        }
        for (int i = 0; i < 3; ++i)
        {
            topinfos >> tmp;
            PhyMem.emplace_back(tmp);
        }
        for (int i = 0; i < 4; ++i)
        {
            topinfos >> tmp;
            VM.emplace_back(tmp);
        }
        for (int i = 0; i < 4; ++i)
        {
            topinfos >> tmp;
            Network.emplace_back(tmp);
        }
        for (int i = 0; i < 4; ++i)
        {
            topinfos >> tmp;
            Disks.emplace_back(tmp);
        }
    }
    getTime();
}
