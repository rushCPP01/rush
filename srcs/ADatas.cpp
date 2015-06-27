#include "ADatas.hpp"


ADatas::ADatas(OStats& datas): m_stats(datas)
{
	return;
}

ADatas::~ADatas(void)
{
	return;
}

unsigned int 			ADatas::getInterval(void)
{
	return (m_stats.getMaxSize());
}

void	ADatas::refreshDatas(void)
{
	m_stats.statsRefresh();
	return;
}

void	ADatas::setInterval(unsigned int n)
{
	m_stats.setSize(n);
	return;
}

std::string const &		ADatas::getHostname(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().HostName));
}

std::string const &		ADatas::getUsername(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().UserName));
}

std::string const &		ADatas::getSysname(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().OSInfos[0]));
}

std::string const &		ADatas::getRelease(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().OSInfos[1]));
}

std::string const &		ADatas::getVersion(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().OSInfos[2]));
}

std::string const &		ADatas::getMachine(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().OSInfos[3]));
}

std::string const &		ADatas::getTime(void)
{
	return (static_cast<std::string&>(m_stats.m_datas.front().Time));
}