/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 14:10:22 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 20:53:39 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

void 				test1sfml(int ac, char **av)
{
sf::ContextSettings settings;
settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true); // , un appel suffit, après la création de la fenêtre
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Green);

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
text.setPosition(150.0f, 100.0f);

sf::ConvexShape convex;// crée une forme vide
convex.setPointCount(5);// définit le nombre de points (5)
// définit les points
convex.setPoint(0, sf::Vector2f(200, 400));
convex.setPoint(1, sf::Vector2f(190, 300));
convex.setPoint(2, sf::Vector2f(800, 400));
convex.setPoint(3, sf::Vector2f(200, 200));
convex.setPoint(4, sf::Vector2f(150, 500));
text.setColor(sf::Color(150, 255, 0, 100));

sf::Vertex line[] = {
    sf::Vertex(sf::Vector2f(10, 100)),
    sf::Vertex(sf::Vector2f(150, 200))
};

// création d'un tableau de 3 vertex définissant un triangle
sf::VertexArray triangle(sf::Triangles, 3);

// on définit la position des sommets du triangle
triangle[0].position = sf::Vector2f(10, 10);
triangle[1].position = sf::Vector2f(100, 10);
triangle[2].position = sf::Vector2f(100, 100);

// on définit la couleur des sommets du triangle
triangle[0].color = sf::Color::Red;
triangle[1].color = sf::Color::Blue;
triangle[2].color = sf::Color::Green;

std::vector<sf::Vertex> vertices;
vertices.push_back(sf::Vertex(sf::Vector2f(500, 500), sf::Color::Red));
vertices.push_back(sf::Vertex(sf::Vector2f(510, 480), sf::Color::Red));
vertices.push_back(sf::Vertex(sf::Vector2f(520, 500), sf::Color::Red));
vertices.push_back(sf::Vertex(sf::Vector2f(530, 450), sf::Color::Red));
vertices.push_back(sf::Vertex(sf::Vector2f(540, 400), sf::Color::Red));
vertices.push_back(sf::Vertex(sf::Vector2f(550, 480), sf::Color::Red));



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

            // récupération de la taille de la fenêtre
			//sf::Vector2u size = window.getSize();
			//unsigned int width = size.x;
			//unsigned int height = size.y;

        }

        window.clear(sf::Color::Black);
        //window.draw(circle);
        window.draw(text);
        //window.draw(convex);
		window.draw(line, 2, sf::Lines);
		window.draw(triangle);

		window.draw(&vertices[0], vertices.size(), sf::LinesStrip);
        window.display();
    }

	(void)ac;
	(void)av;
}

int					main(int ac, char **av)
{
	std::cout << "main de demarrage : mettre les test dessous" << std::endl << std::endl;
	
	test1sfml(ac, av);
	return 0;
}
