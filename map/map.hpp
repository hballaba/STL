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
			typedef reverseMapIterator<key_type, mapped_type> reverse_iterator;
			typedef constmapIterator<key_type, mapped_type> const_iterator;
			typedef constReverseMapIterator<key_type, mapped_type> const_reverse_iterator;
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
				while (first != last) {
					insert(*first);
					++first;
				}
			}

			map(const map &x) {
				this->_size = 0;
				this->_root = nullptr;
				const_iterator st = x.begin();
				const_iterator fin = x.end();
				insert(st, fin);
			}


			~map() {

			}

			map &operator=(const map &x) {
				if (this == &x)
					return (*this);
				this->_size = 0;
				this->_root = nullptr;
				const_iterator st = x.begin();
				const_iterator fin = x.end();
				insert(st, fin);
				return (*this);
			}

			iterator begin() {
			   return (iterator(_begin));
			}


			iterator end() {
				return (iterator(_end->right));
			}

			const_iterator end() const{
				return (const_iterator(_end->right));
			}

			const_iterator begin() const {
				return (const_iterator(_begin));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(_end));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(_begin));
			}

			    reverse_iterator rend() {
				    return (reverse_iterator(_begin->left));
			}
			    const_reverse_iterator rend() const{
				    return (const_reverse_iterator(_begin->left));
			}


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

			mapped_type &operator[](const key_type &k){
				std::pair<iterator,bool> ret;
				ret = insert(std::make_pair(k, mapped_type()));
				return (ret.first)->second;
			}


			/************* Modifiers *************/


			int bfactor(node* noda) {     //find diff between branch
				unsigned char left = 0, right = 0;
				if (noda->left)
					left = noda->left->height;
				if (noda->right)
					right = noda->right->height;
				return right - left;
			}

			void getHight(node* noda) {
				unsigned char left = 0, right = 0;
				if (noda->left)
					left = noda->left->height;
				if (noda->right)
					right = noda->right->height;
				noda->height = left + 1;
				if (right > left)
					noda->height = right + 1;
			}

			node* rotateright(node* root)
			{
				node* par = root->parent;
				node* left = root->left;
				root->parent = left;
				left->parent = par;
				if (left->left)
					left->left->parent = root;
				root->left = left->right;
				left->right = root;
				getHight(root);
				getHight(left);
				return left;
			}

			node* rotateleft(node* root)
			{
				node* par = root->parent;
				node* right = root->right;
				root->parent = right;
				right->parent = par;
				if (right->left)
					right->left->parent = root;
				root->right = right->left;
				right->left = root;

				getHight(root);
				getHight(right);
				return right;
			}
			node* balance(node* p)
			{
				nodeptr tmp;
				getHight(p);
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
				return p;
			}


			node* Insert(node* p, int k, mapped_type val) // подшаманить
			{
				if( _size == 0 ) {
					_root = new node(k, val);
					++_size;
					_root->height++;
					_tmp = _root;
					return _root;

				}
				if( !p ) {
					_size++;

					node* newNode = new node(k, val);
					_tmp = newNode;
					return newNode;
				}
				if( k < p->date.first) {
					p->left = Insert(p->left, k, val);
					p->left->parent = p;
				}
				else if (k == p->date.first) {
					return _tmp;
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
			    std::pair<iterator, bool> ret = std::make_pair(find(val.first), t != _size);
				_end = _begin =_root;
				while (_end->right)
					_end = _end->right;
//				_begin = _root;
				while (_begin->left)
					_begin = _begin->left;
				return (ret);
					// исправить возвращаемое значение
			}

			iterator insert (iterator position, const value_type& val){
				std::pair<iterator,bool> ret;
				ret = insert(val);
				return ret.first;
			}

			template<class InputIterator>
			void insert(InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
				while (first != last) {
					insert(*first);
					++first;
				}
			}
			void parent_nullptr(nodeptr del, nodeptr descendent) {
				if (del->parent) {
					if (del->parent->left == del)
						del->parent->left = descendent;
					if (del->parent->right == del)
						del->parent->right = descendent;
				}
			}

			node* findmax(node* p)
			{
				if (p->left)
					return findmax(p->left);
				return p;


//				return p->left?findmax(p->left):p;
			}

			node* removemin(node* p)
			{
				if(!p->left)
					return p->right  ;
				p->left = removemin(p->left);
//				p->right = removemin(p->left);
				return balance(p);
			}

			node* remove(node* del, key_type k)
			{
				if( !del )
					return nullptr;
				if( k < del->date.first) {
					del->left = remove(del->left, k);
				}
				else if( k > del->date.first) {
					del->right = remove(del->right, k);
				}
				else {
					node* left = del->left;
					node* right = del->right;
					node* parent = del->parent;
					delete del;
					_size--;
					if( !right)
						return left;
					nodeptr max = findmax(right);
					nodeptr max_left = max->left;
					max->right = removemin(right);
					max->left = left;
					if (right)
						right->parent = max->right;
					if (max_left)
						max->left->parent = left;
					if (max->right)
						max->right->parent = max;
//					if (right != max)
//						right->left = max_left;
					left->parent = max;
					max->parent = parent;
					return balance(max);
				}
				return balance(del);
			}



			void erase (iterator position) {
				nodeptr del = position.getp();
				if (!del)
					return ;
//				_root = _delete(_root, del->date.first);
				_root = remove(_root, del->date.first);
				_end = _begin =_root;
				if (_end)
					while (_end->right)
						_end = _end->right;
				if (_begin)
					while (_begin->left)
						_begin = _begin->left;
//				nodeptr del = position.getp();
//				if (!del)
//					return ;
//				else if (!del->right && !del->left) {
//					parent_nullptr(del, nullptr);
//					delete del;
//				}
//				else if (!del->right && del->left) {  //there is left descendent
//					parent_nullptr(del, del->left);
//					delete del;
//				}
//				else if (del->right && !del->left) {  //there is left descendent
//					parent_nullptr(del, del->right);
//					delete del;
//				}
//				else {
//					nodeptr next = (++iterator(del)).getp();
//				}
//
//
//
//
//				_size--;
			}

			size_type erase(const key_type &k) {
					erase(find(k));
				return (1);
			}

			void erase (iterator first, iterator last) {
				while (first != last) {
					erase(first);
					first++;
					std::cout << "1";
				}
			}

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


			    iterator find (const key_type& k) {
					nodeptr _find = _root;
					unsigned char i = _root->height;
					while (i-- > 0) {
						if (_find->date.first < k) {
							if (!_find->right)
								return (end());
							_find = _find->right;
						}
						else if (_find->date.first > k) {
							if (!_find->left)
								return (end());
							_find = _find->left;
						}
						else
							return (iterator(_find));
					}

					return (iterator(_find));
			    }

		   const_iterator find (const key_type& k) const {
			   nodeptr _find = _root;
			   unsigned char i = _root->height;
			   while (i-- > 0) {
				   if (_find->date.first < k) {
					   if (!_find->right)
						   return (end());
					   _find = _find->right;
				   }
				   else if (_find->date.first > k) {
					   if (!_find->left)
						   return (end());
					   _find = _find->left;
				   }
				   else
					   return (const_iterator(_find));
			   }

			   return (const_iterator(_find));
			    }


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

#endif /*MAP_HPP*/