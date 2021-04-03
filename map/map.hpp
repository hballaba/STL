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
			nodeptr _tmp;
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

			unsigned char height(node* p)
			{
				unsigned char i =p?p->height:0;
				return i;
			}

			int bfactor(node* p)
			{
				int i =  height(p->right)-height(p->left);
				return i;
			}

			void fixheight(node* p)
			{
				unsigned char hl = height(p->left);
				unsigned char hr = height(p->right);
				p->height = (hl>hr?hl:hr)+1;
			}

			node* rotateright(node* q) // правый поворот вокруг p
			{
				node* par = q->parent;
				node* p = q->left;

				q->left = p->right;     // need Parent
				p->right = q;
				fixheight(q);
				fixheight(p);
				return p;
			}

			node* rotateleft(node* q) // левый поворот вокруг q
			{
				node* par = q->parent;
				node* p = q->right;
				q->right = p->left;
				p->left = q;
				q->parent = p;
				p->parent = par;
				fixheight(q);
				fixheight(p);
				return p;
			}
			node* balance(node* p) // балансировка узла p
			{
				nodeptr tmp;
				fixheight(p);
				if( bfactor(p)== 2 )
				{
					if( bfactor(p->right) < 0 )
						p->right = rotateright(p->right);
					tmp = rotateleft(p);
					return tmp;
				}
				if( bfactor(p)== -2 )
				{
					if( bfactor(p->left) > 0  )
						p->left = rotateleft(p->left);
					tmp = rotateright(p);
					return tmp;
				}
				return p; // балансировка не нужна
			}

//			node * Insert(key_type x, mapped_type val) {
//				Node<key_type, mapped_type>** cur = &_root;
//				while (*cur) {
//					Node<key_type, mapped_type>& pode = **cur;
//					if (x < pode.date.first) {
//						pode.height++;
//						cur = &pode.left;
//					} else if (x > pode.date.first) {
//						pode.height++;
//						cur = &pode.right;
//					} else {
//						return *cur;
//					}
//				}
//				*cur = new Node<key_type, mapped_type>(x, val);
//				_size++;
//				if (_root->left && _root->right)
//					_root->height =  (_root->left->height > _root->right->height) ?_root->left->height + 1 : _root->right->height + 1;
//
//				return balance(*cur);
//			}

			node* Insert(node* p, int k, mapped_type val) // подшаманить
			{
				if( _size == 0 ) {
					_root = new node(k, val);
					++_size;
					_root->height++;
					_begin = _root;
					_end = _root;
					return _root;

				}
				if( !p ) {
					_size++;

					node* newNode = new node(k, val);
					if (_begin->date.first > k)
						_begin = newNode;
					if (_end->date.first < k)
						_end = newNode;
					_tmp = newNode;
					return newNode;
				}
				if( k < p->date.first) {
					p->left = Insert(p->left, k, val);
					p->left->parent = p;
				}
				else {
					p->right = Insert(p->right, k, val);
					p->right->parent = p;
				}
				nodeptr tmp = balance(p);
				return tmp;
			}



			    std::pair<iterator, bool> insert (const value_type& val) {
						size_t t = _size;
				        _root = Insert(_root, val.first, val.second);
						node *tmp = _root;
					    std::pair<iterator, bool> ret = std::make_pair(iterator(_tmp), t != _size);
			    		return (ret);
			    		// исправить возвращаемое значение
			    }


//				node *newNode(key_type key, mapped_type val) {
//					nodeptr _newNode;
//					_newNode= new node(key, val);
//					_newNode->left = nullptr;
//					_newNode->right = nullptr;
//					_newNode->parent = nullptr;
//					return _newNode;
//				}

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