#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	std::cout  << "std map test\n" << std::endl;
	{
		std::map<int, int> std_map;
		std_map.insert(std::pair<int, int>(1, 10));
		std_map.insert(std::pair<int, int>(2, 200));
		std_map.insert(std::pair<int, int>(3, 2));
		std_map.insert(std::pair<int, int>(4, 20));
		std_map.insert(std::pair<int, int>(5, 2000));
		std_map.insert(std::pair<int, int>(6, 200));
		std::map<int, int>::iterator it = std_map.begin();
		it++;
		it++;
		std::cout << it->first << std::endl;
	}

	std::cout  << "ft map test\n" << std::endl;
	{
		ft::map<int, int> ft_map;
		ft_map.insert(ft::pair<int, int>(1, 10));
		ft_map.insert(ft::pair<int, int>(2, 200));
		ft_map.insert(ft::pair<int, int>(3, 2));
		ft_map.insert(ft::pair<int, int>(4, 20));
		ft_map.insert(ft::pair<int, int>(5, 2000));
		ft_map.insert(ft::pair<int, int>(6, 200));
		// ft_map.print();
		ft::map<int, int>::iterator it = ft_map.begin();
		// std::cout << "======" << std::endl;
		it++;
		it++;
		std::cout << it->first << std::endl;
	}
}