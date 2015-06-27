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
#include <vector>

void				test_datasinfos(void)
{
	OStats stat(static_cast<unsigned int>(10));
	ADatas dat(stat);
	while (1)
	{
		dat.refreshDatas();
	}
}

int					main(int ac, char **av)
{
	std::cout << "main de demarrage : mettre les test dessous" << std::endl;
	(void)ac;
	(void)av;
	test_datasinfos();
	return 0;
}
