/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:48:37 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/25 23:39:56 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "vector/vector.hpp"
#include "stack/stack.hpp"

// #include "map/map.hpp"
#include "set/set.hpp"

void	set_test( void )
{
	ft::set<int> s;
	std::set<int> s_;
	for (int i  = 0; i < 25; i++){
		int num = rand() % 200; 
		s.insert(num);
		s_.insert(num);
	}
	std::cout << "std set \n";
	for (ft::set<int>::iterator it = s.begin(); it != --s.end(); it++){
		std::cout << "set val : " << it.getVal() << std::endl;
	}
	std::cout << "ft set \n";
	for (std::set<int>::iterator it = s_.begin(); it != --s_.end(); it++){
		std::cout << "set val : " << *it << std::endl;
	}
	
}
// void	map_test( void )
// {
// 	ft::map<int, int> ft_map;
// 	std::map<int, int> std_map;
// 	for (size_t i = 0; i < 25; i++)
// 	{
// 		int num = rand() % 300;
// 		ft_map.insert(ft::pair<int, int> (num, i));
// 		std_map.insert(std::pair<int, int> (num, i));
// 	}
// 	std::cout << "ft_map test\n" << std::endl;
// 	for (ft::map<int, int>::iterator it = ft_map.begin() ; it != ft_map.end(); it++)
// 		std::cout << "Map Key : " << it->first << " | Map Value : " << it->second << std::endl;
// 	std::cout << "std_map test\n" << std::endl;
// 	for (std::map<int, int>::iterator it = std_map.begin() ; it != --std_map.end(); it++)
// 		std::cout << "Map Key : " << it->first << " | Map Value : " << it->second << std::endl;
// }

void vector_test( void )
{
	ft::vector<int> vec_int;
	for (size_t i = 0; i < 25; i++)
	{
		vec_int.push_back(rand() % 100000);
	}
	std::cout << "vec_int size is => " << vec_int.size() << std::endl;
	std::cout << "vec_int capacity is => " << vec_int.capacity() << std::endl;
	std::cout << "vector content : \n";
	for (size_t i = 0; i < vec_int.size(); i++)
	{
		std::cout << "[ " << vec_int[i] << " ]" << std::endl;
	}
	std::cout << "vector iterators : \n";
	std::cout << "begin of vecotr => " << *vec_int.begin() << std::endl;
	std::cout << "end of vector => "  << *(vec_int.end() - 1) << std::endl;
	std::cout << "vector reverse iterators : \n";
	std::cout << "rbegin of vecotr => " << *vec_int.rbegin() << std::endl;
	std::cout << "rend of vector => "  << *(vec_int.rend()) << std::endl;
}

void stack_test( void )
{
	ft::stack<int> stack_int;
	for (size_t i = 0; i < 5; i++)
		stack_int.push(rand() % 100000);
	std::cout << "stack_int size is => " << stack_int.size() << std::endl;
	std::cout << "stack top element content : \n";
	std::cout << stack_int.top() << std::endl;
}

int main( void )
{
	std::cout << "---------------- VECTOR TEST ------------------\n";
	vector_test();
	std::cout << "---------------- STACK TEST ------------------\n";
	stack_test();
	std::cout << "---------------- MAP TEST ------------------\n";
	// map_test();
	std::cout << "---------------- SET TEST ------------------\n";
	set_test();
}