#ifndef BIDIRECTIONAL_ITERATOR
#define BIDIRECTIONAL_ITERATOR

#ifndef M_DEBUG
#define M_DEBUG 0
#endif

#include <map>

#include "ft_iterator_traits.hpp"
#include "ft_utils.hpp"

namespace ft
{
// class is templated on 2 types
template <typename NodePtr, typename ValueType>
class map_iterator {
    //---------------MAP ITERATOR TYPEDEFS (iterator
    // traits)---------------------------------
        // define types of member funcs required for itr to be compatible with
        // stl
       public:
        typedef bidirectional_iterator_tag iterator_category;
        typedef NodePtr
            node_pointer;  // is a ptr type that points to node type used in bst
        typedef ValueType value_type;  // type of value stored in the node
        typedef map_iterator<NodePtr, ValueType> mapItr;

        //---------------PROTECTED MEBER
        // FUNCTION------------------------------------------------

       protected:
        mutable node_pointer _current_pointer;
        mutable node_pointer _root_pointer;

        //---------------MAP ITERATOR
        // CONSTRUCTORS-----------------------------------------------

       public:
        //---------------DEFAULT CONSTRUCTOR---------------//
        map_iterator(void) : _current_pointer(NULL), _root_pointer(NULL) {}

        //---------------PARAMETERIZED CONSTRUCTOR---------------//
        map_iterator(node_pointer ptr, node_pointer root_ptr)
            : _current_pointer(ptr), _root_pointer(root_ptr) {}

        //---------------COPY CONSTRUCTOR---------------//
        template <typename n_ptr, typename v_type>
        map_iterator(const map_iterator<n_ptr, v_type> &copy)
            : _current_pointer(copy.base()), _root_pointer(copy.getRootPtr()) {}

        //---------------DESTRUCTOR---------------//
        ~map_iterator() {}

        //---------------BASE()---------------//
        // returns the curr pointer
        const node_pointer base() const { return (_current_pointer); }

        //---------------GETTERS---------------//
        const node_pointer getRootPtr() const { return (_root_pointer); }

        //---------------COPY ASSIGNMENT OPERATOR---------------//
        map_iterator &operator=(map_iterator const &rhs) {
            _current_pointer = rhs._current_pointer;
            _root_pointer = rhs._root_pointer;
            return (*this);
        }

        // returns a ref to value of the node pointed to by the curr ptr
        value_type &operator*(void) const { return (_current_pointer->data); }
        // returns a ptr to the value of the node pointed to by curr ptr
        value_type *operator->(void) const { return &(_current_pointer->data); }

        // moves curr ptr to next node in the tree and returns ref to curr obj
        map_iterator &operator++(void) {
            node_pointer tmp;
            if (_current_pointer == NULL) {
                tmp = _root_pointer;
                while (tmp && tmp->left) tmp = tmp->left;
            } else if (_current_pointer->right)  // if curr ptr is not null, set
                                                 // tmp to leftmost elem in
                                                 // right subtree of curr node
            {
                tmp = _current_pointer->right;
                while (tmp && tmp->left) tmp = tmp->left;
            } else {
                tmp = _current_pointer->parent;
                while (tmp && _current_pointer == tmp->right) {
                    _current_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _current_pointer = tmp;
            return (*this);
        }

        const map_iterator &operator++(void) const {
            node_pointer tmp;
            if (_current_pointer == NULL) {
                tmp = _root_pointer;
                while (tmp && tmp->left) tmp = tmp->left;
            } else if (_current_pointer
                           ->right)  // if right exists, go right once
                                     // and left as long as possible
            {
                tmp = _current_pointer->right;
                while (tmp && tmp->left) tmp = tmp->left;
            } else  // go to parent: while child is bigger -> go further up
            {
                tmp = _current_pointer->parent;
                while (tmp && _current_pointer == tmp->right) {
                    _current_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _current_pointer = tmp;
            return (*this);
        }

        // reurns copy of original obj
        map_iterator operator++(int) {
            map_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        const map_iterator operator++(int) const {
            map_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        map_iterator &operator--(void) {
            node_pointer tmp;
            if (_current_pointer == NULL) {
                tmp = _root_pointer;
                while (tmp && tmp->right) tmp = tmp->right;
            } else if (_current_pointer->left) {
                tmp = _current_pointer->left;
                while (tmp && tmp->right) tmp = tmp->right;
            } else {
                tmp = _current_pointer->parent;
                while (tmp && _current_pointer == tmp->left) {
                    _current_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _current_pointer = tmp;
            return (*this);
        }

        const map_iterator &operator--(void) const {
            node_pointer tmp;
            if (_current_pointer == NULL) {
                tmp = _root_pointer;
                while (tmp && tmp->right) tmp = tmp->right;
            } else if (_current_pointer->left) {
                tmp = _current_pointer->left;
                while (tmp && tmp->right) tmp = tmp->right;
            } else {
                tmp = _current_pointer->parent;
                while (tmp && _current_pointer == tmp->left) {
                    _current_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _current_pointer = tmp;
            return (*this);
        }

        map_iterator operator--(int) {
            map_iterator ret(*this);
            --(*this);
            return (ret);
        }

        const map_iterator operator--(int) const {
            map_iterator tmp(*this);
            --(*this);
            return (tmp);
        }
    };

    //---------------NON-MEMBER OPERATORS---------------//
    template <typename n_ptr, typename v_type>
    bool operator==(const map_iterator<n_ptr, v_type> &lhs,
                    const map_iterator<n_ptr, v_type> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template <typename n_ptr, typename v_type>
    bool operator!=(const map_iterator<n_ptr, v_type> &lhs,
                    const map_iterator<n_ptr, v_type> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template <typename n_ptr1, typename n_ptr2, typename v_type>
    bool operator==(const map_iterator<n_ptr1, v_type> &lhs,
                    const map_iterator<n_ptr2, v_type> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template <typename n_ptr1, typename n_ptr2, typename v_type>
    bool operator!=(const map_iterator<n_ptr1, v_type> &lhs,
                    const map_iterator<n_ptr2, v_type> &rhs) {
        return (lhs.base() != rhs.base());
    }

    template <typename n_ptr1, typename n_ptr2, typename v_type1,
              typename v_type2>
    bool operator==(const map_iterator<n_ptr1, v_type1> &lhs,
                    const map_iterator<n_ptr2, v_type2> &rhs) {
        return (lhs.base() == rhs.base());
    }

    template <typename n_ptr1, typename n_ptr2, typename v_type1,
              typename v_type2>
    bool operator!=(const map_iterator<n_ptr1, v_type1> &lhs,
                    const map_iterator<n_ptr2, v_type2> &rhs) {
        return (lhs.base() != rhs.base());
    }

    // ######################################################################
    // ######################## REVERSE MAP ITERATOR ########################
    // ######################################################################

    template <typename map_iterator>
    class reverse_map_iterator {
        //---------------REVERSE MAP ITERATOR TYPEDEFS (iterator
        // traits)---------------------------------

       public:
        typedef map_iterator iterator_type;
        typedef typename map_iterator::iterator_category iterator_category;
        typedef typename map_iterator::node_pointer node_pointer;
        typedef typename map_iterator::value_type value_type;

       protected:
        iterator_type _base;

       public:
        //---------------DEFAULT CONSTRUCTOR---------------//
        reverse_map_iterator(void) : _base() {
            if (M_DEBUG)
                std::cout << "[_REVERSE_MAP] Default constructor was invoked"
                          << std::endl;
        }

        //---------------PARAMETERIZED CONSTRUCTOR---------------//
        explicit reverse_map_iterator(iterator_type it) : _base(it) {
            if (M_DEBUG)
                std::cout
                    << "[_REVERSE_MAP] Parameterized constructor was invoked"
                    << std::endl;
        }

        //---------------PARAMETERIZED CONSTRUCTOR---------------//
        reverse_map_iterator(node_pointer ptr, node_pointer root_ptr)
            : _base(iterator_type(ptr, root_ptr)) {
            if (M_DEBUG)
                std::cout
                    << "[_REVERSE_MAP] Parameterized constructor was invoked"
                    << std::endl;
        }

        //---------------COPY CONSTRUCTOR---------------//
        reverse_map_iterator(const reverse_map_iterator &src)
            : _base(src.base()) {
            if (M_DEBUG)
                std::cout << "[_REVERSE_MAP] Copy constructor was invoked"
                          << std::endl;
        }

        template <class Iter>
        reverse_map_iterator(const reverse_map_iterator<Iter> &rhs)
            : _base(rhs.base()) {
            if (M_DEBUG)
                std::cout << "[_REVERSE_MAP] Copy constructor with template "
                             "was invoked"
                          << std::endl;
        }

        //---------------DESTRUCTOR---------------//
        ~reverse_map_iterator() {
            if (M_DEBUG)
                std::cout << "[_REVERSE_MAP] Destructor was invoked"
                          << std::endl;
        }

        //---------------REVERSE BASE FUNCTION
        //--------------------------------------------------------------

        iterator_type base() const { return (_base); }

        //---------------COPY ASSIGNMENT OPERATOR---------------//
        template <class U>
        reverse_map_iterator &operator=(const reverse_map_iterator<U> &rhs) {
            _base = rhs._base;
            return (*this);
        }

        value_type &operator*(void) const {
            iterator_type tmp = _base;
            return (*(--tmp));
        }

        value_type *operator->(void) const { return (&(operator*())); }

        reverse_map_iterator &operator++(void) {
            --_base;
            return (*this);
        }

        reverse_map_iterator operator++(int) {
            reverse_map_iterator ret(*this);
            _base--;
            return (ret);
        }

        reverse_map_iterator &operator--(void) {
            ++_base;
            return (*this);
        }

        reverse_map_iterator operator--(int) {
            reverse_map_iterator ret(*this);
            _base++;
            return (ret);
        }
    };

//---------------NON-MEMBER OPERATORS---------------//
template <typename n_ptr1, typename n_ptr2>
bool operator==(const reverse_map_iterator<n_ptr1> &lhs,
                const reverse_map_iterator<n_ptr2> &rhs) {
    return (lhs.base() == rhs.base());
}

template <typename n_ptr1, typename n_ptr2>
bool operator!=(const reverse_map_iterator<n_ptr1> &lhs,
                const reverse_map_iterator<n_ptr2> &rhs) {
    return (lhs.base() != rhs.base());
}
};  // namespace ft

#endif