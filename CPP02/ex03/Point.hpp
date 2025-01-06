/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:43:35 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/21 13:43:35 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
    const Fixed _x;
    const Fixed _y;
    public:
    Point();
    ~Point();
    Point(const float x, const float y);
    Point(const Point& copy);
    Point& operator=(const Point& src);
    float get_x() const;
    float get_y() const;
};


#endif