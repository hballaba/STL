#ifndef ITERATOR_HPP

#define ITERATOR_HPP

//#include "utils.hpp"
#include <iostream>
#include <iterator>

namespace ft {

	template <class T>

	//template </*class Category, */class T, class Distance = ptrdiff_t,	class Pointer = T*, class Reference = T&>
	class myIterator : public std::iterator<std::bidirectional_iterator_tag, T> {

		typedef T         value_type;
//		typedef Distance  difference_type;
		typedef T*   pointer;
		typedef T& reference;
		//typedef Category  iterator_category;

	private:
		pointer p;

	public:

		myIterator() : p(nullptr) { }

		myIterator(value_type *x) : p(x) {}

		myIterator(const myIterator& it) : p(it.p) {}

		~myIterator() { }

		myIterator & operator=(const myIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		};
		
		value_type& operator * () { return *p; }
		value_type& operator -> () {return p; }

		myIterator operator ++ () {++p; return (*this); }
		myIterator operator ++ (int) {
			myIterator temp(*this);
			operator ++();
			return temp;
		}
		myIterator& operator -- () {--p; return (*this); }
		myIterator& operator -- (int) {
			myIterator temp(*this);
			operator --();
			return temp;
		}
		myIterator& operator += (int n) {
				if (n > 0) {
					while (n-- > 0) // n positive
						operator++(); 
					return (*this);	
				}
				while (n++ < 0) // n negative
					operator--();
				return (*this);
		}
		myIterator& operator -= (int n) {
			if (n > 0) {
				while (n-- > 0) // n positive
					operator--(); 
				return (*this);	
			}
			while (n++ < 0)
				operator++();
			return (*this);
		}
		myIterator operator - (int n) const {
			myIterator temp(*this);
			temp -= n;
			return (temp);
		}
		myIterator operator + (int n) const {
			myIterator temp(*this);
			temp += n;
			return (temp);
		}
	
		bool operator == (const myIterator & other) const {return (this->p == other.p); }
		bool operator != (const myIterator & other) const { return (this->p != other.p); }
		bool operator > (const myIterator & other) const { return (this->p > other.p); }
		bool operator < (const myIterator & other) const { return (this->p < other.p); }
		bool operator >= (const myIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const myIterator & other) const { return (this->p <= other.p); }

		value_type & operator [] (int n) const { return (*(*this + n)); }
	};

			
			/*************   Const Iterator   *************/

	template <class T>

	//template </*class Category, */class T, class Distance = ptrdiff_t,	class Pointer = T*, class Reference = T&>
	class constMyIterator : public std::iterator<std::bidirectional_iterator_tag, T> {

		typedef T         value_type;
//		typedef Distance  difference_type;
		typedef T*   pointer;
		typedef T& reference;
		//typedef Category  iterator_category;

	private:
		pointer p;

	public:

		constMyIterator() : p(nullptr) { }

		constMyIterator(value_type *x) : p(x) {}

		constMyIterator(const constMyIterator& it) : p(it.p) {}

		~constMyIterator() { }

		constMyIterator & operator = (const constMyIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		};
		
		const value_type& operator * () { return *p; }
		const value_type& operator -> () {return p; }

		constMyIterator& operator ++ () {++p; return (*this); }
		constMyIterator operator ++ (int) {
			constMyIterator temp(*this);
			operator ++();
			return temp;
		}
		constMyIterator& operator -- () {--p; return (*this); }
		constMyIterator operator -- (int) {
			constMyIterator temp(*this);
			operator --();
			return temp;
		}
		constMyIterator& operator += (int n) {
				if (n > 0) {
					while (n-- > 0) // n positive
						operator++(); 
					return (*this);	
				}
				while (n++ < 0) // n negative
					operator--();
				return (*this);
		}
		constMyIterator& operator -= (int n) {
			if (n > 0) {
				while (n-- > 0) // n positive
					operator--(); 
				return (*this);	
			}
			while (n++ < 0)
				operator++();
			return (*this);
		}
		constMyIterator operator - (int n) const {
			constMyIterator temp(*this);
			temp -= n;
			return (temp);
		}
		constMyIterator operator + (int n) const {
			constMyIterator temp(*this);
			temp += n;
			return (temp);
		}
	
		bool operator == (const constMyIterator & other) const {return (this->p == other.p); }
		bool operator != (const constMyIterator & other) const { return (this->p != other.p); }
		bool operator > (const constMyIterator & other) const { return (this->p > other.p); }
		bool operator < (const constMyIterator & other) const { return (this->p < other.p); }
		bool operator >= (const constMyIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const constMyIterator & other) const { return (this->p <= other.p); }

		const value_type & operator [] (int n) const { return (*(*this + n)); }
	};



			/*************   Revers Iterator   *************/

	template <class T>

	//template </*class Category, */class T, class Distance = ptrdiff_t,	class Pointer = T*, class Reference = T&>
	class reversMyIterator : public std::iterator<std::bidirectional_iterator_tag, T> {

		typedef T         value_type;
//		typedef Distance  difference_type;
		typedef T*   pointer;
		typedef T& reference;
		//typedef Category  iterator_category;

	private:
		pointer p;

	public:

		reversMyIterator() : p(nullptr) { }

		reversMyIterator(value_type *x) : p(x) {}

		reversMyIterator(const reversMyIterator& it) : p(it.p) {}

		~reversMyIterator() { }

		reversMyIterator & operator = (const reversMyIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		};
		
		const value_type& operator * () { return *p; }
		const value_type& operator -> () {return p; }

		reversMyIterator& operator ++ () {--p; return (*this); }
		reversMyIterator operator ++ (int) {
			reversMyIterator temp(*this);
			operator --();
			return temp;
		}
		reversMyIterator& operator -- () {++p; return (*this); }
		reversMyIterator operator --(int) {
			reversMyIterator temp(*this);
			operator +();
			return temp;
		}
		reversMyIterator& operator +=(int n) {
				if (n > 0) {
					while (n-- > 0) // n positive
						operator--(); 
					return (*this);	
				}
				while (n++ < 0) // n negative
					operator++();
				return (*this);
		}
		reversMyIterator& operator -=(int n) {
			if (n > 0) {
				while (n-- > 0) // n positive
					operator++(); 
				return (*this);	
			}
			while (n++ < 0)
				operator--();
			return (*this);
		}
		reversMyIterator operator -(int n) const {
			reversMyIterator temp(*this);
			temp += n;
			return (temp);
		}
		reversMyIterator operator +(int n) const {
			reversMyIterator temp(*this);
			temp -= n;
			return (temp);
		}
	
		bool operator == (const reversMyIterator & other) const {return (this->p == other.p); }
		bool operator != (const reversMyIterator & other) const { return (this->p != other.p); }
		bool operator > (const reversMyIterator & other) const { return (this->p > other.p); }
		bool operator < (const reversMyIterator & other) const { return (this->p < other.p); }
		bool operator >= (const reversMyIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const reversMyIterator & other) const { return (this->p <= other.p); }

		const value_type & operator [] (int n) const { return (*(*this + n)); }
	};

	/*************   Revers Const Iterator   *************/

	template <class T>

	//template </*class Category, */class T, class Distance = ptrdiff_t,	class Pointer = T*, class Reference = T&>
	class reversConstMyIterator : public std::iterator<std::bidirectional_iterator_tag, T> {

		typedef T         value_type;
//		typedef Distance  difference_type;
		typedef T*   pointer;
		typedef T& reference;
		//typedef Category  iterator_category;

	private:
		pointer p;

	public:

		reversConstMyIterator() : p(nullptr) { }

		reversConstMyIterator(value_type *x) : p(x) {}

		reversConstMyIterator(const reversConstMyIterator& it) : p(it.p) {}

		~reversConstMyIterator() { }

		reversConstMyIterator & operator = (const reversConstMyIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		};
		
		const value_type& operator * () { return *p; }
		const value_type& operator -> () {return p; }

		reversConstMyIterator& operator ++ () {--p; return (*this); }
		reversConstMyIterator operator ++ (int) {
			reversConstMyIterator temp(*this);
			operator --();
			return temp;
		}
		reversConstMyIterator& operator -- () {++p; return (*this); }
		reversConstMyIterator operator --(int) {
			reversConstMyIterator temp(*this);
			operator +();
			return temp;
		}
		reversConstMyIterator& operator +=(int n) {
				if (n > 0) {
					while (n-- > 0) // n positive
						operator--(); 
					return (*this);	
				}
				while (n++ < 0) // n negative
					operator++();
				return (*this);
		}
		reversConstMyIterator& operator -=(int n) {
			if (n > 0) {
				while (n-- > 0) // n positive
					operator++(); 
				return (*this);	
			}
			while (n++ < 0)
				operator--();
			return (*this);
		}
		reversConstMyIterator operator - (int n) const {
			reversConstMyIterator temp(*this);
			temp += n;
			return (temp);
		}
		reversConstMyIterator operator + (int n) const {
			reversConstMyIterator temp(*this);
			temp -= n;
			return (temp);
		}
	
		bool operator == (const reversConstMyIterator & other) const {return (this->p == other.p); }
		bool operator != (const reversConstMyIterator & other) const { return (this->p != other.p); }
		bool operator > (const reversConstMyIterator & other) const { return (this->p > other.p); }
		bool operator < (const reversConstMyIterator & other) const { return (this->p < other.p); }
		bool operator >= (const reversConstMyIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const reversConstMyIterator & other) const { return (this->p <= other.p); }

		const value_type & operator [] (int n) const { return (*(*this + n)); }
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

