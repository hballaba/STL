#ifndef ITERATOR_HPP

#define ITERATOR_HPP

#include "utils.hpp"
#include <iostream>
#include <iterator>

namespace ft {

	template <class T>

	//template </*class Category, */class T, class Distance = ptrdiff_t,	class Pointer = T*, class Reference = T&>
	class myIterator : public std::iterator<std::bidirectional_iterator_tag, T> {

		typedef T         value_type;
//		typedef Distance  difference_type;
		typedef T*   pointer;
//		typedef Reference reference;
		//typedef Category  iterator_category;

	private:
		pointer p;

	public:

		myIterator() : p(nullptr) { }

		myIterator(value_type *x) : p(x) {}

		myIterator(myIterator& it) : p(it.p) {}

		myIterator & operator=(const myIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);

		};



		bool operator == (const myIterator & other) const  {return (p == other.p); }
		bool operator != (const myIterator & other) { return (p != other.p);	}
		T& operator * () { return *p; }
		T& operator -> () {return *p; }

		myIterator operator ++ () {++p; return *this; }
		myIterator operator ++(int) {
			myIterator temp(*this);
			operator ++();
			return temp;
		}

		myIterator& operator -- () {
			--p;
			return *this;
		}

		myIterator& operator --(int) {
			myIterator temp(*this);
			operator --();
			return temp;
		}
		//*a++
		//*a--
		//*a = t
//		a + n
//		n + a
//		a - n
//		a - b
//		a < b
//		a > b
//		a <= b
//		a >= b
//		a += n
//		a -= n
//		a[n]

	};




	template <class T>
	class randomIterator {
		
	public:
		randomIterator() {}

		randomIterator operator++ () {

		}
		randomIterator operator++ (int) {

		}
		randomIterator operator-- () {

		}

		randomIterator operator-- (int) {

		}




	};






}



#endif /*ITERATOR_HPP*/

