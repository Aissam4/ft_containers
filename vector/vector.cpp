/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/04/21 19:59:01 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main(void)
{
	// TODO: testing;
	std::cout << "std Vector" << std::endl;
	{
		std::vector<std::string> vector_str(5);
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.push_back("Hello4");
		vector_str.shrink_to_fit();
		vector_str.is_int
		std::cout << "size :  " << vector_str.size() << "capacity" << vector_str.capacity() << std::endl;
		std::vector<std::string> vec(vector_str.begin(), vector_str.end());
		std::cout << "size :  " << vec.size() << "capacity" << vec.capacity() << std::endl;
	} 
	std::cout << "==============================================\n";
	std::cout << "ft Vector" << std::endl;
	{
		ft::vector<std::string> vector_str(5);
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.push_back("Hello4");
		vector_str.shrink_to_fit();
		std::cout << "size :  " << vector_str.size() << "capacity" << vector_str.capacity() << std::endl;
		ft::vector<std::string> vec(vector_str.begin(), vector_str.end());
		std::cout << "size :  " << vec.size() << "capacity" << vec.capacity() << std::endl;
	}
}
