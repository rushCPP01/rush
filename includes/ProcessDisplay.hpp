#ifndef PROCESS_DISPLAY_HPP
#define PROCESS_DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class ProcessDisplay: public IMonitorDisplay
{
		public:
		ProcessDisplay(ADatas& datas, int px, int py);
		~ProcessDisplay(void);
		void	displayNcurses(void);
		void	displayQt(void);
	private:
		WINDOW	*win;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		ProcessDisplay(void);
		ProcessDisplay& operator=(ProcessDisplay const & rhs);
		ProcessDisplay(ProcessDisplay const & src);
};
#endif