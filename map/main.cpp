#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	std::cout  << "std map test\n" << std::endl;
	{
		std::map<int, int> std_map;
		std_map.insert(std::pair<int, int>(1, 1));
		std_map.insert(std::pair<int, int>(2, 2));
		std_map.insert(std::pair<int, int>(3, 3));
		std_map.insert(std::pair<int, int>(4, 4));
		std_map.insert(std::pair<int, int>(5, 5));
		std_map.insert(std::pair<int, int>(6, 6));
		std::map<int, int> map(std_map.begin(), std_map.end());
		for (size_t i = 0; i < map.size(); i++)
		{
			std::cout << map[i] << std::endl;
		}
	}

	std::cout  << "ft map test\n" << std::endl;
	{
		ft::map<int, int> ft_map;
		ft_map.insert(ft::pair<int, int>(1, 1));
		ft_map.insert(ft::pair<int, int>(2, 2));
		ft_map.insert(ft::pair<int, int>(3, 3));
		ft_map.insert(ft::pair<int, int>(4, 4));
		ft_map.insert(ft::pair<int, int>(5, 5));
		ft_map.insert(ft::pair<int, int>(6, 6));
		std::cout << "first element =>" << ft_map.begin()->first << std::endl;
		ft::map<int , int> map(ft_map.cbegin(),ft_map.cend());
		map.print();

		// ft::map<int, int>::iterator it = ft_map.begin();
		// ft::map<int, int>::iterator end = ft_map.end();
		// end--;
		// std::cout << end->first << std::endl;
	}
}