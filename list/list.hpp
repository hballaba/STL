#ifndef LIST_HPP

# define LIST_HPP

# include "list_iterator.hpp"

namespace ft {

    template<class T>
    class Node {
    public:
        T date;
        Node *next;
        Node *prev;

        explicit Node(const T &val = T()) : date(val), next(nullptr), prev(nullptr) { }

        Node(const Node &other) : date(other.date), next(other.next), prev(other.prev) { }

        ~Node() { }

        Node&	operator= (const Node& copy) {
            if (this == &copy)
                return *this;
            this->data = copy.data;
            this->next = copy.next;
            this->prev = copy.prev;
            return *this;
        }
    };
}

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

        typedef 	ft::myListIterator<Node<value_type> > iterator;


		// typedef 	ft::constMyIterator<value_type> const_iterator;
		// typedef		ft::reversMyIterator<value_type> reverse_iterator;
		// typedef		ft::reversConstMyIterator<value_type> const_reverse_iterator;
		typedef		ptrdiff_t difference_type;
		typedef		size_t size_type;
		//typedef		std::allocator<T> type_alloc;
		typedef		Node<value_type> * node;

	private:
		node _begin;
		node _end;
		size_t _size;
		allocator_type _alloc;


	public:

		explicit list (const allocator_type& alloc = allocator_type()) :
			_begin(nullptr), _end(nullptr), _size(0), _alloc(alloc) {
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
            assign(first, last);
		}
		
		list (const list& x) : _alloc(x._alloc), _size(0) {
                _end = new Node<T>();
                _end->next = _end;
                _end->prev = _end;
                list<T>::iterator st = x._begin();
//                list::iterator fin = x._end();
//                assign(st, fin);
		}

		~list() {
			//clear;
			// null cheсk 
			//_alloc.dealocate(_begin);
			//_alloc.dealocate(_end);

		};

        list &operator=(list const &toCopy) {
//            if (toCopy._capacity != this->_capacity) {
//                for (size_t i = 0; i < this->_size; i++) {
//                    this->_alloc.destroy(this->_array + i);
//                }
//                if (this->_capacity > 0) {
//                    this->_alloc.deallocate(this->_array, this->_capacity);
//                }
//                this->_array = _alloc.allocate(toCopy._capacity);
//            }
//            for (size_t i = 0; i < toCopy._size; i++)
//                this->_alloc.construct(this->_array + i, toCopy._array[i]);
//            this->_size = toCopy._size;
//            this->_capacity = toCopy._capacity;
//            return *this;
        }


        /***************    Iterators ************/
//
        iterator begin() {return iterator(_end->next); }
//        const_iterator begin() const {};
//
        iterator end() {return _end; }
//        const_iterator end() const;
//
//        reverse_iterator rbegin();
//        const_reverse_iterator rbegin() const;
//
//        reverse_iterator rend();
//        const_reverse_iterator rend() const;


        /************** Capacity  *****************/

        bool empty() const {
            if (_size)
                return false;
            return true;
        }
        size_type size() const {return _size; }
        size_type max_size() const {return allocator_type().max_size(); }


        /************* Element access *************/

        reference front() { return _end->next->date; };
        const_reference front() const {return _end->next->date; } ;

        reference back(){return _end->prev->date; } ;
        const_reference back() const{return _end->prev->date; } ;

    /***************** Modifiers   ******************/

    template <class InputIterator>
    void assign (InputIterator first, InputIterator last, char (*)[sizeof(*first)] = NULL) {
        clear();
        int i = 0;
        while (first != last) {
            Node<T> t = *first;
            Node<T>	*tmp = new Node<T>(t.date);
            tmp->next = _end;
            tmp->prev = _end->prev;
            _end->prev->next = tmp;
            _end->prev = tmp;
            _size++;
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
        _end->prev->prev = tmp;
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
            Node<T>	*tmp = _end->prev->prev;
            tmp->next = _end;
            delete _end->prev;
            _end->prev = tmp;
            _size--;
        }
    }

//    iterator insert (iterator position, const value_type& val);
//
//    void insert (iterator position, size_type n, const value_type& val);
//
//    template <class InputIterator>
//    void insert (iterator position, InputIterator first, InputIterator last);

//    iterator erase (iterator position);
//    iterator erase (iterator first, iterator last);

    void swap (list& x) {}

    void resize (size_type n, value_type val = value_type()) {}

    void clear() {
        while (_size > 0) {
            pop_back();
        }
    };

        /*************  Operations  **************/

//    void splice (iterator position, list& x);
//
//    void splice (iterator position, list& x, iterator i);
//
//    void splice (iterator position, list& x, iterator first, iterator last);

    void remove (const value_type& val) { }

    template <class Predicate>
    void remove_if (Predicate pred) {}

    void unique() {}

    template <class BinaryPredicate>
    void unique (BinaryPredicate binary_pred) {}

    void merge (list& x) { }

    template <class Compare>
    void merge (list& x, Compare comp) { }

    void sort() {}

    template <class Compare>
    void sort (Compare comp) {}

    void reverse() {}


















	};


//    list& operator= (const list& x);
//
//    reference front(void)
//    {
//        return (_list_begin->next->data);
//    };

//    template <class T, class Alloc>
//    void swap (list<T,Alloc>& x, list<T,Alloc>& y);
//
//    template <class T, class Alloc>
//    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        if (lhs.size() != rhs.size())
//            return (false);
//        typename List<T>::const_iterator cur1 = lhs.begin();
//        typename List<T>::const_iterator cur2 = rhs.begin();
//        while (cur1 != lhs.end())
//        {
//            if (*(cur1++) != *(cur2++))
//                return (false);
//        }
//        return (true);
//    };
//
//    template <class T, class Alloc>
//    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        return (!(lhs == rhs));
//    };
//
//    template <class T, class Alloc>
//    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        if (lhs.size() < rhs.size())
//            return (true);
//        if (lhs.size() > rhs.size())
//            return (false);
//        typename list<T>::const_iterator cur1 = lhs.begin();
//        typename list<T>::const_iterator cur2 = rhs.begin();
//        while (cur1 != lhs.end())
//        {
//            if (*cur1 != *cur2)
//                return (*cur1 < *cur2);
//            cur1++;
//            cur2++;
//        }
//        return (false);
//    };
//
//    template <class T, class Alloc>
//    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        return (!(rhs < lhs));
//    };
//
//    template <class T, class Alloc>
//    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        return (rhs < lhs);
//    };
//
//    template <class T, class Alloc>
//    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
//        return (!(lhs < rhs));
//    };
//
//
//    //need metods
//    //newNode

}

#endif /*LIST_HPP*/