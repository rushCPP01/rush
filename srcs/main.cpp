/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:10:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 22:35:27 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Tools.hpp"

void 				test1sfml(int ac, char **av)
{
sf::ContextSettings settings;
settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true); // , un appel suffit, après la création de la fenêtre




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           // on regarde le type de l'évènement...
	   		switch (event.type)
		    {
		        // fenêtre fermée
		        case sf::Event::Closed:
		            window.close();
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

        window.clear(sf::Color::Black);
		Tools::drawGraph(&window);
        window.display();
        sf::sleep(sf::seconds(0.1f));
    }

	(void)ac;
	(void)av;
}

int					main(int ac, char **av)
{
	srand(time(NULL));
	std::cout << "main de demarrage : mettre les test dessous" << std::endl << std::endl;
	
	test1sfml(ac, av);
	return 0;
}
