#ifndef MEMORY_DISPLAY_HPP
#define MEMORY_DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class MemoryDisplay: public IMonitorDisplay
{
	public:
		MemoryDisplay(ADatas& datas, int px, int py);
		MemoryDisplay(ADatas& datas);
		~MemoryDisplay(void);
		void	displayNcurses(void);
		void	displayNGraph(void);
		void	displayQt(void);
		int		choose_color(int value);
	private:
		WINDOW	*win;
		WINDOW	*graph;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		MemoryDisplay(void);
		MemoryDisplay& operator=(MemoryDisplay const & rhs);
		MemoryDisplay(MemoryDisplay const & src);
};
#endif