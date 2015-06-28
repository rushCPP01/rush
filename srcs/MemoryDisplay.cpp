#include "MemoryDisplay.hpp"

MemoryDisplay::MemoryDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 18, (getmaxx(stdscr)) - 4, posY, posX);
	graph = subwin(win, 16, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4), posY + 1, posX + (getmaxx(win) / 4));
	return;
}

MemoryDisplay::MemoryDisplay(ADatas& datas): m_datas(datas)
{
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

void	MemoryDisplay::displayQt(void)
{
	sf::Text text;
	std::string s;

	text.setFont(m_datas.font);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CYELLOW, 236));
	text.setCharacterSize(15);
	s = "Memory Regions:";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[0]) + " Total.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[1]) + "M Resident.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[2]) + "M Private.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[3]) + "M Shared.";
	text.setString(s);
	text.setPosition(1150, 200);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CORANGE, 236));
	text.setCharacterSize(15);
	s = "Physical Memory:";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[0]) + "M Total used.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[1]) + "M Wired.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().MemRegions[3]) + "M Unused.";
	text.setString(s);
	text.setPosition(1150, 350);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CRED, 236));
	text.setCharacterSize(15);
	s = "Virtual Memory:";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().VM[0]) + "G Total.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().VM[1]) + "M SharedLibs.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().VM[2]) + " Swapin.";
	s += "\n   " + std::to_string(m_datas.m_stats.m_datas.back().VM[3]) + " Swapout.";
	text.setString(s);
	text.setPosition(1150, 500);
	m_datas.window->draw(text);

	// std::vector<sf::Vertex> user;
	// std::vector<sf::Vertex> sys;
	// std::vector<sf::Vertex> idle;

	// //vector<int> values.size()
	// for (int i = 0; i < size; ++i)
	// {
	// 	user.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 3 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[0])), sf::Color::Red));
	// 	sys.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 3 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[1])), sf::Color::Blue));
	// 	idle.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 3 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[2])), sf::Color::Green));
	// }
	// m_datas.window->draw(&user[0], user.size(), sf::LinesStrip);
	// m_datas.window->draw(&sys[0], sys.size(), sf::LinesStrip);
	// m_datas.window->draw(&idle[0],idle.size(), sf::LinesStrip);
	// return;
}


MemoryDisplay::~MemoryDisplay(void)
{
	delwin(win);
	delwin(graph);
	return;
}