/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinet <rpinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 21:06:31 by rpinet            #+#    #+#             */
/*   Updated: 2015/06/27 22:22:07 by rpinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

# include <iostream>
# include <string>
# include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>

class Tools
{
    private:
        Tools(Tools const &);
        Tools &operator=(Tools const &);

    public:
        Tools(void);
        ~Tools(void);

        // currently managing fixed size
        /*
        
         */
        static void		drawGraph(sf::RenderWindow *window);
};

#endif /* !TOOLS_HPP */
