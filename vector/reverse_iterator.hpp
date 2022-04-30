#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__
#include "Iterator.hpp"
#include "vector.hpp"
namespace ft
{
    template<class T>
    class reverse_iterator : public std::reverse_iterator<std::random_access_iterator_tag, T>
    {
        private:
            T   _it;
        public:
            typedef typename    T                                           reverse_iterator_type;
            typedef typename    std::reverse_iterator<T>::value_type        value_type;
            typedef typename    std::random_access_iterator_tag             reverse_iterator_tag;
            typedef typename    std::reverse_iterator<T>::difference_type   difference_type;
            typedef typename    std::reverse_iterator<T>::pointer           pointer;
            typedef typename    std::reverse_iterator<T>::reference         reference;

            reverse_iterator( void )
            {
                this->_it = nullptr;
            }
            reverse_iterator(reverse_iterator_type element)
            {
                this->_it = element;
            }
            template<class RevIter>
            reverse_iterator( const  reverse_iterator<RevIter> &obj)
            {
                this->_it = obj.base();
            }
            reverse_iterator_type   base( void )
            {
                return (this->_it);
            }
            reverse_iterator    operator+(difference_type _n) const
            {
                return(reverse_iterator(this->_it + _n));
            }
            reverse_iterator    operator-(difference_type _n) const
            {
                return(reverse_iterator(this->_it - _n));
            }
            reverse_iterator&	operator+=(difference_type _n)
			{
				this->_it += _n;
				return (*this);
			}
			reverse_iterator&	operator-=(difference_type _n)
			{
				this->_it -= _n;
				return (*this);
			}
			reverse_iterator&	operator++( void )
			{
				++this->_it;
				return (*this);
			}
			reverse_iterator&	operator--( void )
			{
				--this->_it;
				return (*this);
			}
			reverse_iterator	operator++( int )
			{
				reverse_iterator	obj(*this);
				++(*this);
				return (obj);
			}
			reverse_iterator	operator--( int )
			{
				reverse_iterator_Type	obj(*this);
				--(*this);
				return (obj);
			}
			reference	operator*() const
			{
				return (*this->_it);
			}
			pointer		operator->()
			{
				return (&(operator*()));
			}
			reference	operator[](difference_type n)
			{
				return (*(this->_it + n));
			}
    };


    template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator==(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() == S.base());
		}
	template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator>(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() > S.base());
		}
	template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator<(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() < S.base());
		}
	template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator<=(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() <= S.base());
		}
	template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator>=(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() >= S.base());
		}
	template <class F_reverse_iterator, class S_reverse_iterator>
		bool	operator!=(const reverse_iterator<F_reverse_iterator> &F, const reverse_iterator<S_reverse_iterator> &S)
		{
			return (F.base() != S.base());
		}	
}
#endif