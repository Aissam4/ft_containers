#include "vector_test.hpp"
#include "stack_test.hpp"
#include "map_test.hpp"

int main( void )
{
	std::cout << "---------------- VECTOR TEST ------------------\n";
	vector_test();
	std::cout << "---------------- STACK TEST ------------------\n";
	stack_test();
	std::cout << "---------------- MAP TEST ------------------\n";
	map_test();
}