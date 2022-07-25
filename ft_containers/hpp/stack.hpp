/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:58:49 by lmarzano          #+#    #+#             */
/*   Updated: 2022/07/22 11:23:49 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

//	INCLUDES
# include "vector.hpp"

//	CLASSES
namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

			container_type	container;

			explicit stack(const Container& cont = Container()) : container(cont) {};
			~stack() {};

			stack& operator=(const stack& op)
			{
				container = op.container;
				return *this;
			}

			reference top() { return container.back(); }

			const_reference top() const { return container.back(); }

			bool empty() const { return container.empty(); }

			size_type size() const { return container.size(); }

			void push(const value_type& value) { container.push_back(value); }

			void pop() { container.pop_back(); }
	};

	template< class T, class Container >
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container == rhs.container; }

	template< class T, class Container >
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container != rhs.container; }

	template< class T, class Container >
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container < rhs.container; }

	template< class T, class Container >
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container <= rhs.container; }

	template< class T, class Container >
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container > rhs.container; }

	template< class T, class Container >
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{ return lhs.container >= rhs.container; }

}

#endif