#include "ProcessDisplay.hpp"

ProcessDisplay::ProcessDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 8, getmaxx(stdscr) - 4, posY, posX);
	return;
}

ProcessDisplay::~ProcessDisplay(void)
{
	delwin(win);
	return;
}

void	ProcessDisplay::displayNcurses(void)
{
	wresize(win, 8, getmaxx(stdscr) - 4);
	int x = getmaxx(win);
	werase(win);
	wattron(win, COLOR_PAIR(51));
	box(win, '.', '.');
	wattroff(win, COLOR_PAIR(51));
	wattron(win, COLOR_PAIR(42));
	mvwprintw(win, 1, (x / 2) - 11, "Processus:");
	wattroff(win, COLOR_PAIR(42));
	wattron(win, COLOR_PAIR(43));
	mvwprintw(win,2, 1, "Total: %d", m_datas.m_stats.m_datas.back().Process[0]);
	wattroff(win, COLOR_PAIR(43));
	wattron(win, COLOR_PAIR(44));
	mvwprintw(win,3, 1, "Running: %d", m_datas.m_stats.m_datas.back().Process[1]);
	wattroff(win, COLOR_PAIR(44));
	wattron(win, COLOR_PAIR(45));
	mvwprintw(win,4, 1, "Sleeping: %d", m_datas.m_stats.m_datas.back().Process[2]);
	wattroff(win, COLOR_PAIR(45));
	wattron(win, COLOR_PAIR(46));
	mvwprintw(win,5, 1, "Stoped: %d", m_datas.m_stats.m_datas.back().Process[3]);
	wattroff(win, COLOR_PAIR(46));
	wattron(win, COLOR_PAIR(47));
	mvwprintw(win,6, 1, "Thread: %d", m_datas.m_stats.m_datas.back().Process[4]);
	wattroff(win, COLOR_PAIR(47));
	wrefresh(win);
}
