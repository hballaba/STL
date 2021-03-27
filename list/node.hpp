#ifndef NODE_HPP

# define NODE_HPP

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

#endif /*NODE_HPP*/