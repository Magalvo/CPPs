/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:43:01 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/21 13:43:01 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float crossproduct(const Point& a, const Point& b, const Point& c)
{
    return (
            b.get_x() - a.get_x()) *
         (c.get_y() - a.get_y()) - 
            (b.get_y() - a.get_y()) * 
         (c.get_x() - a.get_x());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{   
    float cross1 = crossproduct(a, b, point);
    float cross2 = crossproduct(b, c, point);
    float cross3 = crossproduct(c, a, point);

  
    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

    return !(has_neg && has_pos);
}