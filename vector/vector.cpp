/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/14 10:20:51 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
int main(void)
{
	//TODO: testing;
	ft::vector<std::string> vector_str(10);
	std::cout << vector_str.get(2);
}