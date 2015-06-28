#include "CPUDisplay.hpp"

CPUDisplay::CPUDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, getmaxy(stdscr) / 4, (getmaxx(stdscr)) - 4, posY, posX);
	graph = subwin(win, getmaxy(win) - 4, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4), posY + 1, posX + (getmaxx(win) / 4));
	return;
}

CPUDisplay::CPUDisplay(ADatas& datas) : m_datas(datas)
{}

int		CPUDisplay::choose_color(int value)
{
	return (42 + (value / 35));
}

void	CPUDisplay::displayNGraph(int c1, int c2, int c3)
{
	wresize(graph, (getmaxy(win) - 4), ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4));
	int y = getmaxy(graph);
	int size = m_datas.m_stats.m_datas.size();
	werase(graph);
	for (int i = 0; i < size; ++i)
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

void	CPUDisplay::displayInfos(void)
{
	wattron(win, COLOR_PAIR(45));
	mvwprintw(win, 1, 1, "CPU Infos: ");
	wattroff(win, COLOR_PAIR(45));;
	wattron(win, COLOR_PAIR(45));
	mvwprintw(win, 2, 2, "Name: %s", m_datas.m_stats.m_datas[0].CPUInfos[0].c_str());
	mvwprintw(win, 3, 2, "Vendor: %s", m_datas.m_stats.m_datas[0].CPUInfos[1].c_str());
	mvwprintw(win, 4, 2, "Cores: %d", m_datas.m_stats.m_datas[0].ncpu);
	wattroff(win, COLOR_PAIR(45));;
}

void	CPUDisplay::displayNcurses(void)
{
	wresize(win, getmaxy(stdscr) / 4, (getmaxx(stdscr)) - 4);
	werase(win);
	int color1 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[0]);
	int color2 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[1]);
	int color3 = choose_color(m_datas.m_stats.m_datas.back().CPUsage[2]);
	box(win, '|', '=');
	displayInfos();
	mvwprintw(win, 5, 1, "CPU Usage:");
	wattron(win, COLOR_PAIR(color1));
	mvwprintw(win, 6, 2, "%.2f%% user.",m_datas.m_stats.m_datas.back().CPUsage[0]);
	wattroff(win, COLOR_PAIR(color1));
	wattron(win, COLOR_PAIR(color2));
	mvwprintw(win, 7, 2, "%.2f%% system.",	m_datas.m_stats.m_datas.back().CPUsage[1]);
	wattroff(win, COLOR_PAIR(color2));
	wattron(win, COLOR_PAIR(color3));
	mvwprintw(win, 8, 2, "%.2f%% idle.",	m_datas.m_stats.m_datas.back().CPUsage[2]);
	wattroff(win, COLOR_PAIR(color3));
	wrefresh(win);
	displayNGraph(45, 46, 47);
}

CPUDisplay::~CPUDisplay(void)
{
	delwin(win);
	delwin(graph);
	return;
}

void	CPUDisplay::displayQt(void)
{
	std::vector<sf::Vertex> user;
	std::vector<sf::Vertex> sys;
	std::vector<sf::Vertex> idle;
// sf::Vector2f(500, 500); // for origin
	int posX = 400;
	int posY = 500;
	int size = m_datas.m_stats.m_datas.size();

	sf::Text text;
	text.setCharacterSize(15); // choix de la taille des caractères // exprimée en pixels, pas en points !
	//text.setColor(sf::Color(50, 255, 200, 150));// choix de la couleur du texte
	text.setColor(sf::Color::White);// choix de la couleur du texte
	

	text.setFont(m_datas.font); // choix de la police à utiliser // font est un sf::Font
	text.setStyle(sf::Text::Bold);
	std::string s = "CPU Data:\n\tName: " + m_datas.m_stats.m_datas[0].CPUInfos[0];
	s += "\n\tVendor: " + m_datas.m_stats.m_datas[0].CPUInfos[1];
	s += "\n\tCores: " + std::to_string(m_datas.m_stats.m_datas[0].ncpu);
	s += "\n\nCPU usage:\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[0]) + "\% user.";
	s += "\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[1]) + "\% system.";
	s += "\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[2]) + "\% idle.";
	text.setString(s);// choix de la chaîne de caractères à afficher
	text.setPosition(posX - 380, posY - 250);
	m_datas.window->draw(text);
	//vector<int> values.size()
	for (int i = 0; i < size; ++i)
	{
		user.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 4 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[0])), sf::Color::Red));
		sys.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 4 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[1])), sf::Color::Blue));
		idle.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - 4 * static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[2])), sf::Color::Green));
	}
	m_datas.window->draw(&user[0], user.size(), sf::LinesStrip);
	m_datas.window->draw(&sys[0], sys.size(), sf::LinesStrip);
	m_datas.window->draw(&idle[0],idle.size(), sf::LinesStrip);
	return;
}

	// std::string s;
	// std::stringstream ss;
 // 	ss.unsetf ( std::ios::floatfield );                // floatfield not set
 //  	ss.precision(2);
	// ss << "CPU Data:\n\tName: " + m_datas.m_stats.m_datas[0].CPUInfos[0];
	// ss << "\n\tVendor: " + m_datas.m_stats.m_datas[0].CPUInfos[1];
	// ss << "\n\tCores: " + std::to_string(m_datas.m_stats.m_datas[0].ncpu);
	// ss << "\n\nCPU usage:\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[0]) + "\% user.";
	// ss << "\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[1]) + "\% system.";
	// ss << "\n\t" + std::to_string(m_datas.m_stats.m_datas.back().CPUsage[2]) + "\% idle.";
	// ss >> s;
	// text.setString(s);// choix de la chaîne de caractères à afficher