#ifndef MAPITERATOR_HPP

# define MAPITERATOR_HPP

#include <iostream>
#include <iterator>
#include "mapNode.hpp"


namespace ft {

	template<class Key, class T>
	class mapIterator {
//		typedef Key key_type;
//		typedef T mapped_type;

		typedef T value_type;
		typedef Node<Key, T> node;

	private:
		node *p;


	public:

		mapIterator() : p(nullptr) {}

		mapIterator(node *x) : p(x) { }

		mapIterator(const mapIterator& it) : p(const_cast<node *>(it.p)) { }

		~mapIterator() {}

		mapIterator & operator=(const mapIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		}

		value_type  operator * () const  { return (p->date); }
		value_type & operator -> () {return *p; }

//		mapIterator operator ++ () {
//			p = p->next;
//			return (*this);
//		}
//
//		mapIterator operator ++ (int) {
//			mapIterator temp(*this);
//			operator ++();
//			return temp;
//		}
//		mapIterator& operator -- () {
//			p = p->prev;
//			return (*this);
//		}
//		mapIterator& operator -- (int) {
//			mapIterator temp(*this);
//			operator --();
//			return temp;
//		}

		bool operator == (const mapIterator & other) const {return (this->p == other.p); }
		bool operator != (const mapIterator & other) const { return (this->p != other.p); }
		bool operator > (const mapIterator & other) const { return (this->p > other.p); }
		bool operator < (const mapIterator & other) const { return (this->p < other.p); }
		bool operator >= (const mapIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const mapIterator & other) const { return (this->p <= other.p); }

		node*	getp() const { return p; }
	};

}


#endif /*MAPITERATOR_HPP*/