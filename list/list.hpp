#ifndef LIST_HPP

# define LIST_HPP

# include "list_iterator.hpp"
# include "node.hpp"


namespace ft {


    template< class T, class Alloc = std::allocator<T> >
	class list {

	public:
		typedef 	T value_type;
		typedef 	Alloc allocator_type;
		typedef 	typename allocator_type::reference 	reference;
		typedef 	typename allocator_type::const_reference const_reference;
		typedef 	typename allocator_type::pointer pointer;
		typedef 	typename allocator_type::const_pointer const_pointer;

        typedef 	ft::myListIterator<value_type> iterator;


		typedef 	ft::myListConstIterator<value_type> const_iterator;
		typedef	ft::reversmyListIterator<value_type> reverse_iterator;
		typedef	ft::constreversemyListIterator<value_type> const_reverse_iterator;
		typedef		ptrdiff_t difference_type;
		typedef		size_t size_type;
		typedef		Node<value_type> * node;

	private:
		node _end;
		size_t _size;
		allocator_type _alloc;


	public:

		explicit list (const allocator_type& alloc = allocator_type()) :
			_end(nullptr), _size(0), _alloc(alloc) {
		    _end = new Node<T>();
            _end->next = _end;
            _end->prev = _end;
		}
		
		explicit list (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) {
            _size = 0;
            _end = new Node<T>();
            _end->next = _end;
            _end->prev = _end;
            assign(n, val);
            _size = n;
		}

		
		template <class InputIterator>
  		list (InputIterator first, InputIterator last,
        		const allocator_type& alloc = allocator_type(), char (*)[sizeof(*first)] = NULL) {
            _size = 0;
		    _end = new Node<T>();
            _end->next = _end;
            _end->prev = _end;
			
            while (first != last) {
                push_back(*first);
                first++;
            }
		}
		
		list (const list& x) : _alloc(x._alloc), _size(0) {
                _end = new Node<T>();
                _end->next = _end;
                _end->prev = _end;
                const_iterator st = x.begin();
            for (size_t i = 0; i < x._size; i++) {
	            push_back(*st);
    			st++;
            }
  		}

		~list() {
			clear();
			delete _end;



		};

        list &operator=(list const &toCopy) {
          	this->clear();
			
		  	this->_end->next = this->_end;
            this->_end->prev = this->_end;
                const_iterator st = toCopy.begin();
            for (int i = 0; i < toCopy._size; i++) {
	            push_back(*st);
    			st++;
            }
		  	 return *this;
        }


        /***************    Iterators ************/

        iterator begin() {return iterator(_end->next); }

        const_iterator begin() const {return const_iterator(_end->next); }

        iterator end() {return iterator(_end); }

        const_iterator end() const {return const_iterator( _end); }

        reverse_iterator rbegin() {
            return reverse_iterator(_end->prev);
        }
        const_reverse_iterator rbegin() const;

        reverse_iterator rend() {
            return reverse_iterator(_end);
        }
        const_reverse_iterator rend() const;


        /************** Capacity  *****************/

        bool empty() const {
            if (_size)
                return false;
            return true;
        }
        size_type size() const {return _size; }

        size_type max_size() const {return std::numeric_limits<size_t>::max() / sizeof(Node<T>) ; }

        /************* Element access *************/

        reference front() { return _end->next->date; };
        const_reference front() const {return _end->next->date; } ;

        reference back(){return _end->prev->date; } ;
        const_reference back() const{return _end->prev->date; } ;

        /***************** Modifiers   ******************/

        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
            clear();
            size_t i = -1;
            while (first != last) {
                push_back(*first);
                first++;
            }

        }

        void assign (size_type n, const value_type& val) {
            clear();
            while (n > 0) {
                push_back(val);
                --n;
            }
        }

        void push_front (const value_type& val) {
            Node<T>	*tmp = new Node<T>(val);
            tmp->next = _end->next;
            tmp->prev = _end;
            tmp->next->prev = tmp;
            _end->next = tmp;
            _size++;
        }

        void pop_front() {
            if(_size > 0) {
                Node<T> *tmp = _end->next;
                _end->next->next->prev = _end;
                _end->next = _end->next->next;
                delete tmp;
                _size--;
            }
        }

        void push_back (const value_type& val){
            Node<T>	*tmp = new Node<T>(val);
            tmp->next = _end;
            tmp->prev = _end->prev;
            _end->prev->next = tmp;
            _end->prev = tmp;
            _size++;
        }

        void pop_back() {
            if (_size > 0)
            {
                Node<T>	*tmp = _end->prev;
                _end->prev = tmp->prev;
                _end->prev->next = _end;

                delete tmp;
                _size--;
            }
        }

        iterator insert (iterator position, const value_type& val) {
            Node<T> *tmp = new Node<T>(val);

            tmp->next = position.getp();
            tmp->prev = position.getp()->prev;
            tmp->prev->next = tmp;
            tmp->next->prev = tmp;
            _size++;
            return iterator(tmp);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            while (n-- > 0)
                insert(position, val);
        }

        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
            while (first != last) {
                insert(position, *first);
                first++;
            }
        }

        iterator erase (iterator position) {
            Node<T> *tmp = position.getp();
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            position++;
            _size--;
            return (position);
        }

        iterator erase (iterator first, iterator last, char (*)[sizeof(*first)] = NULL) {
            while (first != last) {
                erase(first);
                first++;
            }
            return (first);
        }

        void swap (list& x) {
            list tmp(x);
            x = *this;
            *this = tmp;

        }

        void resize (size_type n, value_type val = value_type()) {
            while (n > _size)
                push_back(val);
            while (n < _size)
                pop_back();
        }

        void clear() {
            while (_size > 0) {
                pop_front();
            }
        }

            /*************  Operations  **************/

        void splice (iterator position, list& x) {
            splice(position, x, x.begin(), x.end());
        }

        void splice (iterator position, list& x, iterator i) {
            iterator temp = i;
            temp++;
            this->splice(position, x, i, temp);
        }

        void splice (iterator position, list& x, iterator first, iterator last, char (*)[sizeof(*first)] = NULL) {
            size_type i = 0;
            iterator tmp = first;
            while (tmp != last) {
                tmp++;
                i++;
            }
            Node<T> *it = position.getp();
            Node<T> *st = first.getp();
            Node<T> *fin = last.getp();
            Node<T> *temp = fin->prev;

            st->prev->next = fin;
            fin->prev = st->prev;
            it->prev->next = st;
            st->prev =it->prev;
            it->prev = temp;
            temp->next = it;

            this->_size += i;
            x._size -= i;
        }

        void remove (const value_type& val) {
            iterator st = begin();
            iterator fin = end();
            while (st != fin) {
                if (*st == val)
                    erase(st);
                st++;
            }
        }

        template <class Predicate>
        void remove_if (Predicate pred) {
            iterator st = begin();
            iterator fin = end();
            while (st != fin) {
                if (pred(*st))
                    erase(st);
                st++;
            }
        }

        void unique() {
            iterator st = begin();
            iterator fin = end();
            while (st != fin) {
                if (*st == st.getp()->prev->date)
                    erase(st);
                st++;
            }
        }

        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred) {
            iterator st = begin();
            iterator fin = end();
            while (st != fin) {
                if (binary_pred(*st, st.getp()->prev->date))
                    erase(st);
                st++;
            }

        }

        void merge (list& x) {
            if (&x == this)
                return;
            insert(end(), x.begin(), x.end());
            x.clear();
            sort();
        }

        template <class Compare>
        void merge (list& x, Compare comp) {
            if (&x == this)
                return;
            insert(end(), x.begin(), x.end());
            x.clear();
            sort(comp);
        }

        void sort() {
            iterator st = begin();
            iterator fin = end();

            while (++st != fin) {
                if (*st < st.getp()->prev->date){
                 value_type temp = *st;
                 st.getp()->date = st.getp()->prev->date;
                 st.getp()->prev->date = temp;
                 st = begin();
                }
            }
        }

        template <class Compare>
        void sort (Compare comp) {
            iterator st = begin();
            iterator fin = end();

            while (++st != fin) {
                if (comp(*st, st.getp()->prev->date)){
                    value_type temp = *st;
                    st.getp()->date = st.getp()->prev->date;
                    st.getp()->prev->date = temp;
                    st = begin();
                }
            }
        }

        void reverse() {
            if (_size < 2)
                return ;
            iterator st = begin();
            size_type i = -1;
            Node<T>* tmp;
            while (++i < _size) {
                tmp = st.getp()->prev;
                st.getp()->prev = st.getp()->next;
                st.getp()->next = tmp;
                --st;
            }
            tmp = _end->prev;
            _end->prev = _end->next;
            _end->next = tmp;

        }

	};


        /*************** Non-member function overloads  ********/


    template <class T, class Alloc>
    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
        if (lhs.size() != rhs.size())
           return false;
        typename list<T>::const_iterator list1 = lhs.begin();
        typename list<T>::const_iterator list2 = rhs.begin();
        while (list1 != lhs.end()) {
            if (*(list1++) != *(list2++))
                return (false);
        }
        return true;
    }

    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
        return (!(lhs == rhs));
    }

    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){

        if (lhs.size() < rhs.size())
            return true;
        if (lhs.size() > rhs.size())
            return false;
        typename list<T>::const_iterator cur1 = lhs.begin();
        typename list<T>::const_iterator cur2 = rhs.begin();
        while (cur1 != lhs.end())
        {
            if (*cur1 != *cur2)
                return (*cur1 < *cur2);
            cur1++;
            cur2++;
        }
        return false;
    }

    template <class T, class Alloc>
    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
        return (!(rhs < lhs));
    }

    template <class T, class Alloc>
    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
        return (rhs < lhs);
    }

    template <class T, class Alloc>
    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
        return (!(lhs < rhs));
    }

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)  {
        list<T,Alloc>	tmp(x);
        x = y;
        y = tmp;
    }
}

#endif /*LIST_HPP*/