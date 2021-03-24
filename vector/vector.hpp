#ifndef VECTOR_HPP

# define VECTOR_HPP

# include <iostream>
# include <string>
# include <iterator>
# include "../iterator.hpp"
# include <stdio.h>



namespace ft {


	template< class T, class Alloc = std::allocator<T> >
	class vector {

		template<class Other>
		struct rebind {typedef std::allocator<Other> other;};
	public:
		typedef 	T value_type;
		typedef 	Alloc allocator_type;
		typedef 	typename allocator_type::reference 	reference;
		typedef 	typename allocator_type::const_reference const_reference;
		typedef 	typename allocator_type::pointer pointer;
		typedef 	typename allocator_type::const_pointer const_pointer;
		typedef 	ft::myIterator<value_type> iterator;
		typedef 	ft::constMyIterator<value_type> const_iterator;
		typedef 	ft::reversMyIterator<value_type> reverse_iterator;
		typedef 	ft::reversConstMyIterator <value_type> const_reverse_iterator;
		typedef		ptrdiff_t difference_type;
		typedef		size_t size_type;
		typedef		std::allocator<T> type_alloc;


		private:
			value_type *_array;
			size_t _size;
			size_t _capacity;
			allocator_type _alloc;

		
		public:

		explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0) { }

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				_array = _alloc.allocate(n);
				for(int i = 0; i < n; i++)
					_alloc.construct(_array + i, val);
				_size = n;
				_capacity = n;
		}

        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(), char (*)[sizeof(*first)] = NULL) : _alloc(alloc) {
            _capacity = 0;
            InputIterator temp = first;
		    while (temp != last) {
                _capacity++;
                temp++;
            }
		    _array = _alloc.allocate(_capacity);
		    _size = _capacity;
		    temp = first;
            for(int i = 0; i < _size; i++) {
                _alloc.construct(_array + i, *temp);
                temp++;
            }
		};

			vector(vector const & toCopy) {

				this->_alloc = toCopy._alloc;
				this->_array = this->_alloc.allocate(toCopy._size);
				for(int i = 0; i < toCopy._size; i++)
				 	this->_alloc.construct(this->_array + i, toCopy._array[i]);
				this->_size = toCopy._size;
				this->_capacity = toCopy._size;
			}

        ~vector() {
            for (int i = 0; i < _size; i++) {
                _alloc.destroy(_array + i);
            }
            if (_capacity > 0) {
                _alloc.deallocate(_array, _capacity);
            }
        }

			vector & operator = (vector const & toCopy) {
				if (toCopy._capacity != this->_capacity) {
					for (int i = 0; i < this->_size; i++) {
						this->_alloc.destroy(this->_array + i);
					}
					if (this->_capacity > 0) {
						std::cerr << "tyt1\n";
						this->_alloc.deallocate(this->_array, this->_capacity);
					}
					this->_array = _alloc.allocate(toCopy._capacity);
				}
				for(int i = 0; i < toCopy._size; i++)
					this->_alloc.construct(this->_array + i, toCopy._array[i]);
				this->_size = toCopy._size;
				this->_capacity = toCopy._capacity;
				return *this;
			}

			

			//**********	Modifiers **********


		void	push_back(value_type const & element) {
			if (_capacity > _size) {  //уже выделена памятm
				_alloc.construct(_array + _size, element);
				_size++;
			}
			else if (_capacity > 0) {  // надо домалочить
				value_type *tmp;// = _array;
				tmp = _alloc.allocate(_capacity * 2);

				_alloc.construct(tmp + (_size),  element);
				for (int i = 0; i < _size; i++) {
				_alloc.construct(tmp + i, _array[i]);
				}
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_alloc.deallocate(_array, _capacity);
				_capacity = _capacity * 2;
				_array = tmp;
				_size++;
			}
			else {			// новый вектор
				this->_array = this->_alloc.allocate(1);
				this->_alloc.construct(this->_array, element);
				this->_capacity ++;
				this->_size++;
			}
		}
			
			void	clear() {
				delete [] _array;
				_array = nullptr;
				_size = 0;
				_capacity = 0;
			}


        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
            int cap = 0;
            InputIterator temp = first;
            while (temp != last) {
                cap++;
                temp++;
            }
            if (cap > _capacity)
                _capacity = cap;
            _array = _alloc.allocate(_capacity);
            _size = _capacity;
            temp = first;
            for(int i = 0; i < _size; i++) {
                _alloc.construct(_array + i, *temp);
                temp++;
            }
		}


        void assign (size_type n, const value_type& val) {
            if (n > _capacity)
                _capacity = n;
            value_type *tmp = _alloc.allocate(_capacity);

            for (int i = 0; i < n; i++)
                _alloc.construct(tmp + i, val);

            for (int i = 0; i < _size; i++)
                _alloc.destroy(_array + i);
            _alloc.deallocate(_array, _capacity);
            _array = tmp;
            _size = n;
		}

			void	pop_back() {
				if (_size > 0)
                    _alloc.destroy(_array + --_size);
			}


            void insert (iterator pos, size_type n, const value_type& val)
			{
				int num;
				int cup = _capacity;
                value_type * tmp;
				for (num = 0; num < _size; num++) {
					if (pos == &_array[num])
						break ;
				}
				if (_size + n > _capacity && _size + n <= _capacity  * 2)
                    _capacity *= 2;
				else if (_size + n > _capacity)
                    _capacity = (_size + n) * 2;
				tmp = _alloc.allocate(_capacity);
				_size += n;
				for (int i = 0; i < num; i++)
                    _alloc.construct(tmp + i, _array[i]);
				for (int i = _size - 1; i >= num + n; i--)
                    _alloc.construct(tmp + i, _array[i - n]);
				for (int i = 0; i < n; i++) {
                    _alloc.construct(tmp + (num + i), val);
                }
				for (int i = 0; i < _size - n; i++)
                    _alloc.destroy(_array + i);
                _alloc.deallocate(_array, cup);
				_array = tmp;

			}

    private:
        void myinsert (int num, size_type n, const value_type& val)
        {
             int cup = _capacity;
            value_type * tmp;
            if (_size + n > _capacity && _size + n <= _capacity  * 2)
                _capacity *= 2;
            else if (_size + n > _capacity)
                _capacity = (_size + n) * 2;
            tmp = _alloc.allocate(_capacity);
            _size += n;
            for (int i = 0; i < num; i++)
                _alloc.construct(tmp + i, _array[i]);
            for (int i = _size - 1; i >= num + n; i--)
                _alloc.construct(tmp + i, _array[i - n]);
            for (int i = 0; i < n; i++) {
                _alloc.construct(tmp + (num + i), val);
            }
            for (int i = 0; i < _size - n; i++)
                _alloc.destroy(_array + i);
            _alloc.deallocate(_array, cup);
            _array = tmp;

        }

    public:
            iterator	insert(iterator pos, const value_type& val) {
                value_type * tmp = _array;
                int num;
                for (num = 0; num < _size; num++) {
                    if (pos == &_array[num])
                        break ;
                }
                insert(pos, 1, val);
                return (&_array[num]);
            }


            template <class InputIterator>
           	void	insert(iterator pos, InputIterator start, InputIterator finish, char (*)[sizeof(*start)] = NULL)
			{
				value_type * tmp = _array;
				InputIterator t = start;
				int num = 0;
				while (t != finish) {
                    t++;
				    num++;
				}
				int num2 = 0;
                for (num2 = 0; num2 < _size; num2++) {
                    if (pos == &_array[num2])
                        break ;
                }
				for (int i = 0; i < num; i++) {
				    myinsert(num2++, 1, *(start + i));
				}
			}



			iterator erase(iterator pos) {
				T* tmp = _array;
				int num;
				for (num = 0; num < _size; num++) {
					if (pos == &_array[num])
						break ;
				}
				if (num == _size)
					num--;
				int j = 0;
				for(int i = 0; j < _size; j++) {
					if (j != num) {
						T t = tmp[j];
						_array[i++] = tmp[j];
					}
				}
				_size--;
				_array[_size] = 0;
				if (_size == num)
					return (&_array[_size]);
				return (&_array[num]);
			}

			iterator erase(iterator start, iterator finish) {
				T* tmp = _array;
				int numst, numfin;
				for (numst = 0; numst < _size; numst++) {
					if (start == &_array[numst])
						break ;
				}
				for (numfin = 0; numfin < _size; numfin++) {
					if (finish == &_array[numfin])
						break ;
				}

				if (numst >= _size)
					numst = _size;
				if (numfin >= _size)
					numfin = _size;
				int j = 0;
				for(int i = 0; j < _size; j++) {
					if (j < numst || j >= numfin ) {
						T t = tmp[j];
						_array[i++] = tmp[j];
					}
				}
				_size = _size - (numfin - numst);
				if (_size <= numfin)
					return (&_array[_size]);
				return (&_array[numfin]);
			}

			void	ft_copy(vector<T> & forCopy, vector<T> const & toCopy) {
				if (toCopy._capacity > forCopy._capacity) {
					delete [] forCopy._array;
					forCopy._array = new T[toCopy._capacity];
				}
				for(int i = 0; i < toCopy._capacity; i++)
					forCopy._array[i] = toCopy._array[i];
				forCopy._size = toCopy._size;
				forCopy._capacity = toCopy._capacity;

			}
			void	swap(vector<T> & toCopy) {
				vector<T> *tmp = new vector<T>;
				ft_copy(*tmp, *this);
				ft_copy(*this, toCopy);
				ft_copy(toCopy, *tmp);

				delete tmp;


			}


//			//**********	Capacity **********
			size_type 	size() const {
				return _size;
			}

			size_type 	capacity() const {
				return _capacity;
			}

			bool	empty() const {
				if (_size)
					return false;
				return true;
			}

			size_type max_size() const { return allocator_type().max_size(); }

			void	resize(size_t size, value_type val = value_type()) {
				if (size > _capacity) {
					size_t cap;
					if (size < _capacity * 2)
						cap = _capacity * 2;
					else
						cap = size;
					value_type *tmp = _alloc.allocate(cap);

					for (int i = 0; i < size; i++) {
						if (i < _size)
							_alloc.construct(tmp + i, _array[i]);
						else
							_alloc.construct(tmp + i, val);
					}
					for (int i = 0; i < _size; i++)
						_alloc.destroy(_array + i);
					_alloc.deallocate(_array, _capacity);
					_array = tmp;
					_size = size;
					_capacity = cap;
				}
				else if (size > _size) {
					for (int i = 0; i < size; i++) {
					if (i >= _size)
							_alloc.construct(_array + i, val);
					}
					_size = size;
				}
				else {
					_size = size;
					}
			}

			void	reserve (size_t n) {
				if (n > _capacity) {
					T *tmp = _alloc.allocate(n);
					for (int i = 0; i < _size; i++)
					    _alloc.construct(tmp + i, _array[i]);
					for (int i = 0; i < _size; i++)
						_alloc.destroy(_array + i);
					_alloc.deallocate(_array, _capacity);
					_array = tmp;
					_capacity = n;
				}
			}


			//**********	Iterators *********


			iterator begin() {
				return (_array);
			}


			iterator end() {
				return ((_array + _size));
			}


            reverse_iterator    rbegin() {
				return (_array + _size - 1);
			}

            reverse_iterator rend() {
				return (_array - 1);
			}


			

			//**********	Element access *********

			T & operator [] (const unsigned int index) const {
				return _array[index];
			}

			T at(const size_t index) {
				if (_size >= index + 1)
					return (_array[index]);
				else
					throw "vector";
			}

			T front() {
				T t = 0;
				if(_size > 0)
					return (_array[0]);
				return t;
			}

			T back() {
				T t = 0;
				if (_size > 0)
					return (_array[_size - 1]);
				return t;
			}



				
	};
}
#endif