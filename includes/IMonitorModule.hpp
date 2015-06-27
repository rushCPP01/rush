#ifndef I_MONITOR_MODULE_HPP
#define I_MONITOR_MODULE_HPP

class IMonitorModule
{
	public:
		virtual ~IMonitorModule(void){};
		virtual void refreshDatas(void) = 0;
		virtual void setInterval(unsigned int n) = 0;
};
#endif