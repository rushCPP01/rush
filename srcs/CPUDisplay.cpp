#include "CPUDisplay.hpp"

CPUDisplay::CPUDisplay(ADatas& datas, int px, int py): m_datas(datas), posX(px), posY(py)
{
	win = subwin(stdscr, getmaxy(stdscr) / 4, (getmaxx(stdscr)) - 4, posY, posX);
	graph = subwin(win, getmaxy(win) - 4, ((getmaxx(win) - 4) / 2) + (getmaxx(win) / 4), posY + 1, posX + (getmaxx(win) / 4));
	return;
}

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
	float posX = 100;
	float posY = 300;
	int size = m_datas.m_stats.m_datas.size();

	sf::Font font;
	if (!font.loadFromFile("misc/Calibri.ttf")) {
		std::cout << "Font loading error." << std::endl;
		exit(0);
	}
	sf::Text text;
	text.setFont(font); // choix de la police à utiliser // font est un sf::Font
	text.setString("CPU usage");// choix de la chaîne de caractères à afficher
	text.setCharacterSize(24); // choix de la taille des caractères // exprimée en pixels, pas en points !
	text.setColor(sf::Color(50, 255, 200, 150));// choix de la couleur du texte
	text.setPosition(posX, posY + 30);
	m_datas.window->draw(text);
	//vector<int> values.size()
	for (int i = 0; i < size; ++i)
	{
		user.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[0])), sf::Color::Red));
		sys.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[1])), sf::Color::Blue));
		idle.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - static_cast<float>(m_datas.m_stats.m_datas[i].CPUsage[2])), sf::Color::Green));
	}
	m_datas.window->draw(&user[0], user.size(), sf::LinesStrip);
	m_datas.window->draw(&sys[0], sys.size(), sf::LinesStrip);
	m_datas.window->draw(&idle[0],idle.size(), sf::LinesStrip);
	return;
}