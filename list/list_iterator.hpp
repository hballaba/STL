#ifndef LIST_ITERATOR_HPP

# define LIST_ITERATOR_HPP

#include <iostream>
#include <iterator>

namespace ft {

    template <class T>
        class myListIterator : public std::iterator<std::bidirectional_iterator_tag, T> {
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;

        private:
//            pointer p;

        public:
        pointer p;
            myListIterator() : p(nullptr) { }

            myListIterator(value_type *x) : p(x) {}

            myListIterator(const myListIterator& it) : p(it.p) {}

            ~myListIterator() { }

            myListIterator & operator=(const myListIterator &copy) {
                if (this == &copy)
                    return (*this);
                this->p = copy.p;
                return (*this);
            }

            value_type& operator * () { return *p; }
            value_type& operator -> () {return p; }

            myListIterator operator ++ () {
                p = p->next;
                return (*this);
            }

            myListIterator operator ++ (int) {
                myListIterator temp(*this);
                operator ++();
                return temp;
            }
            myListIterator& operator -- () {
                p = p->prev;
                return (*this);
            }
            myListIterator& operator -- (int) {
                myListIterator temp(*this);
                operator --();
                return temp;
            }

            bool operator == (const myListIterator & other) const {return (this->p == other.p); }
            bool operator != (const myListIterator & other) const { return (this->p != other.p); }
            bool operator > (const myListIterator & other) const { return (this->p > other.p); }
            bool operator < (const myListIterator & other) const { return (this->p < other.p); }
            bool operator >= (const myListIterator & other) const { return (this->p >= other.p); }
            bool operator <= (const myListIterator & other) const { return (this->p <= other.p); }
        };





};


#endif /*LIST_ITERATOR_HPP*/