/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:57:31 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/13 18:55:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main(void)
{
	// TODO: testing;
	// std::cout << "std Vector" << std::endl;
	// {
	// 	std::vector<std::string> vector_str;
	// 	vector_str.push_back("Hello1");
	// 	vector_str.push_back("Hello2");
	// 	vector_str.push_back("Hello3");
	// 	vector_str.push_back("Hello4");
	// 	std::cout << "last element : " << *(vector_str.end() - 1) << std::endl;
	// 	std::vector<std::string> vec(vector_str.begin(), vector_str.end() - 1);
	// 	std::cout << "size :  " << vec.size() << " capacity " << vec.capacity() << std::endl;
	// 	std::cout << "vec data\n\n";
	// 	for (unsigned int i = 0; i < vec.size(); i++){
	// 		std::cout << "[ " << vec.at(i) << " ]" << std::endl;
	// 	}
	// } 
	std::cout << "==============================================\n";
	std::cout << "ft Vector" << std::endl;
	{
		ft::vector<std::string> vector_str;
		vector_str.push_back("Hello1");
		vector_str.push_back("Hello2");
		vector_str.push_back("Hello3");
		vector_str.push_back("Hello4");
		std::cout << "last element : " << *(vector_str.end() - 1) << std::endl;
		ft::vector<std::string> vec(vector_str.begin(), vector_str.end() - 1);
		std::cout << "size :  " << vec.size() << " capacity " << vec.capacity() << std::endl;
		std::cout << "vec data\n\n";
		for (unsigned int i = 0; i < vec.size(); i++){
			std::cout << "[ " << vec.at(i) << " ]" << std::endl;} 
	}
}
