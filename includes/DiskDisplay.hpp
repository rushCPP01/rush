#ifndef DISK_DISPLAY_HPP
#define DISK_DISPLAY_HPP
#include "IMonitorDisplay.hpp"
#include "ADatas.hpp"

class DiskDisplay: public IMonitorDisplay
{
	public:
		DiskDisplay(ADatas& datas, int px, int py);
		~DiskDisplay(void);
		void	displayNcurses(void);
		void	displayQt(void);
		int		choose_color(int value);
	private:
		WINDOW	*win;
		WINDOW	*graph;
		ADatas&	m_datas;
		int		posX;
		int		posY;
		DiskDisplay(void);
		DiskDisplay& operator=(DiskDisplay const & rhs);
		DiskDisplay(DiskDisplay const & src);
};
#endif