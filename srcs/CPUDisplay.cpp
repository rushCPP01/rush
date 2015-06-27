#include "CPUDisplay.hpp"

CPUDisplay::CPUDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, getmaxy(stdscr) / 4, getmaxx(stdscr) / 4, posY, posX);
	graph = subwin(win, getmaxy(win) - 7, getmaxx(win) - 2, posY + 5, posX + 1);
	return;
}

int		choose_color(int value)
{
	return (42 + (value / 35));
}

void	CPUDisplay::displayGraph(int c1, int c2, int c3)
{
	wresize(graph, getmaxy(win) - 7, getmaxx(win) - 2);
	int y = getmaxy(graph);
	int size = m_datas.m_stats.m_datas.size();
	werase(graph);
	for (int i = 0; i < size; i++)
	{
		wattron(graph, COLOR_PAIR(c1));
		mvwprintw(graph, y - (((y - 1) * (static_cast<int>(m_datas.m_stats.m_datas[i].CPUsage[0]))) / 100) - 1, i + 1, ".");
		wattroff(graph, COLOR_PAIR(c1));
		wattron(graph, COLOR_PAIR(c2));
		mvwprintw(graph, y - (((y - 1) * (static_cast<int>(m_datas.m_stats.m_datas[i].CPUsage[1]))) / 100) - 1, i + 1, ".");
		wattroff(graph, COLOR_PAIR(c2));
		wattron(graph, COLOR_PAIR(c3));
		mvwprintw(graph, y - (((y - 1) * (static_cast<int>(m_datas.m_stats.m_datas[i].CPUsage[2]))) / 100) - 1, i + 1, ".");
		wattroff(graph, COLOR_PAIR(c3));
	}
	wrefresh(graph);
}

void	CPUDisplay::displayNcurses(void)
{
	wresize(win, getmaxy(stdscr) / 4, getmaxx(stdscr) / 4);
	werase(win);
	int color1 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[0]);
	int color2 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[1]);
	int color3 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[2]);
	box(win, '|', '=');
	mvwprintw(win, 1, 1, "CPU Usage:");
	wattron(win, COLOR_PAIR(color1));
	mvwprintw(win, 2, 2, "%.2f%% user.",m_datas.m_stats.m_datas.back().CPUsage[0]);
	wattroff(win, COLOR_PAIR(color1));
	wattron(win, COLOR_PAIR(color2));
	mvwprintw(win, 3, 2, "%.2f%% system.",	m_datas.m_stats.m_datas.back().CPUsage[1]);
	wattroff(win, COLOR_PAIR(color2));
	wattron(win, COLOR_PAIR(color3));
	mvwprintw(win, 4, 2, "%.2f%% idle.",	m_datas.m_stats.m_datas.back().CPUsage[2]);
	wattroff(win, COLOR_PAIR(color3));
	wrefresh(win);
	displayGraph(45, 46, 47);
}

void	CPUDisplay::setX(unsigned int n)
{
	posX = n;
}
void	CPUDisplay::setY(unsigned int n)
{
	posY = n;
}

CPUDisplay::~CPUDisplay(void)
{
	delwin(win);
	delwin(graph);
	return;
}

void	CPUDisplay::displayQt(void)
{
	return;
}