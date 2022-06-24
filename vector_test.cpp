#include "vector/vector.hpp"
int main( void )
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