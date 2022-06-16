#ifndef __PAIR_HPP__
#define __PAIR_HPP__
namespace ft
{
	template<typename T1, typename T2>
	class pair{
		public:
			T1	first;
			T2	second;
		pair( void ){
		}
		pair(const pair &obj){
			*this  = obj;
		}
		pair(const T1 &obj1, const T2 &obj2){
			first(obj1);
			second(obj2);
		}
		template<class X, class Y>
		pair(ft::pair<X, Y> &obj){
			first(obj.first);
			second(obj.second);
		}
		~pair( void ){}
		pair	&operator=(const pair &obj){
			if (this != &obj){
				this->first = obj.first;
				this->second = obj.second;
			}
			return (*this);
		}
	};
	template <class T1, class T2>
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first == p2.first && p1.second == p2.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return !(p1 == p2);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first < p2.first || (p1.first == p2.first &&  p1.second < p2.second));
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return (p1.first <= p2.first);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return !(p1 <= p2);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2){
        return !(p1 < p2);
    }
	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
}
#endif