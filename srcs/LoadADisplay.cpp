#include "LoadADisplay.hpp"

LoadADisplay::LoadADisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 6, getmaxx(stdscr) - 4, posY, posX);
	return;
}

LoadADisplay::~LoadADisplay(void)
{
	delwin(win);
	return;
}

void		LoadADisplay::displayNcurses(void)
{
	wresize(win, 6, getmaxx(stdscr) - 4);
	int x = getmaxx(win);
	werase(win);
	wattron(win, COLOR_PAIR(42));
	box(win, '|', '^');
	wattroff(win, COLOR_PAIR(42));
	wattron(win, COLOR_PAIR(44));
	mvwprintw(win, 1, (x / 8), "LoadAverage: ");
	mvwprintw(win, 2, (x / 8), "1min: %.2f", m_datas.m_stats.m_datas.back().LoadAvg[0]);
	mvwprintw(win, 3, (x / 8), "5min: %.2f", m_datas.m_stats.m_datas.back().LoadAvg[1]);
	mvwprintw(win, 4, (x / 8), "15min: %.2f", m_datas.m_stats.m_datas.back().LoadAvg[2]);
	wattroff(win, COLOR_PAIR(44));
	wattron(win, COLOR_PAIR(43));
	mvwprintw(win, 1, (x / 8)*5, "SharedLibs: ");
	mvwprintw(win, 2, (x / 8)*5, "Size of code: %d", m_datas.m_stats.m_datas.back().SharedLibs[0]);
	mvwprintw(win, 3, (x / 8)*5, "Datas Segment: %d", m_datas.m_stats.m_datas.back().SharedLibs[1]);
	mvwprintw(win, 4, (x / 8)*5, "Link Editor Memory usage: %d", m_datas.m_stats.m_datas.back().SharedLibs[2]);
	wattroff(win, COLOR_PAIR(43));
	wrefresh(win);
}