#ifndef CPU_DISPLAY_HPP
#define CPU_DISPLAY_HPP
#include <sys/time.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/socket.h>
#include <sys/mount.h>
#include <sys/resource.h>
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"
#include <iostream>

class CPUDisplay: public IMonitorDisplay
{
	public:
		CPUDisplay(ADatas& datas, int px, int py);
		~CPUDisplay(void);
		void	displayInfos(void);
		void	displayNcurses(void);
		void	displayNGraph(int, int, int);
		void	displayQt(void);
		int		choose_color(int value);
	private:
		WINDOW	*win;
		WINDOW	*graph;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		CPUDisplay(void);
		CPUDisplay& operator=(CPUDisplay const & rhs);
		CPUDisplay(CPUDisplay const & src);
};
#endif