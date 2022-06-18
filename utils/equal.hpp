/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:07:27 by abarchil          #+#    #+#             */
/*   Updated: 2022/06/18 15:15:53 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EQUAL_HPP__
#define __EQUAL_HPP__

template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))
      return false;
    ++first1;
	++first2;
  }
  return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
  while (first1!=last1) {
    if (pred(*first1, *first2))
      return false;
    ++first1;
	++first2;
  }
  return true;
}

#endif