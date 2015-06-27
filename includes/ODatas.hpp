#ifndef O_DATAS_HPP
#define O_DATAS_HPP
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/mount.h>
#include <sys/resource.h>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <utility>
#include <sys/utsname.h>

/* Datas structure description: */
        // OSInfos[0] = infos.sysname;
        // OSInfos[1] = infos.release;
        // OSInfos[2] = infos.version;
        // OSInfos[3] = infos.machine;
        /* Process[0] == Tasks Total            */
        /* Process[1] == Tasks Running          */
        /* Process[2] == Tasks Sleeping         */
        /* Process[3] == Tasks Stoped           */
        /* Process[4] == Tasks  Zombies(stuck)  */

        /* LoadAvg[0] == LoadAvg/1min in %          */
        /* LoadAvg[1] == LoadAvg/5min in %          */
        /* LoadAvg[2] == LoadAvg/15min in %         */

        /* CPUsage[0] == CPUsage User in %           */
        /* CPUsage[1] == CPUsage Sys in %            */
        /* CPUsage[2] == CPUsage Idle in %           */

        /* SharedLibs[0] == SharedLibs SzOfCode                 */
        /* SharedLibs[1] == SharedLibs DataSeg                  */
        /* SharedLibs[2] == SharedLibs Link Editor MemUsage     */

        /* MemRegions[0] == MemRegions Size Total               */
        /* MemRegions[1] == MemRegions Broken Resident          */
        /* MemRegions[2] == MemRegions Private                  */
        /* MemRegions[3] == Shared                              */

        /* PhyMem[0] == PhyMem MemUsage                 */
        /* PhyMem[1] == PhyMem broken(wired)            */
        /* PhyMem[2] == PhyMem Inactive                 */

        /* VM[0] == VirtualMem Total                     */
        /* VM[1] == VM Consomed by shared libs           */
        /* VM[2] == VM Numbers Pages IN                  */
        /* VM[3] == VM Numbers Pages OUT                 */

        /* Network[0] == Network Total size               */
        /* Network[1] == Network Input                    */
        /* Network[2] == Network Output                   */
        /* Network[3] == Network Total Packets            */

        /* Disks[0] == Disks Totalsize                 */
        /* Disks[1] == Disks FreeSize                  */
        /* Disks[2] == Disks ReadSize                  */
        /* Disks[] == Disks Write Siwe                 */

class ODatas
{
public:
    ODatas(void);
    ~ODatas(void);
    void getDatas(void);
    void getHostName(void);
    void getUserName(void);
    void getOSInfos(void);
    void getTime(void);

    std::string HostName;
    std::string UserName;
    std::string OSInfos[4];
    std::string Time;
    int     Process[5];
    float   LoadAvg[3];
    float   CPUsage[3];
    int     SharedLibs[3];
    int     MemRegions[4];
    int     PhyMem[3];
    int     VM[4];
    int     Network[4];
    int     Disks[4];
private:
    ODatas& operator=(ODatas const & rhs);
    ODatas(ODatas const & src);
};
#endif