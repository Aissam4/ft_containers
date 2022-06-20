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

		std::map<int , int > map(std_map.begin(), std_map.end());
		// map.print();
		std::map<int, int>::iterator it = map.begin();
		for(; it != map.end(); it++){
			std::cout << "( " << it->first << " ) " << std::endl;
		}
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
		ft_map.insert(ft::pair<int, int>(7, 200));
		ft_map.insert(ft::pair<int, int>(70, 200));
		// ft::map<int, int>::iterator	it = ft_map.begin();
		// it--;
		// ft::map<int, int>::iterator	it2 = ft_map.end();
		// it2++;
		ft::map<int , int > map(ft_map.begin(), ft_map.end());
		map.print();
		// std::map<int, int>::iterator it = map.begin();
		// for(; it != map.end(); it++){
		// 	std::cout << "( " << it->first << " ) " << std::endl;
		// }
	}
	// std::map<int, int> m;
	// m.insert(std::pair<int, int> (10, 20));
	// m.insert(std::pair<int, int> (100, 200));
	// m.insert(std::pair<int, int> (1, 2));

	// std::cout << *(m.begin()) << std::endl;
	// (void)myMap;
}