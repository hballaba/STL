#ifndef MAP_HPP

# define MAP_HPP

template < class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
        class Compare = std::less<Key>,                     // map::key_compare
        class Alloc = allocator<std::pair<const Key,T> >    // map::allocator_type
> class map {

public:



    typedef std::pair<const Key, T> value_type;








public:

    explicit map (const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type()){

    }

    template <class InputIterator>
    map (InputIterator first, InputIterator last,
         const key_compare& comp = key_compare(),
         const allocator_type& alloc = allocator_type()){

    }

    map (const map& x){

    }

    ~map(){

    }

    map& operator= (const map& x);





};



#endif /*MAP_HPP*/