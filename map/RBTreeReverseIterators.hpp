/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeReverseIterators.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:29:03 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/21 20:16:24 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RBTREEREVERSEITERATORS_HPP__
#define __RBTREEREVERSEITERATORS_HPP__

#include "RBTreeIterators.hpp"

namespace ft
{
	template < typename RBTreeIter >
	class ReverseRBTreeIter : public RBTreeIter
	{
		public:
			using typename RBTreeIter::value_type;
			using typename RBTreeIter::pointer;
			using typename RBTreeIter::const_pointer;
			using typename RBTreeIter::reference;
			using typename RBTreeIter::const_reference;

			ReverseRBTreeIter() : RBTreeIter() {}
			template<class Ts>
			ReverseRBTreeIter(ReverseRBTreeIter<Ts> const &rhs) : RBTreeIter(rhs) {}
			ReverseRBTreeIter(RBTreeIter const &rhs) : RBTreeIter(rhs) {}
			~ReverseRBTreeIter() {}

			ReverseRBTreeIter &operator=( ReverseRBTreeIter const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseRBTreeIter();
				return *new(this) ReverseRBTreeIter(rhs);
			}

			ReverseRBTreeIter &operator++()
			{
				RBTreeIter::operator--();
				return(*this);
			}

			ReverseRBTreeIter operator++(int)
			{
				ReverseRBTreeIter tmp(*this);
				RBTreeIter::operator--(0);
				return(tmp);
			}

			virtual ReverseRBTreeIter &operator--()
			{
				RBTreeIter::operator++();
				return(*this);
			}
			virtual ReverseRBTreeIter operator--(int)
			{
				ReverseRBTreeIter tmp(*this);
				RBTreeIter::operator++(0);
				return(tmp);
			}
	};		
}
#endif