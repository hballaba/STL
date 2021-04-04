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

		typedef std::pair<Key, T> _pair;

		typedef T value_type;
		typedef Node<Key, T> node;

		_pair val;
		node *p;



	public:

		mapIterator() : p(nullptr) {}

		mapIterator(node *x) : p(x) { }

		mapIterator(const mapIterator& it) : p(const_cast<node *>(it.p)) { }

		mapIterator(const value_type & v) : val(v) { }

		~mapIterator() {}

		mapIterator & operator=(const mapIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		}

		_pair operator * () const  { return (p->date); }

		_pair * operator -> () { return &p->date; }

		mapIterator operator ++ () {

			node * next;
			if (p) {

				if (!p->right) {
					next = p;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				} else {
					next = p->right;
					while (next->left)
						next = next->left;
				}
				p = next;
			}
			return (*this);
		}

		mapIterator operator ++ (int) {
			mapIterator temp(*this);
			operator ++();
			return temp;
		}
		mapIterator& operator -- () {
			node* prev;
			if (!p->left) {
				prev = p;
				while (prev->parent && prev == prev->parent->left)
					prev = prev->parent;
				prev = prev->parent;
			}
			else {
				prev = p->left;
				while (prev->right)
					prev = prev->right;
			}
			p = prev;
			return (*this);
		}
		mapIterator& operator -- (int) {
			mapIterator temp(*this);
			operator --();
			return temp;
		}

		bool operator == (const mapIterator & other) const {return (this->p == other.p); }
		bool operator != (const mapIterator & other) const { return (this->p != other.p); }
		bool operator > (const mapIterator & other) const { return (this->p > other.p); }
		bool operator < (const mapIterator & other) const { return (this->p < other.p); }
		bool operator >= (const mapIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const mapIterator & other) const { return (this->p <= other.p); }

		node*	getp() const { return p; }
	};

	template<class Key, class T>
	class constmapIterator {
//		typedef Key key_type;
//		typedef T mapped_type;

		typedef std::pair<Key, T> _pair;

		typedef T value_type;
		typedef Node<Key, T> node;

		_pair val;
		node *p;



	public:

		constmapIterator() : p(nullptr) {}

		constmapIterator(node *x) : p(x) { }

		constmapIterator(const constmapIterator& it) : p(const_cast<node *>(it.p)) { }

		constmapIterator(const value_type & v) : val(v) { }

		~constmapIterator() {}

		constmapIterator & operator=(const constmapIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		}

		const _pair operator * () const  { return (p->date); }

		const _pair * operator -> () { return &p->date; }

		constmapIterator operator ++ () {
			node* next;
			if (!p->right) {
				next = p;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else {
				next = p->right;
				while (next->left)
					next = next->left;
			}
			p = next;
			return (*this);
		}

		constmapIterator operator ++ (int) {
			constmapIterator temp(*this);
			operator ++();
			return temp;
		}
		constmapIterator& operator -- () {
			node* prev;
			if (!p->left) {
				prev = p;
				while (prev->parent && prev == prev->parent->left)
					prev = prev->parent;
				prev = prev->parent;
			}
			else {
				prev = p->left;
				while (prev->right)
					prev = prev->right;
			}
			p = prev;
			return (*this);
		}
		constmapIterator& operator -- (int) {
			constmapIterator temp(*this);
			operator --();
			return temp;
		}

		bool operator == (const constmapIterator & other) const {return (this->p == other.p); }
		bool operator != (const constmapIterator & other) const { return (this->p != other.p); }
		bool operator > (const constmapIterator & other) const { return (this->p > other.p); }
		bool operator < (const constmapIterator & other) const { return (this->p < other.p); }
		bool operator >= (const constmapIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const constmapIterator & other) const { return (this->p <= other.p); }

		node*	getp() const { return p; }
	};

	template<class Key, class T>
	class reverseMapIterator {

		typedef std::pair<Key, T> _pair;
		typedef T value_type;
		typedef Node<Key, T> node;

		_pair val;
		node *p;



	public:

		reverseMapIterator() : p(nullptr) {}

		reverseMapIterator(node *x) : p(x) { }

		reverseMapIterator(const reverseMapIterator& it) : p(const_cast<node *>(it.p)) { }

		reverseMapIterator(const value_type & v) : val(v) { }

		~reverseMapIterator() {}

		reverseMapIterator & operator=(const reverseMapIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		}

		_pair operator * () const  { return (p->date); }

		_pair * operator -> () { return &p->date; }

		reverseMapIterator operator -- () {

			node * next;
			if (!p->right)
			{
				next = p;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = p->right;
				while (next->left)
					next = next->left;
			}
			p = next;
			return (*this);
		}

		reverseMapIterator operator ++ (int) {
			reverseMapIterator temp(*this);
			operator ++();
			return temp;
		}
		reverseMapIterator& operator ++ () {
			node* prev;
			if (!p->left) {
				prev = p;
				while (prev->parent && prev == prev->parent->left)
					prev = prev->parent;
				prev = prev->parent;
			}
			else {
				prev = p->left;
				while (prev->right)
					prev = prev->right;
			}
			p = prev;
			return (*this);
		}
		reverseMapIterator& operator -- (int) {
			reverseMapIterator temp(*this);
			operator --();
			return temp;
		}

		bool operator == (const reverseMapIterator & other) const {return (this->p == other.p); }
		bool operator != (const reverseMapIterator & other) const { return (this->p != other.p); }
		bool operator > (const reverseMapIterator & other) const { return (this->p > other.p); }
		bool operator < (const reverseMapIterator & other) const { return (this->p < other.p); }
		bool operator >= (const reverseMapIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const reverseMapIterator & other) const { return (this->p <= other.p); }

		node*	getp() const { return p; }
	};

	template<class Key, class T>
	class constReverseMapIterator {

		typedef std::pair<Key, T> _pair;
		typedef T value_type;
		typedef Node<Key, T> node;

		_pair val;
		node *p;



	public:

		constReverseMapIterator() : p(nullptr) {}

		constReverseMapIterator(node *x) : p(x) { }

		constReverseMapIterator(const constReverseMapIterator& it) : p(const_cast<node *>(it.p)) { }

		constReverseMapIterator(const value_type & v) : val(v) { }

		~constReverseMapIterator() {}

		constReverseMapIterator & operator=(const constReverseMapIterator &copy) {
			if (this == &copy)
				return (*this);
			this->p = copy.p;
			return (*this);
		}

		_pair operator * () const  { return (p->date); }

		_pair * operator -> () { return &p->date; }

		constReverseMapIterator operator -- () {

			node * next;
			if (!p->right)
			{
				next = p;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = p->right;
				while (next->left)
					next = next->left;
			}
			p = next;
			return (*this);
		}

		constReverseMapIterator operator ++ (int) {
			constReverseMapIterator temp(*this);
			operator ++();
			return temp;
		}
		constReverseMapIterator& operator ++ () {
			node* prev;
			if (!p->left) {
				prev = p;
				while (prev->parent && prev == prev->parent->left)
					prev = prev->parent;
				prev = prev->parent;
			}
			else {
				prev = p->left;
				while (prev->right)
					prev = prev->right;
			}
			p = prev;
			return (*this);
		}
		constReverseMapIterator& operator -- (int) {
			constReverseMapIterator temp(*this);
			operator --();
			return temp;
		}

		bool operator == (const constReverseMapIterator & other) const {return (this->p == other.p); }
		bool operator != (const constReverseMapIterator & other) const { return (this->p != other.p); }
		bool operator > (const constReverseMapIterator & other) const { return (this->p > other.p); }
		bool operator < (const constReverseMapIterator & other) const { return (this->p < other.p); }
		bool operator >= (const constReverseMapIterator & other) const { return (this->p >= other.p); }
		bool operator <= (const constReverseMapIterator & other) const { return (this->p <= other.p); }

		node*	getp() const { return p; }
	};

}


#endif /*MAPITERATOR_HPP*/