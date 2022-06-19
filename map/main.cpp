#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert(std::pair<int, int>(10, 10));
	std_map.insert(std::pair<int, int>(20, 20));

	ft_map.insert(ft::pair<int, int>(10, 10));
	ft_map.insert(ft::pair<int, int>(20, 20));

	std::cout << "std::map key -> " << std_map.begin()->first << " | std::map value -> " << std_map.begin()->second << std::endl;  
	std::cout << "ft::map key -> " << ft_map.begin()->first << " | ft::map value -> " << ft_map.begin()->second << std::endl;

	// std::map<int, int> m;
	// m.insert(std::pair<int, int> (10, 20));
	// m.insert(std::pair<int, int> (100, 200));
	// m.insert(std::pair<int, int> (1, 2));

	// std::cout << *(m.begin()) << std::endl;
	// (void)myMap;
}