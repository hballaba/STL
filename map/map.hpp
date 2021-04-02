#ifndef MAP_HPP

# define MAP_HPP

#include "mapNode.hpp"
#include "mapIterator.hpp"
#include <utility>

	namespace ft {

		template<class Key,                                     // map::key_type
				class T,                                       // map::mapped_type
				class Compare = std::less<Key>,                     // map::key_compare
				class Alloc = std::allocator<std::pair<const Key, T> > >   // map::allocator_type

		class map {

		public:

			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const Key, T> value_type;
			typedef Alloc allocator_type;
			typedef Compare key_compare;
			typedef T &reference;
			typedef const T &const_reference;
			typedef T *pointer;
			typedef const T *const_pointer;

			typedef mapIterator<key_type, mapped_type> iterator;
			//    typedef ReverseMapIterator<key_type, mapped_type> reverse_iterator;
			//    typedef ConstMapIterator<key_type, mapped_type> const_iterator;
			//    typedef ConstReverseMapIterator<key_type, mapped_type> const_reverse_iterator;
			typedef ft::Node<key_type, mapped_type> node;
			typedef ft::Node<key_type, mapped_type> *nodeptr;
			typedef size_t size_type;

			class value_compare {

			};// возможно вынести в отдельый файл



		private:
			allocator_type _alloc;
			key_compare _compare;
			size_type _size;
			nodeptr _root;
			nodeptr _begin;
			nodeptr _end;


		public:

			/************* Construct **************/
			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			    _size(0), _alloc(alloc), _root(nullptr), _compare(comp), _end(nullptr), _begin(nullptr) {


			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last,
			    const key_compare &comp = key_compare(),
			    const allocator_type &alloc = allocator_type()) {

			}

			map(const map &x) {

			}


			~map() {

			}

			map &operator=(const map &x);

			//    iterator begin();
			//    const_iterator begin() const;
			//    iterator end();
			//    const_iterator end() const;
			//    reverse_iterator rbegin();
			//    const_reverse_iterator rbegin() const;
			//    reverse_iterator rend();
			//    const_reverse_iterator rend() const;


			/********** Capacity **********/


			bool empty() const {
				if (_size)
					return false;
				return true;
			}

			size_type size() const {return _size; }

			size_type max_size () const {
				return std::numeric_limits<size_t>::max() / sizeof(node);
			}


			/************ Element access *********/

			mapped_type &operator[](const key_type &k);


			/************* Modifiers *************/

			node * Insert(key_type x, mapped_type val) {
				Node<key_type, mapped_type>** cur = &_root;
				while (*cur) {
					Node<key_type, mapped_type>& pode = **cur;
					if (x < pode.date.first) {
						cur = &pode.left;
					} else if (x > pode.date.first) {
//						if (x ) {
//							std::cout << "pup\n";
//
//
//						}
						cur = &pode.right;
					} else {
						return *cur;
					}
				}
				*cur = new Node<key_type, mapped_type>(x, val);
				_size++;

				return *cur;
			}


			    std::pair<iterator, bool> insert (const value_type& val){
			    	std::cout << "tyt\n";
						size_t t = _size;
				        nodeptr tmp = Insert(val.first, val.second);

					    std::pair<iterator, bool> ret = std::make_pair(iterator(tmp), t != _size);
			    		return (ret);
			    }


				node *newNode(key_type key, mapped_type val) {
					nodeptr _newNode;
					_newNode= new node(key, val);
					_newNode->left = nullptr;
					_newNode->right = nullptr;
					_newNode->parent = nullptr;
					return _newNode;
				}

			//    iterator insert (iterator position, const value_type& val);

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last);


			//    void erase (iterator position);

			size_type erase(const key_type &k);

			//    void erase (iterator first, iterator last);

			void swap(map &x) {
				map tmp(x);
				x = *this;
				*this = tmp;
			}


			void clear() {

			}


			/************* Observers *************/

			key_compare key_comp() const;

			value_compare value_comp() const;


			/**************  Operations  ***************/


			//    iterator find (const key_type& k);

			//    const_iterator find (const key_type& k) const;


			size_type count(const key_type &k) const;

			//    iterator lower_bound (const key_type& k);

			//    const_iterator lower_bound (const key_type& k) const;
			//
			//    iterator upper_bound (const key_type& k);

			//    const_iterator upper_bound (const key_type& k) const;
			//
			//    pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			//    pair<iterator,iterator>             equal_range (const key_type& k);

		private:




		};

	}


#endif /*MAP_HPP*/