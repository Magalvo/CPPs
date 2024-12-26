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

//? (PT)
//? O método do produto vetorial é usado para determinar a orientação relativa do ponto em relação às arestas do triângulo. 
//? Verificando os sinais dos produtos vetoriais, podemos deduzir se o ponto está dentro ou fora do triângulo:
//?     - Se todos os produtos vetoriais tiverem o mesmo sinal, o ponto está dentro.
//?     - Se houver uma mistura de sinais positivos e negativos, o ponto está fora.

//? (EN)
//? The vector product method is used to determine the relative orientation of the point with respect to the edges of the triangle.
//? By checking the signals of the vector products, we can deduce whether the point is inside or outside the triangle:
//?     - If all vector products have the same signal, the point is inside.
//?     - If there is a mix of positive and negative signals, the point is out.

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
    //?(PT) Calculo do produto vetorial com cada aresta do triangulo (cada um dos 3 pontos que formam o triangulo)
    float cross1 = crossproduct(a, b, point); //?Ponto1
    float cross2 = crossproduct(b, c, point); //?Ponto2
    float cross3 = crossproduct(c, a, point); //?Ponto3

  
    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

    return !(has_neg && has_pos);
}