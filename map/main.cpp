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
		std::map<int, int>::iterator it = std_map.begin();
		std::map<int, int>::reverse_iterator it2 = std_map.rend();
		// it++;
		std::cout << "begin of std::map => " << it->first << std::endl;
		std::cout << "rend of std::map => " << it2->first << std::endl;
		// for (size_t i = 0; i < map.size(); i++)
		// {
		// 	std::cout << map[i] << std::endl;
		// }
	}

	std::cout  << "-----------------------\nft map test\n" << std::endl;
	{
		ft::map<int, int> ft_map;
		ft_map.insert(ft::pair<int, int>(1, 1));
		ft_map.insert(ft::pair<int, int>(2, 2));
		ft_map.insert(ft::pair<int, int>(3, 3));
		ft_map.insert(ft::pair<int, int>(4, 4));
		ft_map.insert(ft::pair<int, int>(5, 5));
		ft_map.insert(ft::pair<int, int>(6, 6));
		// ft::map<int, int>::iterator it = ft_map.begin();
		// std::cout << it->first << std::endl;
		ft::map<int, int>::iterator it = ft_map.begin();
		ft::map<int, int>::reverse_iterator it2 = ft_map.rend();
		// it++;
		std::cout << "begin of std::map => " << it->first << std::endl;
		std::cout << "rend of std::map => " << it2->first << std::endl;
		// ft::map<int, int>::iterator it = ft_map.begin();
		// ft::map<int, int>::iterator end = ft_map.end();
		// end--;
		// std::cout << end->first << std::endl;
	}
}