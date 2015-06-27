#include "OStats.hpp"

OStats::OStats(void)
{
    m_datas.emplace_front();
    m_maxsize = 1;
    return;
}

OStats::OStats(unsigned int size)
{
    m_datas.emplace_front();
    m_maxsize = size;
    return;
}

void OStats::setSize(unsigned int n)
{
    while (n < m_datas.size())
        m_datas.pop_front();
    m_maxsize = n;
}

unsigned int OStats::getMaxSize(void)
{
    return (m_maxsize);
}

void    OStats::statsRefresh(void)
{
    if ((m_datas.size() + 1) > m_maxsize)
        m_datas.pop_front();
    m_datas.emplace_back();
}

OStats::~OStats(void)
{
    return;
}

