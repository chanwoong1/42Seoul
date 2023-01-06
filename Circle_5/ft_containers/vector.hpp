/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwjeo <chanwjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:10:10 by chanwjeo          #+#    #+#             */
/*   Updated: 2023/01/06 18:17:46 by chanwjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>


template <class T, class Alloc>
class vector {
	public:
		typedef _Allocator                               allocator_type;
		typedef allocator_traits<allocator_type>         __alloc_traits;
		typedef typename __alloc_traits::size_type       size_type;
	protected:
		typedef _Tp                                      value_type;
		typedef value_type&                              reference;
		typedef const value_type&                        const_reference;
		typedef typename __alloc_traits::difference_type difference_type;
		typedef typename __alloc_traits::pointer         pointer;
		typedef typename __alloc_traits::const_pointer   const_pointer;
		typedef pointer                                  iterator;
		typedef const_pointer                            const_iterator;

	
	public:
		explicit vector(const allocator_type& alloc)
};




#endif
