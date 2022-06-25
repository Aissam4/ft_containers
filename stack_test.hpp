#include "stack/stack.hpp"
void stack_test( void )
{
	ft::stack<int> stack_int;
	for (size_t i = 0; i < 5; i++)
		stack_int.push(rand() % 100000);
	std::cout << "stack_int size is => " << stack_int.size() << std::endl;
	std::cout << "stack top element content : \n";
	std::cout << stack_int.top() << std::endl;
}