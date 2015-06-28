#include "NetworkDisplay.hpp"

NetworkDisplay::NetworkDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 3, (getmaxx(stdscr)) - 4, posY, posX);
	return;
}

int		NetworkDisplay::choose_color(int value)
{
	return (42 + (value / 35));
}

void	NetworkDisplay::displayNcurses(void)
{
	wresize(win, 3, (getmaxx(stdscr)) - 4);
	werase(win);
	box(win, '|', '=');
	wattron(win, COLOR_PAIR(45));
	mvwprintw(win, 1, getmaxx(win) / 4, "Network: ");
	wprintw(win, "%d/%dG Input. 	",m_datas.m_stats.m_datas.back().Network[0],m_datas.m_stats.m_datas.back().Network[1]);
	wprintw(win, "%d/%dG Output.",m_datas.m_stats.m_datas.back().Network[2],m_datas.m_stats.m_datas.back().Network[3]);
	wattroff(win, COLOR_PAIR(45));
	wrefresh(win);
}

NetworkDisplay::~NetworkDisplay(void)
{
	delwin(win);
	return;
}

void	NetworkDisplay::displayQt(void)
{
	return;
}