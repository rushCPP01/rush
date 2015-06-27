/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:10:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 23:04:10 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Tools.hpp"
#include "ADatas.hpp"
#include "CPUDisplay.hpp"
#include "InfosDisplay.hpp"
#define KEY_ECHAP 27
#define NCOLOR(x) (x*4)
#define MYGREEN	  67
#define MYRED	  68
#define MYORANGE  69
#define MYBLUE	  70
#define MYYELLOW  71
#define MYMAGENTA 72

void				colorsDefines(void)
{
	init_color(MYGREEN, 156, 696, 384);
	init_color(MYRED, 768, 228, 172);
	init_color(MYORANGE, 920, 504, 136);
	init_color(MYBLUE, NCOLOR(41), NCOLOR(128), NCOLOR(185));
	init_color(MYYELLOW, NCOLOR(241), NCOLOR(196), NCOLOR(15));
	init_color(MYMAGENTA, NCOLOR(142), NCOLOR(68), NCOLOR(173));
	init_pair(42, MYGREEN,COLOR_BLACK );
	init_pair(43, MYORANGE, COLOR_BLACK);
	init_pair(44, MYRED, COLOR_BLACK);
	init_pair(45, MYBLUE, COLOR_BLACK);
	init_pair(46, MYYELLOW, COLOR_BLACK);
	init_pair(47, MYMAGENTA, COLOR_BLACK);
	init_pair(48, COLOR_BLACK, MYGREEN);
	init_pair(49, COLOR_BLACK, MYORANGE);
	init_pair(50, COLOR_BLACK, MYRED);
	init_pair(51, COLOR_BLACK, MYBLUE);
	init_pair(52, COLOR_BLACK, MYYELLOW);
	init_pair(53, COLOR_BLACK, MYMAGENTA);
}

void				Ncurses_Mode(ADatas& dat)
{
	int input = -1;
	int x;
	int y;

	initscr();
	x = getmaxx(stdscr);
	y = getmaxy(stdscr);
	dat.setInterval(x / 4);
	start_color();
	colorsDefines();
	noecho();
	curs_set(FALSE);
	raw();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	InfosDisplay infos(dat, 2, 2);
	CPUDisplay cpu(dat, 2, 13);
	while (input != KEY_ECHAP)
	{
		dat.setInterval(getmaxx(stdscr) / 2);
		erase();
		box(stdscr, '|', '-');
		cpu.displayNcurses();
		infos.displayNcurses();
		input = getch();
		dat.refreshDatas();
		refresh();
	}
	endwin();
}

void 				test1sfml(ADatas &env)
{
	env.settings.antialiasingLevel = 8;

    env.window = new sf::RenderWindow(sf::VideoMode(1000, 800), "SFML works!", sf::Style::Default, env.settings);
    env.window->setVerticalSyncEnabled(true); // , un appel suffit, après la création de la fenêtre
    while (env.window->isOpen())
    {
        sf::Event event;
        while (env.window->pollEvent(event))
        {
           // on regarde le type de l'évènement...
	   		switch (event.type)
		    {
		        // fenêtre fermée
		        case sf::Event::Closed:
		            env.window->close();
		            break;
		        case sf::Event::Resized:
		            std::cout << "new width: " << event.size.width << std::endl;
	    			std::cout << "new height: " << event.size.height << std::endl;
		            break;

		        // touche pressée
		        case sf::Event::KeyPressed:
		            break;

		        // on ne traite pas les autres types d'évènements
		        default:
		            break;
		    }

        }
        env.window->clear(sf::Color::Black);
		Tools::drawGraph(env.window);
        env.window->display();
        sf::sleep(sf::seconds(0.1f));
    }
}

int					main(int ac, char **av)
{
	srand(time(NULL));
	std::cout << "main de demarrage : mettre les test dessous" << std::endl;
	OStats stat(static_cast<unsigned int>(10));
	ADatas dat(stat);
	(void)ac;
	(void)av;
	Ncurses_Mode(dat);
//	test1sfml(dat);
	return 0;
}
