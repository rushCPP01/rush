#ifndef LOAD_ADISPLAY_HPP
#define LOAD_ADISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class LoadADisplay: public IMonitorDisplay
{
	public:
		LoadADisplay(ADatas& datas, int px, int py);
		void	displayNcurses(void);
		void	displayQt(void);
		~LoadADisplay(void);
	private:
		WINDOW	*win;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		LoadADisplay(void);
		LoadADisplay(LoadADisplay const & src);
		LoadADisplay& operator=(LoadADisplay const & rhs);
};
#endif