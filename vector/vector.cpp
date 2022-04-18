/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/18 16:06:25 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
int main(void)
{
	// TODO: testing;
	std::cout << "std Vector" << std::endl;
	{
		std::vector<std::string> vector_str(3);
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.reserve(10);
	}
	std::cout << "ft Vector" << std::endl;
	{
		// ft::vector<std::string> vector_str(1);
		// vector_str.push_back("Hello1");
		// vector_str.push_back("Hello2");
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
		// std::cout << "=====================" << std::endl;
		// vector_str.push_back("Hello3");
		// vector_str.push_back("Hello4");
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
		// std::cout << "=====================" << std::endl;
		// vector_str.push_back("Hello5");
		// vector_str.push_back("Hello6");
		// vector_str.push_back("Hello7");
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
		// std::cout << "=====================" << std::endl;
		// vector_str.push_back("Hello8");
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
		// std::cout << "=======Pop_Back Test==============" << std::endl;
		// vector_str.pop_back();
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
		// vector_str.pop_back();
		// std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// vector_str.print();
	}
}