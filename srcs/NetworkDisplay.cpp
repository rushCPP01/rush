#include "NetworkDisplay.hpp"

NetworkDisplay::NetworkDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 18, (getmaxx(stdscr)) - 4, posY, posX);
	graph = subwin(win, 16, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4), posY + 1, posX + (getmaxx(win) / 4));
	return;
}

int		NetworkDisplay::choose_color(int value)
{
	return (42 + (value / 35));
}

void	NetworkDisplay::displayNGraph(void)
{
	wresize(graph, 16, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4));
	int y = getmaxy(graph);
	int size = m_datas.m_stats.m_datas.size();
	int percent;
	int max = m_datas.m_stats.m_datas[0].PhyMem[0] + m_datas.m_stats.m_datas[0].PhyMem[2];
	werase(graph);
	for (int i = 0; i < size; ++i)
	{
		percent = y - ((y * (m_datas.m_stats.m_datas[i].PhyMem[0])) / max);
		wattron(graph, COLOR_PAIR(53));
		for (int e = y; e > 0; --e)
			mvwprintw(graph, e, i, " ");
		wattroff(graph, COLOR_PAIR(53));
		wattron(graph, COLOR_PAIR(49));
		for (int f = y; f > percent; --f)
			mvwprintw(graph, f, i, " ");
		percent = y - ((y * (m_datas.m_stats.m_datas[i].PhyMem[1])) / (max - m_datas.m_stats.m_datas[i].PhyMem[2]));
		for (int f = y; f > percent; --f)
			mvwprintw(graph, f, i, ".");
		wattroff(graph, COLOR_PAIR(49));
	}
	wrefresh(graph);
}

void	NetworkDisplay::displayNcurses(void)
{
	wresize(win, 18, (getmaxx(stdscr)) - 4);
	werase(win);
	box(win, '|', '=');
	wattron(win, COLOR_PAIR(45));
	mvwprintw(win, 2, 1, "Network:");
	mvwprintw(win, 3, 2, "%d/%dG Input.",m_datas.m_stats.m_datas.back().Network[0],m_datas.m_stats.m_datas.back().Network[1]);
	mvwprintw(win, 4, 2, "%d/%dG Output.",m_datas.m_stats.m_datas.back().Network[2],m_datas.m_stats.m_datas.back().Network[3]);
	wattroff(win, COLOR_PAIR(45));
	wrefresh(win);
	displayNGraph();
}

NetworkDisplay::~NetworkDisplay(void)
{
	delwin(win);
	delwin(graph);
	return;
}

void	NetworkDisplay::displayQt(void)
{
	return;
}