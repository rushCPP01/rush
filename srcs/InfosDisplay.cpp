#include "InfosDisplay.hpp"

InfosDisplay::InfosDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 10, getmaxx(stdscr) - 4, posY, posX);
	return;
}

InfosDisplay::~InfosDisplay(void)
{
	delwin(win);
	return;
}

void		InfosDisplay::displayNcurses(void)
{
	wresize(win, 10, getmaxx(stdscr) - 4);
	int x = getmaxx(win);
	werase(win);
	wattron(win, COLOR_PAIR(51));
	box(win, '|', '=');
	mvwprintw(win, 1, (x / 2) - 6, "Infos:");	
	wattroff(win, COLOR_PAIR(51));
	wattron(win, COLOR_PAIR(45));	
	mvwprintw(win, 3, (x / 2) - (10), "Hostname: %s", m_datas.getHostname().c_str());
	mvwprintw(win, 4, (x / 2) - (10), "Username: %s", m_datas.getUsername().c_str());
	wattroff(win, COLOR_PAIR(45));
	wattron(win, COLOR_PAIR(43));	
	mvwprintw(win, 5, (x / 2) - (9), "Sysname: %s", m_datas.getSysname().c_str());
	mvwprintw(win, 6, (x / 2) - (9), "Release: %s", m_datas.getRelease().c_str());
	mvwprintw(win, 7, (x / 2) - (9), "Machine: %s", m_datas.getMachine().c_str());
	wattroff(win, COLOR_PAIR(43));
	wattron(win, COLOR_PAIR(44));
	mvwprintw(win, 8, (x / 2) - (6), "Time: %s", m_datas.getTime().c_str());
	wattroff(win, COLOR_PAIR(44));
	wrefresh(win);
}