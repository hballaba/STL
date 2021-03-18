#ifndef VECTOR_HPP

# define VECTOR_HPP

# include <iostream>
# include <string>
# include <iterator>
# include "../iterator.hpp"
# include <stdio.h>



//limite_max /sizof(T);

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
		//typedef 	my_const_iterator<value_type> const_iterator;
		//typedef reverse_iterator<iterator> reverse_iterator;
		//typedef reverse_iterator<const_iterator> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef std::allocator<T> type_alloc;


		private:
			value_type *_array;
			size_t _size;
			size_t _capacity;
			allocator_type _alloc;
			//type_alloc alloc;

		
		public:

		explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0) { }

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
//				value_type t;
				_array = _alloc.allocate(n);
//				for(int i = 0; i < size -1; i++)
//					alloc.construct(_array + i, t);
				_size = n;
				_capacity = n;
		}

//		template <class InputIterator>
//		vector (InputIterator first, InputIterator last,
//				const allocator_type& alloc = allocator_type());

			~vector() {
//				for (int i = 0; i < _size; i++) {
//					alloc.destroy(_array + i);
//				}
				if (_capacity > 0) {
					_alloc.deallocate(_array, _capacity);
				}


			}

			vector(vector const & toCopy) {

				this->_alloc = toCopy._alloc;
				this->_array = this->_alloc.allocate(toCopy._capacity);
				for(int i = 0; i < toCopy._size; i++)
				 	this->_alloc.construct(this->_array + i, toCopy._array[i]);
					//this->_array[i] = toCopy._array[i];
				this->_size = toCopy._size;
				this->_capacity = toCopy._capacity;
				//this->alloc = toCopy.alloc;
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
					//this->_array[i] = toCopy._array[i];
				this->_size = toCopy._size;
				this->_capacity = toCopy._capacity;
				//this->alloc = toCopy.alloc;
				return *this;
			}

			

			//**********	Modifiers **********

		void	push_back(value_type const & element) {
			if (_capacity > _size) {  //уже выделена памятm
				_alloc.construct(_array + _size, element);
				//_array[_size] = element;
				_size++;
			}
			else if (_capacity > 0) {  // надо домалочить
				value_type *tmp;// = _array;
				tmp = _alloc.allocate(_capacity * 2);

				_alloc.construct(tmp + (_size),  element);
				//tmp[_size] = element;
				for (int i = 0; i < _size; i++) {
					//tmp[i] = _array[i];
					_alloc.construct(tmp + i, _array[i]);
					//std::cout << "in " << _array[i];
				}
				//_array = tmp;
				for (int i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				//printf("126= %p\n", _array);
				_alloc.deallocate(_array, _capacity);
				//printf("126= %p\n", _array);
				_capacity = _capacity * 2;
				_array = tmp;
				_size++;
			}
			else {			// новый вектор
				this->_array = this->_alloc.allocate(1);
				//this->_array[0] = element;
				this->_alloc.construct(this->_array, element); // BAGGGGG!!!!
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

			void	assign(size_t n, T const & element) {
				if (_capacity < n) {
					delete [] _array;
					_array = new T[n];
					_capacity = n;
				}
				for(int i = 0; i < n; i++)
					_array[i] = element;
				_size = n;
			}

			void	pop_back() {
				if (_size > 0)
					_array[--_size] = 0;
			}

			//typedef T* iterator;

			iterator	insert(iterator pos, T const & element) {
				value_type * tmp = _array;
				int num;
				for (num = 0; num < _size; num++) {
					if (pos == &_array[num])
						break ;
				}

				if (_size == _capacity)
					_array = new T[_size+ 1];
				_size++;
				int j = 0;
				for (int i = 0; i < _size; i++) {
						if(i == num)
							_array[i] = element;
						else
							_array[i] = tmp[j++];

				}
				if (_size > _capacity) {
					delete [] tmp;
					_capacity++;
				}

				return (&_array[num]);
			}


			void		insert(iterator pos, size_t n, T const & element)
			{
				T* tmp = _array;
				int num;
				for (num = 0; num < _size; num++) {
					if (pos == &_array[num])
						break ;
				}

				if (_size + n >= _capacity)
					_array = new T[_size+ n];
				//_size ++;
				int j = 0;
				for (int i = 0; i < _size + n; i++) {
						if(i == num) {
							for(int a = 0; a < n; a++) {
								_array[i++] = element;
								//_size++;
							}
						}
						else
							_array[i] = tmp[j++];

				}
				if (_size + n >=_capacity) {
					delete [] tmp;
					_size += n;
					_capacity += n;
				}

			}

			iterator	insert(iterator pos, iterator start, iterator finish)
			{
				T* tmp = _array;
				int num, num2, num3, copyst;
				for (num = 0; num < _size; num++) {
					if (pos == &_array[num])
						break ;
				}
				num3 = num;
				for (copyst = 0; copyst < _size; copyst++) {
					if (start == &_array[copyst])
						break ;
				}
				for (num2 = 0; num2 < _size; num2++) {
					if (start == finish)
						break ;
				}
				if (_size + num2 >= _capacity)
					_array = new T[_size+ num2];
				int j = 0;
				for (int i = 0; i < _size + num2; i++) {
						if(i == num) {
							for(int a = 0; a < num2; a++) {
								_array[i++] = tmp[copyst++];
							}
							i--;
						}
						else {
							T t = tmp[j];
							_array[i] = tmp[j++];
						}
				}
				if (_size + num2 >=_capacity) {
					delete [] tmp;
					_size += num2;
					_capacity += num2;
				}
				return (_array[num]);
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
					if (j < numst || j > numfin ) {
						T t = tmp[j];
						_array[i++] = tmp[j];
					}
				}
				_size = _size - (numfin - numst);
				//_array[_size] = 0;
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
			size_t	size() const {
				return _size;
			}

			size_t	capacity() const {
				return _capacity;
			}

			bool	empty() const {
				if (_size)
					return false;
				return true;
			}

//			size_t max_size() const {
//
//				return GetTotalAvailableMemory() /sizeof(vector<T>);
//			}

			void	resize(size_t size) {
				T *tmp;
				if (size > _capacity) {
					tmp = new T[size];
					for (int i = 0; i < size; i++) {
						if (i < _size)
							tmp[i] = _array[i];
						else
							tmp[i] = 0; //t посмотреть с чарами и тд
					}
					delete [] _array;
					_array = tmp;
					_size = size;
					_capacity = size;
				}
				else if (size > _size) {
					for (int i = 0; i < size; i++) {
						if (i > _size)
							_array[i] = 0;
					}
					_size = size;
				}
				else {
					for (int i = 0; i < size; i++) {
						if (i > _size)
							_array[i] = 0;
					}
				}
			}

			void	resize(size_t size, T const & tt) {
				T *tmp;
				if (size > _capacity) {
					tmp = new T[size];
					for (int i = 0; i < size; i++) {
						if (i < _size)
							tmp[i] = _array[i];
						else
							tmp[i] = tt; //t посмотреть с чарами и тд
					}
					delete [] _array;
					_array = tmp;
					_size = size;
					_capacity = size;
				}
				else if (size > _size) {
					for (int i = 0; i < size; i++) {
						if (i > _size)
							_array[i] = tt;
					}
					_size = size;
				}
				else {
					for (int i = 0; i < size; i++) {
						if (i > _size)
							_array[i] = tt;
					}
				}
			}

			void	reserve (size_t n) {
				if (n > _capacity) {
					T *tmp = new T[n];
					T t;
					for (int i = 0; i < n; i++) {
						if (i < _size)
							tmp[i] = _array[i];
						else
							tmp[i] = 0; //t посмотреть с чарами и тд
					}
					delete [] _array;
					_array = tmp;
					_capacity = n;
				}
			}


			//**********	Iterators *********


			//typedef T* iterator;


			value_type * begin() {
				return (_array);
			}

			value_type const * cbegin() {
				return (_array);
			}

			value_type *end() {
				return ((_array + _size));
			}
//
//
//			typedef T* revers_iterator;
//			vector<T>::iterator rbegin() {
//				return (_array + _size - 1);
//			}
//
//			vector<T>::iterator rend() {
//				return (_array - 1);
//			}

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