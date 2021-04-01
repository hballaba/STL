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
            typedef Node<T> node;

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

            value_type  operator * () const  { return (p->date); }
            pointer& operator -> () {return *p; }

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

            node*	getp() const { return p; }

            };


    template <typename T>
    class myListConstIterator {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef Node<T> node;

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

        const value_type  operator * () const  { return (p->date); }
        pointer& operator -> () {return *p; }

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



    template <typename T>
    class reversmyListIterator {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef Node<T> node;

    private:
        node *p;



    public:

        reversmyListIterator() : p(nullptr) { }

        reversmyListIterator(node *x) : p(x) { }

        reversmyListIterator(const reversmyListIterator<T>& it) : p(const_cast<node *>(it.p)) { }

        ~reversmyListIterator() { }

        reversmyListIterator & operator=(const reversmyListIterator &copy) {
            if (this == &copy)
                return (*this);
            this->p = copy.p;
            return (*this);
        }

        value_type  operator * () const  { return (p->date); }
        pointer& operator -> () {return *p; }

        reversmyListIterator operator ++ () {
            p = p->prev;
            return (*this);
        }

        reversmyListIterator operator ++ (int) {
            reversmyListIterator temp(*this);
            operator ++();
            return temp;
        }
        reversmyListIterator& operator -- () {
            p = p->next;
            return (*this);
        }
        reversmyListIterator& operator -- (int) {
            reversmyListIterator temp(*this);
            operator --();
            return temp;
        }

        bool operator == (const reversmyListIterator & other) const {return (this->p == other.p); }
        bool operator != (const reversmyListIterator & other) const { return (this->p != other.p); }
        bool operator > (const reversmyListIterator & other) const { return (this->p > other.p); }
        bool operator < (const reversmyListIterator & other) const { return (this->p < other.p); }
        bool operator >= (const reversmyListIterator & other) const { return (this->p >= other.p); }
        bool operator <= (const reversmyListIterator & other) const { return (this->p <= other.p); }

        node*	getp() const { return p; }

    };


    template <typename T>
    class constreversemyListIterator {
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef Node<T> node;

    private:
        node *p;



    public:

        constreversemyListIterator() : p(nullptr) { }

        constreversemyListIterator(node *x) : p(x) { }

        constreversemyListIterator(const constreversemyListIterator<T>& it) : p(const_cast<node *>(it.p)) { }

        ~constreversemyListIterator() { }

        constreversemyListIterator & operator=(const constreversemyListIterator &copy) {
            if (this == &copy)
                return (*this);
            this->p = copy.p;
            return (*this);
        }

        const value_type  operator * () const  { return (p->date); }
        const pointer& operator -> () {return *p; }

        constreversemyListIterator operator ++ () {
            p = p->prev;
            return (*this);
        }

        constreversemyListIterator operator ++ (int) {
            constreversemyListIterator temp(*this);
            operator ++();
            return temp;
        }
        constreversemyListIterator& operator -- () {
            p = p->next;
            return (*this);
        }
        constreversemyListIterator& operator -- (int) {
            constreversemyListIterator temp(*this);
            operator --();
            return temp;
        }

        bool operator == (const constreversemyListIterator & other) const {return (this->p == other.p); }
        bool operator != (const constreversemyListIterator & other) const { return (this->p != other.p); }
        bool operator > (const constreversemyListIterator & other) const { return (this->p > other.p); }
        bool operator < (const constreversemyListIterator & other) const { return (this->p < other.p); }
        bool operator >= (const constreversemyListIterator & other) const { return (this->p >= other.p); }
        bool operator <= (const constreversemyListIterator & other) const { return (this->p <= other.p); }

        node*	getp() const { return p; }

    };




};


#endif /*LIST_ITERATOR_HPP*/