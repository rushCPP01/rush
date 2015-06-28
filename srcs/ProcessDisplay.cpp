#include "ProcessDisplay.hpp"



ProcessDisplay::ProcessDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, 8, getmaxx(stdscr) - 4, posY, posX);
	return;
}

ProcessDisplay::ProcessDisplay(ADatas& datas): m_datas(datas)
{
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
	wattron(win, COLOR_PAIR(43));
	box(win, '.', '.');
	wattroff(win, COLOR_PAIR(43));
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

void	ProcessDisplay::displayQt(void)
{
	sf::Text text;
	std::string s;

	text.setFont(m_datas.font);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CGREEN, 236));
	text.setCharacterSize(15);
	text.setString("Processus:");
	text.setPosition(20, 580);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CORANGE, 236));
	text.setCharacterSize(15);
	text.setString("Total: " + std::to_string(m_datas.m_stats.m_datas.back().Process[0]));
	text.setPosition(20, 600);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CRED, 236));
	text.setCharacterSize(15);
	text.setString("Running: " + std::to_string(m_datas.m_stats.m_datas.back().Process[1]));
	text.setPosition(20, 615);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CBLUE, 236));
	text.setCharacterSize(15);
	text.setString("Sleeping: " + std::to_string(m_datas.m_stats.m_datas.back().Process[2]));
	text.setPosition(20, 630);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CYELLOW, 236));
	text.setCharacterSize(15);
	text.setString("Stoped: " + std::to_string(m_datas.m_stats.m_datas.back().Process[3]));
	text.setPosition(20, 645);
	m_datas.window->draw(text);

	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color(CMAGENTA, 236));
	text.setCharacterSize(15);
	text.setString("Thread: " + std::to_string(m_datas.m_stats.m_datas.back().Process[4]));
	text.setPosition(20, 660);
	m_datas.window->draw(text);
	return;
}
