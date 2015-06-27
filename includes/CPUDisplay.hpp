#ifndef CPU_DISPLAY_HPP
#define CPU_DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class CPUDisplay: public IMonitorDisplay
{
	public:
		CPUDisplay(ADatas& datas, int px, int py);
		~CPUDisplay(void);
		void	displayNcurses(void);
		void	displayNGraph(int, int, int);
		void	displayQt(void);
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