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
			typedef typename allocator_type::template rebind<value_type>::other		alloc_rebind;
			typedef mapIterator<key_type, mapped_type> iterator;
			typedef reverseMapIterator<key_type, mapped_type> reverse_iterator;
			typedef constmapIterator<key_type, mapped_type> const_iterator;
			typedef constReverseMapIterator<key_type, mapped_type> const_reverse_iterator;
			typedef ft::Node<key_type, mapped_type> node;
			typedef ft::Node<key_type, mapped_type> *nodeptr;
			typedef size_t size_type;

			class value_compare {
				friend class map;
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}
			};


		private:
			allocator_type _alloc;
			key_compare _comp;
			value_compare	_valueCompare;
			size_type _size;
			nodeptr _root;
			nodeptr _begin;
			nodeptr _tmp;
			nodeptr _end;
			nodeptr _endtmp;


		public:

			/************* Construct **************/
			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
			    _alloc(alloc), _comp(comp), _valueCompare(comp), _size(0), _root(nullptr), _begin(nullptr) , _end(nullptr) {
				_end = new node();
			}

			template<class InputIterator>
			map(InputIterator first, InputIterator last,
			    const key_compare &comp = key_compare(),
			    const allocator_type &alloc = allocator_type()) :
					_alloc(alloc), _comp(comp), _valueCompare(comp), _size(0), _root(nullptr), _begin(nullptr) , _end(nullptr) {
				_end = new node();
				while (first != last) {
					insert(*first);
					++first;
				}
			}

			map(const map &x) :_alloc(x._alloc), _comp(x._comp), _valueCompare(x._valueCompare) {
				this->_size = 0;
				this->_root = nullptr;
				_end = new node();
				const_iterator st = x.begin();
				const_iterator fin = x.end();
				insert(st, fin);
			}


			~map() {
				clear();
				delete _end;

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
				return (iterator(_end));
			}

			const_iterator end() const{
				return (const_iterator(_end));
			}

			const_iterator begin() const {
				return (const_iterator(_begin));
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(_end->parent));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(_end->parent));
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


			int balanceFactor(node* noda) {
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

			node* rotateright(node* root) {
				node* par = root->parent;
				node* left = root->left;
				root->parent = left;
				left->parent = par;
				if (left->left)
					left->left->parent = left;
				root->left = left->right;
				left->right = root;
				getHight(root);
				getHight(left);
				return left;
			}

			node* rotateleft(node* root) {
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
			node* balance(node* p) {
				nodeptr tmp;
				getHight(p);
				int b = balanceFactor(p);
				if( b == 2 )
				{
					if( balanceFactor(p->right) < 0 )
						p->right = rotateright(p->right);
					tmp = rotateleft(p);
					return tmp;
				}
				if( b == -2 )
				{
					if( balanceFactor(p->left) > 0  )
						p->left = rotateleft(p->left);
					tmp = rotateright(p);
					return tmp;
				}
				return p;
			}


			node* Insert(node* p, int k, mapped_type val) {
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
				if (_size) {
					_end->parent->right = nullptr;
					_end->parent = nullptr;
				}
			    _root = Insert(_root, val.first, val.second);
			    std::pair<iterator, bool> ret = std::make_pair(find(val.first), t != _size);
				_endtmp = _begin =_root;
				while (_endtmp->right) {
					_endtmp = _endtmp->right;
				}
				_end->parent = _endtmp;
				_endtmp->right = _end;

				while (_begin->left)
					_begin = _begin->left;
				return (ret);
			}

			iterator insert (iterator position, const value_type& val) {
				if (position.getp())
					;
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

			node* findmax(node* p) {
				if (p->left)
					return findmax(p->left);
				return p;
			}

			node* removemin(node* p) {
				if(!p->left)
					return p->right  ;
				p->left = removemin(p->left);
//				p->right = removemin(p->left);
				return balance(p);
			}

			node* remove(node* del, key_type k)	{
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
					if (left)
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

				_root = remove(_root, del->date.first);
				_end = _begin =_root;
				if (_end)
					while (_end->right)
						_end = _end->right;
				if (_begin)
					while (_begin->left)
						_begin = _begin->left;
			}

			size_type erase(const key_type &k) {
					erase(find(k));
				return (1);
			}

			void erase (iterator first, iterator last, char (*)[sizeof(*first)] = NULL) {
				while (first != last) {
					iterator tmp = first;
					tmp++;
					erase(first);
					first = tmp;
				}
			}

			void swap(map &x) {
				map tmp(x);
				x = *this;
				*this = tmp;
			}


			void clear() {
				erase(begin(), end());
			}


			/************* Observers *************/

			key_compare key_comp() const {
				return (_comp);
			}

			value_compare value_comp() const {
				return (_valueCompare);
			}


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


			size_type count(const key_type &k) const{
			    	const_iterator tmp = find(k);
			    	if (tmp.getp() == _end || !tmp.getp())
			    		return 0;
			    	return 1;
			}

			    iterator lower_bound (const key_type& k) {
			 	    iterator _find = find(k);
			 	    if (_find.getp()->date.first == k)
			 	    	return _find;
				    return (iterator(_end));
			    }

			    const_iterator lower_bound (const key_type& k) const {
				    const_iterator _find = find(k);

				    if (_find.getp()->date.first == k)
					    return _find;
				    return (const_iterator(_end));
			    }


			    iterator upper_bound (const key_type& k) {
				    iterator _find = find(k);
				    if (_find.getp()->date.first == k) {
					    _find++;
				    	return _find;
				    }
				    else
				    	return iterator(_end);

			    }

			    const_iterator upper_bound (const key_type& k) const {
				    const_iterator _find = find(k);
				    if (_find.getp()->date.first == k) {
					    _find++;
					    return _find;
				    }
				    else
					    return const_iterator(_end);
			    }

			    std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			    	const_iterator low = lower_bound(k);
				    const_iterator up = upper_bound(k);
				    return (std::pair<const_iterator, const_iterator > (low, up));
			    }

			    std::pair<iterator,iterator> equal_range (const key_type& k) {
				    iterator low = lower_bound(k);
				    iterator up = upper_bound(k);
				    return (std::pair<iterator , iterator> (low, up));
			    }

		private:

		};

	}



#endif /*MAP_HPP*/