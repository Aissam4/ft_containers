#include "map/map.hpp"
#include <map>
void	map_test( void ){
	ft::map<int, int> ft_map;
	std::map<int, int> std_map;
	for (size_t i = 0; i < 25; i++)
	{
		int num = rand() % 300;
		ft_map.insert(ft::pair<int, int> (num, i));
		std_map.insert(std::pair<int, int> (num, i));
	}
	std::cout << "ft_map test\n" << std::endl;
	for (ft::map<int, int>::iterator it = ft_map.begin() ; it != ft_map.end(); it++)
		std::cout << "Map Key : " << it->first << " | Map Value : " << it->second << std::endl;
	std::cout << "std_map test\n" << std::endl;
	for (std::map<int, int>::iterator it = std_map.begin() ; it != --std_map.end(); it++)
		std::cout << "Map Key : " << it->first << " | Map Value : " << it->second << std::endl;
}