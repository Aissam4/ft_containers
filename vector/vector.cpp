/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/20 20:19:31 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
int main(void)
{
	// TODO: testing;
	std::cout << "std Vector" << std::endl;
	{
		std::vector<std::string> vector_str(5);
		std::cout << vector_str.size() << std::endl;
		std::cout << vector_str.capacity() << std::endl;
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.push_back("Hello4");
		vector_str.push_back("Welcome");
		vector_str.push_back("Welcome");
		vector_str.push_back("Welcome");
		vector_str.push_back("Hello5");
		vector_str.push_back("Hello5");
		vector_str.erase(vector_str.begin() + 1, vector_str.end() - 5);
		for (unsigned int i = 0; i < vector_str.capacity(); i++)
			std::cout << "[" << vector_str[i] << "]" << std::endl;
		std::cout << vector_str.size() << std::endl;
		std::cout << vector_str.capacity() << std::endl;
		// std::cout << vector_str.size() << std::endl;
		// std::cout << vector_str.capacity() << std::endl;
		// vector_str.push_back("Hello5");
		// std::cout << vector_str.size() << std::endl;
		// std::cout << vector_str.capacity() << std::endl;
		// vector_str.erase(vector_str.begin() + 11);
		// for (unsigned int i = 0; i < vector_str.size(); i++)
		// 	std::cout << vector_str[i] << std::endl;
	} 
	std::cout << "ft Vector" << std::endl;
	{
		ft::vector<std::string> vector_str(5);
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.push_back("Hello4");
		vector_str.push_back("Welcome");
		vector_str.push_back("Welcome");
		vector_str.push_back("Welcome");
		vector_str.push_back("Hello5");
		vector_str.push_back("Hello5");
		vector_str.erase(vector_str.begin() + 1, vector_str.end() - 5);
		vector_str.print();
		std::cout << vector_str.size() << std::endl;
		std::cout << vector_str.capacity() << std::endl;
		// vector_str.erase(vector_str.begin() + 11);
		// ft::vector<std::string> vector_str(1);
		// vector_str.push_back("Hello1");
		// vector_str.push_back("Hello2");
		// vector_str.push_back("Hello2");
		// vector_str.push_back("Hello2");
		// vector_str.push_back("Hello2");
		// std::cout << vector_str.capacity() << std::endl;
		// vector_str.reserve(1);
		// std::cout << vector_str.capacity() << std::endl;
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