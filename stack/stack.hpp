#ifndef __STACK_HPP__
#define __STACK_HPP__
#include <iostream>
#include <algorithm>
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        protected:
            Container _container;
        public:
            typedef	T											value_type;
			typedef Container									container_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
            explicit    stack (const container_type &_c = container_type()){
                this->_container = _c;
            }
            bool                empty() const { return (!this->_container.size()); };
            size_t              size() const { return (this->_container.size()); };
            value_type&         top() { return (this->_container.back()); };
            const   value_type& top() const { return (this->_container.back()); };
            void                push(const value_type& _value) { this->_container.push_back(_value); };
            void                pop() {this->_container.pop_back(); };
        protected:
            template <class _T, class _C>
				friend bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
			template <class _T, class _C>
				friend bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs);
    };
    template <class _T, class _C>
		bool operator== (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c == rhs.c); };
	template <class _T, class _C>
		bool operator!= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c != rhs.c); };
	template <class _T, class _C>
		bool operator<  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c < rhs.c); };
	template <class _T, class _C>
		bool operator<= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c <= rhs.c); };
	template <class _T, class _C>
		bool operator>  (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c > rhs.c); };
	template <class _T, class _C>
		bool operator>= (const stack<_T ,_C>& lhs, const stack<_T ,_C>& rhs) { return (lhs.c >= rhs.c); };
}
#endif
