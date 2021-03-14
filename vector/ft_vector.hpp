#ifndef FT_VECTOR_HPP

# define FT_VECTOR_HPP

# include <iostream>
# include <string>


//limite_max /sizof(T);

template <typename T>
class ft_vector {
	private:
		T *_array;
		size_t _size;
		size_t _capacity;
	
	public:
		ft_vector() : _array(nullptr), _size(0), _capacity(0) { }

		ft_vector(size_t const size){
			T t;
			_array = new T[size];
			for(int i = 0; i < size -1; i++)
				_array[i] = t;
			_size = size;
			_capacity = size;
		}

		~ft_vector() {
			delete [] _array;
		}

		ft_vector(ft_vector const & toCopy) {
			if (toCopy._capacity > this->_capacity) {
				delete [] this->_array;
				this->_array = new T[toCopy._capacity];
			}
			for(int i = 0; i < toCopy._capacity; i++)
				this->_array[i] = toCopy._array[i];
			this->_size = toCopy._size;
			this->_capacity = toCopy._capacity;
		}

		ft_vector & operator = (ft_vector const & toCopy) {
			if (toCopy._capacity > this->_capacity) {
				delete [] this->_array;
				this->_array = new T[toCopy._capacity];
			}
			for(int i = 0; i < toCopy._capacity; i++)
				this->_array[i] = toCopy._array[i];
			this->_size = toCopy._size;
			this->_capacity = toCopy._capacity;		
		}

		

		//**********	Modifiers **********
		void	push_back(T const & element) {
			if (_capacity > _size) {  //уже выделена память
				_array[_size - 1] = element;
				_size++;
			}
			else if (_size != 0) {  // надо домалочить
				T *tmp = _array;
				_array = new T[++_size + 1];
				for (int i = 0; i < _size - 1; i++) {
					_array[i] = tmp[i];
					//std::cout << "in " << _array[i];
				}
				//std::cout << std::endl;
				_array[_size - 1] = element;
				delete [] tmp;
				tmp = nullptr;
				_capacity++;
			}
			else {			// новый вектор
				_array = new T[++_size + 1];
				_array[_size - 1] = element;
				_capacity++;
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

		typedef T* iterator;
		
		iterator	insert(iterator pos, T const & element) {
			T* tmp = _array;
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

		void	ft_copy(ft_vector<T> & forCopy, ft_vector<T> const & toCopy) {
			if (toCopy._capacity > forCopy._capacity) {
				delete [] forCopy._array;
				forCopy._array = new T[toCopy._capacity];
			}
			for(int i = 0; i < toCopy._capacity; i++)
				forCopy._array[i] = toCopy._array[i];
			forCopy._size = toCopy._size;
			forCopy._capacity = toCopy._capacity;

		}
		void	swap(ft_vector<T> & toCopy) {
			ft_vector<T> *tmp = new ft_vector<T>;
			ft_copy(*tmp, *this);
			ft_copy(*this, toCopy);
			ft_copy(toCopy, *tmp);
			
			delete tmp;
	
			
		}

		
		//**********	Capacity **********
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

		size_t max_size() const {
			
			return GetTotalAvailableMemory() /sizeof(ft_vector<T>);
		}

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
		
		
		ft_vector<T>::iterator begin() {
			return (_array);
		}

		ft_vector<T>::iterator end() {
			return ((_array + _size));
		}

			
		typedef T* revers_iterator;
		ft_vector<T>::iterator rbegin() {
			return (_array + _size - 1);
		}

		ft_vector<T>::iterator rend() {
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

#endif