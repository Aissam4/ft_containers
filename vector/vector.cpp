/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/14 11:04:32 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
int main(void)
{
	// TODO: testing;
	std::cout << "std Vector" << std::endl;
	{
		std::vector<std::string> vector_str(2);
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello2");
		std::cout << vector_str.front() << std::endl;
	}
	std::cout << "ft Vector" << std::endl;
	{
		ft::vector<std::string> vector_str(2);
		// vector_str.push_back("Hello");
		// vector_str.push_back("Hello2");
		std::cout << vector_str.back() << std::endl;
	}
}