#ifndef A_DATAS_HPP
#define A_DATAS_HPP
#include <sstream>
#include "OStats.hpp"
#include "IMonitorModule.hpp"

class ADatas: public IMonitorModule
{
	public:
		ADatas(OStats& datas);
		void				refreshDatas(void);
		void				setInterval(unsigned int n);
		unsigned int 			getInterval(void);
		std::string const &		getHostname(void);
		std::string const &		getUsername(void);
		std::string const &		getSysname(void);
		std::string const &		getRelease(void);
		std::string const &		getVersion(void);
		std::string const &		getMachine(void);
		std::string const &		getTime(void);
		std::string	getProcessString(void);
		std::string getLoadAvgString(void);
		std::string getCPUsageString(void);
		virtual ~ADatas(void);
		OStats& m_stats;

	private:	
		ADatas(void);
		ADatas& operator=(ADatas const & rhs);
		ADatas(ADatas const & src);
};
#endif