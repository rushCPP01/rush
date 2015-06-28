#ifndef INFOS_DISPLAY_HPP
#define INFOS_DISPLAY_HPP
#include "ADatas.hpp"
#include "IMonitorDisplay.hpp"

class InfosDisplay: public IMonitorDisplay
{
	public:
		InfosDisplay(ADatas& datas, int px, int py);
		void	displayNcurses(void);
		void	displayQt(void);
		~InfosDisplay(void);
	private:
		WINDOW	*win;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		InfosDisplay(void);
		InfosDisplay(InfosDisplay const & src);
		InfosDisplay& operator=(InfosDisplay const & rhs);
};
#endif