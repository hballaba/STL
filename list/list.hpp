#ifndef LIST_HPP

# define LIST_HPP

# include <iostream>

template<class T>
struct Node {
	T *date;
	Node *next;
	Node *prew;
};

namespace ft {

template< class T, class Alloc = std::allocator<T> >
	class list {

	public:
		typedef 	T value_type;
		typedef 	Alloc allocator_type;
		typedef 	typename allocator_type::reference 	reference;
		typedef 	typename allocator_type::const_reference const_reference;
		typedef 	typename allocator_type::pointer pointer;
		typedef 	typename allocator_type::const_pointer const_pointer;
		// typedef 	ft::myIterator<value_type> iterator;
		// typedef 	ft::constMyIterator<value_type> const_iterator;
		// typedef		ft::reversMyIterator<value_type> reverse_iterator;
		// typedef		ft::reversConstMyIterator<value_type> const_reverse_iterator;
		typedef		ptrdiff_t difference_type;
		typedef		size_t size_type;
		//typedef		std::allocator<T> type_alloc;
		typedef		<value_type> * node;

	private:
		node *_begin;
		node *_end;
		size_t _size;
		allocator_type _alloc;
		template <class T, class Alloc>
  void swap (list<T,Alloc>& x, list<T,Alloc>& y);

template <class T, class Alloc>
  bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  if (lhs.size() != rhs.size())
			return (false);
		typename List<T>::const_iterator cur1 = lhs.begin();
		typename List<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*(cur1++) != *(cur2++))
				return (false);
		}
		return (true);
  };

template <class T, class Alloc>
  bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  return (!(lhs == rhs));
  };

template <class T, class Alloc>
  bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		typename List<T>::const_iterator cur1 = lhs.begin();
		typename List<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*cur1 != *cur2)
				return (*cur1 < *cur2);
			cur1++;
			cur2++;
		}	
		return (false);
  };

template <class T, class Alloc>
  bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  return (!(rhs < lhs));
  };

template <class T, class Alloc>
  bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  return (rhs < lhs);
  };

template <class T, class Alloc>
  bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
	  return (!(lhs < rhs));
  };


		//need metods
		//newNode


		



	public:
		explicit list (const allocator_type& alloc = allocator_type()) :
			_begin(nullptr),
			_end(nullptr),
			_alloc(alloc),
			_size(0) {} ;
		
		explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
				;
		
		template <class InputIterator>
  		list (InputIterator first, InputIterator last,
        		const allocator_type& alloc = allocator_type()) {
			

		};
		
		list (const list& x) {*this = x; };

		~list() {
			//clear;
			// null cheсk 
			//_alloc.dealocate(_begin);
			//_alloc.dealocate(_end);

		};

		list& operator= (const list& x);

		reference front(void)
			{
				return (_list_begin->next->data);
			};









	};

}

#endif /*LIST_HPP*/