/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-hano <sel-hano@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:27:44 by sel-hano          #+#    #+#             */
/*   Updated: 2024/04/30 15:27:45 by sel-hano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(3, 2);
    Point b(2, 1);
    Point c(1, 3);
    Point point(2, 2);
    bool res = bsp(a, b, c, point);
    if (!res)
        std::cout << "out area of triangle" << std::endl;
    else
        std::cout << "in area of triangle" << std::endl;
    return 0;
}