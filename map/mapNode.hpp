#ifndef NODE_HPP

#define NODE_HPP
#include <utility>

namespace ft {

	template <class Key, class T>
    class Node {

    public:
        std::pair<Key, T> date;
        Node *left;
        Node *right;
        Node *parent;
	    Node *begin;


        explicit Node(const Key &key = Key(), const T &val = T()) :
        left(nullptr), right(nullptr), parent(nullptr), begin(nullptr)    {
        	date = std::make_pair(key, val);
        }

        Node (const Node &other) : date(other.date), left(other.left), right(other.right) { }

        ~Node () { }

        Node&	operator= (const Node& copy) {
            if (this == &copy)
                return *this;
            this->data = copy.data;
            this->left = copy.left;
            this->right = copy.right;
            return *this;
        }
    };
}




#endif /*NODE_HPP*/