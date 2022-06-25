/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTreeReverseIterators_set.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:29:03 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/25 23:47:06 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RBTREEREVERSEITERATORS_SET_HPP__
#define __RBTREEREVERSEITERATORS_SET_HPP__

#include "RBTreeIterators_set.hpp"

namespace ft
{
	template < typename RBTreeIterSet >
	class ReverseRBTreeIterSet : public RBTreeIterSet
	{
		public:
			using typename RBTreeIterSet::value_type;
			using typename RBTreeIterSet::pointer;
			using typename RBTreeIterSet::const_pointer;
			using typename RBTreeIterSet::reference;
			using typename RBTreeIterSet::const_reference;

			ReverseRBTreeIterSet() : RBTreeIterSet() {}
			template<class Ts>
			ReverseRBTreeIterSet(ReverseRBTreeIterSet<Ts> const &rhs) : RBTreeIterSet(rhs) {}
			ReverseRBTreeIterSet(RBTreeIterSet const &rhs) : RBTreeIterSet(rhs) {}
			~ReverseRBTreeIterSet() {}

			ReverseRBTreeIterSet &operator=( ReverseRBTreeIterSet const &rhs )
			{
				if (this == &rhs) return(*this);
				this->~ReverseRBTreeIterSet();
				return *new(this) ReverseRBTreeIterSet(rhs);
			}

			ReverseRBTreeIterSet &operator++()
			{
				RBTreeIterSet::operator--();
				return(*this);
			}

			ReverseRBTreeIterSet operator++(int)
			{
				ReverseRBTreeIterSet tmp(*this);
				RBTreeIterSet::operator--(0);
				return(tmp);
			}

			virtual ReverseRBTreeIterSet &operator--()
			{
				RBTreeIterSet::operator++();
				return(*this);
			}
			virtual ReverseRBTreeIterSet operator--(int)
			{
				ReverseRBTreeIterSet tmp(*this);
				RBTreeIterSet::operator++(0);
				return(tmp);
			}
	};		
}
#endif