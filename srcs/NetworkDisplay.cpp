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
	sf::Text text;
	std::string s;

	text.setFont(m_datas.font);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CBLUE, 236));
	text.setCharacterSize(15);
	s = "Network: ";
	s += "\t" + std::to_string(m_datas.m_stats.m_datas.back().Network[0]) + "/" + std::to_string(m_datas.m_stats.m_datas.back().Network[1]) + "G Input.";
	s += "\t\t" + std::to_string(m_datas.m_stats.m_datas.back().Network[2]) + "/" + std::to_string(m_datas.m_stats.m_datas.back().Network[3]) + "G Output.";
	text.setString(s);
	text.setPosition(20, 800);
	m_datas.window->draw(text);
	return;
}