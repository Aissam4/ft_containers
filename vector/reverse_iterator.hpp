#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__
#include <iterator>
namespace ft
{
    template<class T>
    class reverse_iterator :  public std::iterator<std::random_access_iterator_tag, T>
    {
        private:
            T   _it;
        public:
            typedef             T                                           reverse_iterator_type;
            typedef typename    std::random_access_iterator_tag             reverse_iterator_category;
            typedef typename    std::iterator_traits<T>::value_type        value_type;
            typedef typename    std::iterator_traits<T>::difference_type   difference_type;
            typedef typename    std::iterator_traits<T>::pointer           pointer;
            typedef typename    std::iterator_traits<T>::reference         reference;
            reverse_iterator( void )
            {
                this->_it = nullptr;
            }
            explicit	reverse_iterator(reverse_iterator_type element)
            {
                this->_it = element;
            }
            template<class RevIter>
            reverse_iterator( const  reverse_iterator<RevIter> &obj)
            {
                this->_it = obj.base();
            }
            reverse_iterator_type   base( void ) const
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
				reverse_iterator	obj(*this);
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

    template <class Iter>
		bool	operator==(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() == S.base());
		}
	template <class Iter>
		bool	operator>(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() > S.base());
		}
	template <class Iter>
		bool	operator<(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() < S.base());
		}
	template <class Iter>
		bool	operator<=(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() <= S.base());
		}
	template <class Iter>
		bool	operator>=(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() >= S.base());
		}
	template <class Iter>
		bool	operator!=(const reverse_iterator<Iter> &F, const reverse_iterator<Iter> &S)
		{
			return (F.base() != S.base());
		}	
}
#endif