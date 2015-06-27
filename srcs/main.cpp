/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:10:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 14:14:58 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ADatas.hpp"
#include "CPUDisplay.hpp"
#define KEY_ECHAP 27
#define NCOLOR(x) (x*4)
#define MYGREEN	  57
#define MYRED	  58
#define MYORANGE  59
#define MYBLUE	  60
#define MYYELLOW  61
#define MYMAGENTA 62

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
	CPUDisplay cpu(dat, 5, 5);
	while (input != KEY_ECHAP)
	{
		dat.setInterval(getmaxx(stdscr) / 4);
		erase();
		box(stdscr, '|', '-');
		cpu.displayNcurses();
		input = getch();
		dat.refreshDatas();
		refresh();
		usleep(300000);
	}
	endwin();
}

int					main(int ac, char **av)
{
	std::cout << "main de demarrage : mettre les test dessous" << std::endl;
	OStats stat(static_cast<unsigned int>(10));
	ADatas dat(stat);
	(void)ac;
	(void)av;
	Ncurses_Mode(dat);
	return 0;
}
