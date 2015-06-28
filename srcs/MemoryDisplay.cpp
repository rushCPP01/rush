#include "MemoryDisplay.hpp"

MemoryDisplay::MemoryDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 18, (getmaxx(stdscr)) - 4, posY, posX);
	graph = subwin(win, 16, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4), posY + 1, posX + (getmaxx(win) / 4));
	return;
}

int		MemoryDisplay::choose_color(int value)
{
	return (42 + (value / 35));
}

void	MemoryDisplay::displayNGraph(void)
{
	wresize(graph, 16, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4));
	int y = getmaxy(graph);
	int x = getmaxx(graph);
	int size = m_datas.m_stats.m_datas.size();
	int percent;
	int max = m_datas.m_stats.m_datas[0].PhyMem[0] + m_datas.m_stats.m_datas[0].PhyMem[2];
	werase(graph);
	for (int i = 0; i < size; ++i)
	{
		if (i < x)
		{
			percent = static_cast<int>(y - ((y * (m_datas.m_stats.m_datas[i].PhyMem[0])) / max));
			wattron(graph, COLOR_PAIR(53));
			for (int e = y - 1; e > 0; --e)
				mvwprintw(graph, e, i, "|");
			wattroff(graph, COLOR_PAIR(53));
			wattron(graph, COLOR_PAIR(49));
			for (int f = y - 1; f > percent; --f)
				mvwprintw(graph, f, i, "^");
			percent = static_cast<int>(y - ((y * (m_datas.m_stats.m_datas[i].PhyMem[1])) / (max - m_datas.m_stats.m_datas[i].PhyMem[2])));
			for (int f = y - 1; f > percent; --f)
				mvwprintw(graph, f, i, ".");
			wattroff(graph, COLOR_PAIR(49));
		}
	}
	wrefresh(graph);
}

void	MemoryDisplay::displayNcurses(void)
{
	wresize(win, 18, (getmaxx(stdscr)) - 4);
	werase(win);
	box(win, '|', '=');
	wattron(win, COLOR_PAIR(46));
	mvwprintw(win, 2, 1, "Memory Regions:");
	mvwprintw(win, 3, 2, "%d Total.",m_datas.m_stats.m_datas.back().MemRegions[0]);
	mvwprintw(win, 4, 2, "%dM Resident.",m_datas.m_stats.m_datas.back().MemRegions[1]);
	mvwprintw(win, 5, 2, "%dM Private.",m_datas.m_stats.m_datas.back().MemRegions[2]);
	mvwprintw(win, 6, 2, "%dM Shared.",m_datas.m_stats.m_datas.back().MemRegions[3]);
	wattroff(win, COLOR_PAIR(46));
	wattron(win, COLOR_PAIR(43));
	mvwprintw(win, 7, 1, "Physical Memory:");
	mvwprintw(win, 8, 2, "%dM Total used.",m_datas.m_stats.m_datas.back().PhyMem[0]);
	mvwprintw(win, 9, 2, "%dM Wired.",m_datas.m_stats.m_datas.back().PhyMem[1]);
	mvwprintw(win, 10, 2, "%dM Unused.",m_datas.m_stats.m_datas.back().PhyMem[2]);
	wattroff(win, COLOR_PAIR(43));
	wattron(win, COLOR_PAIR(44));
	mvwprintw(win, 11, 1, "Virtual Memory:");
	mvwprintw(win, 12, 2, "%dG Total.",m_datas.m_stats.m_datas.back().VM[0]);
	mvwprintw(win, 13, 2, "%dM SharedLibs.",m_datas.m_stats.m_datas.back().VM[1]);
	mvwprintw(win, 14, 2, "%d Swapin.",m_datas.m_stats.m_datas.back().VM[2]);
	mvwprintw(win, 15, 2, "%d Swapout.",m_datas.m_stats.m_datas.back().VM[3]);
	wattroff(win, COLOR_PAIR(44));
	wrefresh(win);
	displayNGraph();
}

MemoryDisplay::~MemoryDisplay(void)
{
	delwin(win);
	delwin(graph);
	return;
}

void	MemoryDisplay::displayQt(void)
{
	return;
}