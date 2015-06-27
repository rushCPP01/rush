#ifndef I_MONITOR_DISPLAY_HPP
#define I_MONITOR_DISPLAY_HPP

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void){};
		virtual void displayQt(void) = 0;
		virtual void displayNcurses(void) = 0;
};
#endif