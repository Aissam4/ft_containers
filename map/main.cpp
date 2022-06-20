#include "map.hpp"
#include <iostream>
#include <map>

int main(void)
{
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert(std::pair<int, int>(10, 10));
	std_map.insert(std::pair<int, int>(20, 20));
	std_map.insert(std::pair<int, int>(200, 20));
	std_map.insert(std::pair<int, int>(2000, 20));
	std_map.insert(std::pair<int, int>(20000, 20));
	std_map.insert(std::pair<int, int>(200000, 20));

	ft_map.insert(ft::pair<int, int>(10, 10));
	ft_map.insert(ft::pair<int, int>(20, 200));
	ft_map.insert(ft::pair<int, int>(200, 2));
	ft_map.insert(ft::pair<int, int>(2000, 20));
	ft_map.insert(ft::pair<int, int>(20000, 2000));
	ft_map.insert(ft::pair<int, int>(200000, 200));


	std::cout << "std::map key -> " << std_map.begin()->first << " | std::map value -> " << std_map.begin()->second << std::endl;
	std::cout << "ft::map key -> " << ft_map.begin()->first << " | std::map value -> " << ft_map.begin()->second << std::endl;
	std::map<int, int>::iterator it = std_map.end();
	ft::map<int, int>::iterator it2 = ft_map.end();
	it--;
	it2--;
	it2--;
	std::cout << "std end of map => " <<  it->first << std::endl;
	std::cout << "ft end of map => " <<  it2->first << std::endl;
	// std::map<int, int> m;
	// m.insert(std::pair<int, int> (10, 20));
	// m.insert(std::pair<int, int> (100, 200));
	// m.insert(std::pair<int, int> (1, 2));

	// std::cout << *(m.begin()) << std::endl;
	// (void)myMap;
}