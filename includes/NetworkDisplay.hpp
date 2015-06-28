#ifndef NETWORK_DISPLAY_HPP
#define NETWORK_DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class NetworkDisplay: public IMonitorDisplay
{
	public:
		NetworkDisplay(ADatas& datas, int px, int py);
		NetworkDisplay(ADatas& datas);
		~NetworkDisplay(void);
		void	displayNcurses(void);
		void	displayQt(void);
		int		choose_color(int value);
	private:
		WINDOW	*win;
		WINDOW	*graph;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		NetworkDisplay(void);
		NetworkDisplay& operator=(NetworkDisplay const & rhs);
		NetworkDisplay(NetworkDisplay const & src);
	
};
#endif