/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprates <lprates@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:32:28 by lprates           #+#    #+#             */
/*   Updated: 2023/01/02 21:29:02 by lprates          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <map>
# include "utils/pairs.hpp"


namespace ft {
	
	template <typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<key_type, mapped_type>						value_type;
			typedef Compare												key_compare;
			typedef Alloc												allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename ft::Map_iterator<Key, T>					iterator;
			typedef typename ft::Map_const_iterator<Key, T>				const_iterator;
			typedef typename ft::Map_reverse_iterator<Key, T>			reverse_iterator;
			typedef typename ft::Map_const_reverse_iterator<Key, T>		const_reverse_iterator;
			
			typedef typename ptrdiff_t							difference_type;
			typedef typename size_t								size_type;

			class value_compare : std::binary_function<value_type, value_type, bool> {
				private:
					friend class map;

				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
	};
}

#endif