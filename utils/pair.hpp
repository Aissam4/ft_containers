#ifndef __PAIR_HPP__
#define __PAIR_HPP__
namespace ft{

template<class T1, class T2>
class pair{
	public:
		T1	first;
		T2	second;
	pair( void ){
		first();
		second();
	}
	pair(const pair &obj){
		*this  = obj;
	}
	pair(const T1 &obj1, const T2 &obj2){
		first(obj1);
		second(obj2);
	}
}
}
#endif