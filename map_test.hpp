#include "map/map.hpp"
#include <map>
void	map_test( void ){
	ft::map<int, int> ft_map;
	std::map<int, int> std_map;
	for (size_t i = 0; i < 25; i++)
	{
		ft_map.insert(ft::pair<int, int> (rand() %200, i));
		std_map.insert(std::pair<int, int> (rand() %200, i));
	}
	std::cout << "ft_map test\n" << std::endl;
	for (size_t i = 0; i < ft_map.size(); i++){
		// std::cout << ft_map[i] << std::endl;
	}

}