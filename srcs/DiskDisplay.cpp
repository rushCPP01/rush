#include "DiskDisplay.hpp"

DiskDisplay::DiskDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 3, (getmaxx(stdscr)) - 4, posY, posX);
	return;
}

int		DiskDisplay::choose_color(int value)
{
	return (42 + (value / 35));
}

void	DiskDisplay::displayNcurses(void)
{
	wresize(win, 3, (getmaxx(stdscr)) - 4);
	werase(win);
	box(win, '|', '=');
	wattron(win, COLOR_PAIR(47));
	mvwprintw(win, 1, getmaxx(win) / 4, "Disks: ");
	wprintw(win, "%d/%dG Read. 	",m_datas.m_stats.m_datas.back().Disks[0], m_datas.m_stats.m_datas.back().Disks[1]);
	wprintw(win, "%d/%dG Write.",m_datas.m_stats.m_datas.back().Disks[2], m_datas.m_stats.m_datas.back().Disks[3]);
	wattroff(win, COLOR_PAIR(47));
	wrefresh(win);
}

DiskDisplay::~DiskDisplay(void)
{
	delwin(win);
	return;
}

void	DiskDisplay::displayQt(void)
{
	return;
}