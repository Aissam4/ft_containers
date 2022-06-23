#include "map.hpp"
#include <iostream>
#include <map>
#include <vector>
int main(void)
{
	/******** itertaror Test ****************/
	// std::vector<int> vec;
	// int num;
	// for (int i =0; i < 500; i++){
	// 	num = rand() %200;
	// 	vec.push_back(num);
	// 	// std::cout << "[ " << num << " ]" << std::endl;
	// }
	// std::cout  << "\n\nstd map test\n" << std::endl;
	// std::map<int, int> std_map;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	std_map.insert(std::pair<int, int>(vec[i], 0));
	// // std_map.erase(199);
	// std::map<int, int>::iterator it = std_map.begin();
	// std::map<int, int>::reverse_iterator it2 = std_map.rbegin();
	// std::map<int, int>::iterator it3 = std_map.end();
	// std::map<int, int>::reverse_iterator it4  = std_map.rend();
	// // std_map.erase(--it3);
	// it3--;
	// it4--;
	// std::cout << "begin of std::map => " << it->first << std::endl;
	// std::cout << "end of std::map => " << it3->first << std::endl;
	// std::cout << "rend of std::map => " << it2->first << std::endl;
	// std::cout << "rbegin of std::map => " << it4->first << std::endl;

	// std::cout  << "-----------------------\nft map test\n" << std::endl;
	// ft::map<int, int> ft_map;
	// for (size_t i = 0; i < vec.size(); i++)
	// 	ft_map.insert(ft::pair<int, int>(vec[i], 0));
	// ft::map<int, int>::iterator it_ = ft_map.begin();
	// ft::map<int, int>::reverse_iterator it2_ = ft_map.rbegin();
	// ft::map<int, int>::iterator it3_ = ft_map.end();
	// ft::map<int, int>::reverse_iterator it4_  = ft_map.rend();
	// it3--;
	// it4--;
	// std::cout << "begin of std::map => " << it_->first << std::endl;
	// std::cout << "end of std::map => " << it3_->first << std::endl;
	// std::cout << "rend of std::map => " << it2_->first << std::endl;
	// std::cout << "rbegin of std::map => " << it4_->first << std::endl;

	/*********************** erase test ***********************/
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;
	for (int i = 0; i < 10; i++){
		std_map.insert(std::pair<int, int>(i, i));
		ft_map.insert(ft::pair<int, int> (i, i));
	}
	std::cout << "ft_map" << std::endl;
	ft_map.print();
	std::cout<< "std_map" << std::endl;
	for (size_t i = 0; i < std_map.size(); i++)
		std::cout << std_map[i] << std::endl;
	std::cout << "after insertion\n";
	ft::map<int, int> mp;
	mp.insert(ft::pair<int , int>(10, 10));
	mp.insert(ft::pair<int , int>(12, 10));
	mp.insert(ft::pair<int , int>(13, 10));
	mp.insert(ft::pair<int , int>(14, 10));
	ft::map<int , int>::iterator it = mp.begin();
	it++;
	mp.erase(mp.begin(), it);
	mp.print();
}