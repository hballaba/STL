#ifndef LIST_ITERATOR_HPP

# define LIST_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "node.hpp"


//template< class T > struct remove_const                { typedef T type; };
//template< class T > struct remove_const<const T>       { typedef T type; };

namespace ft {

    template< class T > struct remove_const                { typedef T type; };
    template< class T > struct remove_const<const T>       { typedef T type; };

        template <typename T>
        class myListIterator {
            typedef T value_type;
            typedef T* pointer;
            typedef T& reference;
//            typedef Node<T> node;
            typedef Node<T> node;
            //typedef myListIterator<T>  iterator;

        private:
            node *p;



        public:

            myListIterator() : p(nullptr) { }

            myListIterator(node *x) : p(x) { }

            myListIterator(const myListIterator<T>& it) : p(const_cast<node *>(it.p)) { }

            ~myListIterator() { }

            myListIterator & operator=(const myListIterator &copy) {
                if (this == &copy)
                    return (*this);
                this->p = copy.p;
                return (*this);
            }

//            reference operator * () { return *p; }
            value_type  operator * () const  { return (p->date); }
            //value_type& operator * () { return (p->date); }
//            pointer& operator -> () {return *p; }

//

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

//            node getp() {
//
//                return p;
//            }
//            node*	getnext() const { return p->next; }
            node*	getprev() const { return p->prev; }
            node*	getp() const { return p; }

            };


    template <typename T>
    class myListConstIterator {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
//            typedef Node<T> node;
        typedef Node<T> node;
        //typedef myListConstIterator<T>  iterator;

    private:
        node *p;

    public:

        myListConstIterator() : p(nullptr) { }

        myListConstIterator(node *x) : p(x) { }

        myListConstIterator(const myListConstIterator<T>& it) : p(it.p) { }

        ~myListConstIterator() { }

        myListConstIterator & operator=(const myListConstIterator &copy) {
            if (this == &copy)
                return (*this);
            this->p = copy.p;
            return (*this);
        }

//            reference operator * () { return *p; }
        const value_type  operator * () const  { return (p->date); }
        //value_type& operator * () { return (p->date); }
//            pointer& operator -> () {return *p; }

//

        myListConstIterator operator ++ () {
            p = p->next;
            return (*this);
        }

        myListConstIterator operator ++ (int) {
            myListConstIterator temp(*this);
            operator ++();
            return temp;
        }
        myListConstIterator& operator -- () {
            p = p->prev;
            return (*this);
        }
        myListConstIterator& operator -- (int) {
            myListConstIterator temp(*this);
            operator --();
            return temp;
        }

        bool operator == (const myListConstIterator & other) const {return (this->p == other.p); }
        bool operator != (const myListConstIterator & other) const { return (this->p != other.p); }
        bool operator > (const myListConstIterator & other) const { return (this->p > other.p); }
        bool operator < (const myListConstIterator & other) const { return (this->p < other.p); }
        bool operator >= (const myListConstIterator & other) const { return (this->p >= other.p); }
        bool operator <= (const myListConstIterator & other) const { return (this->p <= other.p); }

        node getp() {

            return p; }
   };



};


#endif /*LIST_ITERATOR_HPP*/