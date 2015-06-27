/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 21:06:31 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 22:53:57 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tools.hpp"

/*
**  Constructors.
*/
Tools::Tools(void)
{ }

Tools::~Tools(void)
{ }


void 	Tools::drawGraph(sf::RenderWindow *window) {

std::vector<sf::Vertex> pts;
// sf::Vector2f(500, 500); // for origin
float posX = 100;
float posY = 300;


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
window->draw(text);
//vector<int> values.size()
for (int i = 0; i < 50; i++)
{
	pts.push_back(sf::Vertex(sf::Vector2f(posX + (i * 5), posY - rand() % 100), sf::Color::Red));
}

window->draw(&pts[0], pts.size(), sf::LinesStrip);

//(void)values;
}
