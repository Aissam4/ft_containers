/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/14 10:40:12 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
int main(void)
{
	//TODO: testing;
	// std::cout << "std Vector" << std::endl;
	// {
	// 	std::vector<std::string> vector_str(10);
	// 	std::cout << vector_str.at(20) << std::endl;
	// }
	std::cout << "ft Vector" << std::endl;
	{
		ft::vector<std::string> vector_str(10);
		std::cout << vector_str.at(20) << std::endl;
	}
}