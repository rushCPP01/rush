/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:10:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/28 21:34:40 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ADatas.hpp"
#include "CPUDisplay.hpp"
#include "InfosDisplay.hpp"
#include "ProcessDisplay.hpp"
#include "LoadADisplay.hpp"
#include "MemoryDisplay.hpp"
#include "NetworkDisplay.hpp"
#include "DiskDisplay.hpp"
#include <cstring>
#define KEY_ECHAP 27
#define NCOLOR(x) (x*4)
#define MYGREEN	  67
#define MYRED	  68
#define MYORANGE  69
#define MYBLUE	  70
#define MYYELLOW  71
#define MYMAGENTA 72
#define MYGREY	  7

void				colorsDefines(void)
{
	init_color(MYGREEN, 156, 696, 384);
	init_color(MYRED, 768, 228, 172);
	init_color(MYORANGE, 920, 504, 136);
	init_color(MYBLUE, NCOLOR(41), NCOLOR(128), NCOLOR(185));
	init_color(MYYELLOW, NCOLOR(241), NCOLOR(196), NCOLOR(15));
	init_color(MYMAGENTA, NCOLOR(142), NCOLOR(68), NCOLOR(173));
	init_color(MYGREY, NCOLOR(127), NCOLOR(140), NCOLOR(141));
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
	init_pair(53, COLOR_BLACK, MYGREY);
}

void				Ncurses_Mode(ADatas& dat, char **av)
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
	ProcessDisplay process(dat, 2, 13);
	CPUDisplay cpu(dat, 2, 21);
	LoadADisplay LoadAv(dat, 2, 21 + getmaxy(stdscr) / 4);
	MemoryDisplay Mem(dat, 2, 21 + (getmaxy(stdscr) / 4) + 7);
	NetworkDisplay Net(dat, 2, getmaxy(stdscr) - 25);
	DiskDisplay Disk(dat, 2, getmaxy(stdscr) - 21);
	while (input != KEY_ECHAP)
	{
		dat.setInterval((getmaxx(stdscr) - 8) / 2);
		erase();
		box(stdscr, '|', '-');
		cpu.displayNcurses();
		infos.displayNcurses();
		process.displayNcurses();
		LoadAv.displayNcurses();
		Mem.displayNcurses();
		Net.displayNcurses();
		Disk.displayNcurses();
		input = getch();
		dat.refreshDatas();
		refresh();
		usleep(30000);
	}
	endwin();



	(void)av;
}

void 				sfmlMode(ADatas &env, char **av)
{
	env.settings.antialiasingLevel = 8;
    env.window = new sf::RenderWindow(sf::VideoMode(1800, 1200), "SFML works!", sf::Style::Default, env.settings);
    env.window->setVerticalSyncEnabled(true); // , un appel suffit, après la création de la fenêtre
    /* load font */
	if (!env.font.loadFromFile("misc/Calibri.ttf")) {
		std::cout << "Font loading error." << std::endl; exit(0);
	}
	/* licorne */
	sf::CircleShape shape(100);
	sf::Texture texture;
	if (!texture.loadFromFile("misc/licorne.png")) {
		std::cout << "mais ou est la licorne ..." << std::endl;
    	exit (0);
	}
	shape.setTexture(&texture); // texture est un sf::Texture
	shape.setTextureRect(sf::IntRect(10, 10, 300, 300));
	/* data */
	env.setInterval(env.window->getSize().x / 4);
	CPUDisplay cpu(env, 2, 21);
	InfosDisplay infos(env, 2, 2);
	ProcessDisplay process(env, 2, 13);
 	LoadADisplay LoadAv(env, 2, 21 + env.window->getSize().y / 4);
 	//MemoryDisplay Mem(env, 2, 21 + (env.window->getSize().y / 4) + 7);
 	MemoryDisplay Mem(env, 2, 30);
	NetworkDisplay Net(env, 2, env.window->getSize().y - 25);
	DiskDisplay Disk(env, 2, env.window->getSize().y - 21);
    while (env.window->isOpen())
    {
		env.refreshDatas();
        sf::Event event;
        //dat.setInterval((event.size.width - 8) / 2);
        while (env.window->pollEvent(event))
        {
	   		switch (event.type)
		    {
		        case sf::Event::Closed:
		            env.window->close();
		            break;
		        case sf::Event::Resized:
		      //       std::cout << "new width: " << event.size.width << std::endl;
	    			// std::cout << "new height: " << event.size.height << std::endl;
		            break;
		        case sf::Event::KeyPressed:
		            break;
		        // on ne traite pas les autres types d'évènements
		        default:
		            break;
		    }

        }
        env.window->clear(sf::Color::Black);
		env.window->draw(shape);
        cpu.displayQt();
        infos.displayQt();
        process.displayQt();
 		LoadAv.displayQt();
 		Mem.displayQt();
 		Net.displayQt();
 		Disk.displayQt();
        /* print on screen */
        env.window->display();
        sf::sleep(sf::seconds(0.01f));
    }

	(void)av;
}


// int 				check_module(char *s, char **av)
// {
// 	int 			i;

// 	i = 0;
// 	while (av)
// 	{
// 		if (av[i] == s)

// 	}
// }

void 				print_help(void)
{
	std::cout << "usage : DYLD_FRAMEWORK_PATH=`pwd`\"/SFML/Frameworks\" ./ft_gkrellm [options] [modules ...]\n\n";
	std::cout << "\toptions: \n\t\t-n\tfor ncurses display\n\t\t-g for graphics display (SMFL)\n";
	std::cout << "write each module like this -> module1 module2 module3 ...\n";
	std::cout << "\tlist of modules:\n\t\tcpu\n\t\tdisk\n\t\tinfos\n\t\tload\n\t\tmemory\n\t\tnetwork\n\t\tprocess\n";
}

void 				launch(ADatas *dat, char **av)
{
	//mieux faire fork
	Ncurses_Mode(*dat, av);
	sfmlMode(*dat, av);
	std::cout << "\n\n\nBye" << std::endl;
	return;
}

void 				check_arg(int ac, char **av, ADatas *dat)
{
	switch (ac)
	{
		case 1:
			print_help();
		break;
		case 2:
			if (strcmp(av[1], "-n") != 0 && strcmp(av[1], "-g") != 0 && strcmp(av[1], "-ng") != 0)
				print_help();
			else {
				if (strcmp(av[1], "-ng") == 0 || strcmp(av[1], "-gn") == 0)
					launch(dat, av);
				else if (strcmp(av[1], "-n") == 0)
					Ncurses_Mode(*dat, av);
				else
					sfmlMode(*dat, av);
			}
		break;
		default:
			Ncurses_Mode(*dat, av);
			sfmlMode(*dat, av);
		break;
	}
	(void)av;
}

// DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./ft_gkrellm
int					main(int ac, char **av)
{
	srand(time(NULL));
	std::string mod = "0000000";
	OStats stat(static_cast<unsigned int>(10));
	ADatas dat(stat);
	check_arg(ac, av, &dat);
	(void)mod;
	return 0;
}
