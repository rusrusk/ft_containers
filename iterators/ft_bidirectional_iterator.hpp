#ifndef BIDIRECTIONAL_ITERATOR
#define BIDIRECTIONAL_ITERATOR

#ifndef M_DEBUG
#define M_DEBUG 0
#endif

#include <map>

// #include "../containers/binary_search_tree.hpp"
#include "ft_iterator_traits.hpp"
#include "ft_utils.hpp"

namespace ft
{
    template <typename NodePtr, typename ValueType>
    class map_iterator {
       public:
            typedef bidirectional_iterator_tag      iterator_category;
            typedef NodePtr                             node_ptr;
            typedef ValueType                               value_type;
            typedef map_iterator<NodePtr, ValueType>            mapItr;
        // typedef key key_type;
        // typedef T mapped_type;
        // typedef ft::pair<const key_type, mapped_type> value_type;
        // typedef std::size_t size_type;
        // typedef std::ptrdiff_t difference_type;
        // typedef const value_type &const_reference;
        // typedef typename BST<key_type, mapped_type>::node *node_ptr;

       protected:
        mutable node_ptr    _root_pointer;
        mutable node_ptr    _curr_pointer; 
        // mutable node_ptr _first;
        // mutable node_ptr _last;

       public:
       //-------------------DEFAULT CONSTRUCTOR-------------------//
        map_iterator() : _root_pointer(NULL), _curr_pointer(NULL) {
            if (M_DEBUG)
                std::cout << "[MAP] Default constructor was invoked" << std::endl;
        };
    	//-------------------PARAMETERIZED CONSTRUCTOR-------------------//
        map_iterator(node_ptr root_ptr, node_ptr curr_ptr)
            :   _root_pointer(root_ptr),
                _curr_pointer(curr_ptr) 
        {
            if (M_DEBUG)
                std::cout << "[MAP] Parameterized constructor was invoked"
                          << std::endl;
        }

    	template <typename node_p, typename val_type> 
    	map_iterator(const map_iterator<node_p, val_type> &rhs)
            :   _root_pointer(rhs.getRootPointer()),   
    		    _curr_pointer(rhs.base())
    
    	{

    	}

        ~map_iterator() {
            if (M_DEBUG) std::cout << "[MAP] Destructor was invoked" << std::endl;
        }

        // map_iterator(const map_iterator &rhs)
        //     : _pointer(rhs._pointer), _first(rhs._first), _last(rhs.last) {
        //     if (M_DEBUG)
        //         std::cout << "[MAP] Copy constructor was invoked" << std::endl;
        // }

        //-------------------GETTER//-------------------//
        const node_ptr getRootPointer() const { return this->_root_pointer; }

        const node_ptr base() const { return this->_curr_pointer; }

        //-------------------OPERATORS//-------------------//
        map_iterator &operator=(map_iterator const &rhs) {
            if (M_DEBUG)
                std::cout << "[MAP] Copy assignment operator was invoked"
                          << std::endl;
            _curr_pointer = rhs._curr_pointer;
            _root_pointer = rhs._root_pointer;
            return *this;
        }

        // const map_iterator &operator=(const map_iterator &rhs) const {
        //     if (M_DEBUG)
        //         std::cout << "[MAP] Const Copy assignment operator was invoked"
        //                   << std::endl;
        //     _root_pointer = rhs._root_pointer;
        //     _curr_pointer = rhs._curr_pointer;
        //     return *this;
        // }

        map_iterator &operator++() {
            node_ptr tmp;
            if (!_curr_pointer)
            {
                tmp = _root_pointer;
                while (tmp && tmp->left)
                    tmp = tmp->left;
            }
            else if (_curr_pointer->right)
            {
                tmp = _curr_pointer->right;
                while (tmp && tmp->left)
                    tmp = tmp->left;
            }
            else
            {
                tmp = _curr_pointer->parent;
                while (tmp && _curr_pointer == tmp->right)
                {
                    _curr_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _curr_pointer = tmp;
            // _curr_pointer = plusPlus(_curr_pointer);
            return *this;
        }

		// node_ptr plusPlus(node_ptr current) {

		// 		node_ptr tmp;
		// 		if (current == NULL)
		// 		{
		// 			tmp = _root_pointer;
		// 			while (tmp && tmp->left)
		// 				tmp = tmp->left;
		// 		}
		// 		else if (current->right) // if right exists, go right once and left as long as possible
		// 		{
		// 			tmp = current->right;
		// 			while (tmp && tmp->left)
		// 				tmp = tmp->left;
		// 		}
		// 		else // go to parent: while child is bigger -> go further up
		// 		{
		// 			tmp = current->parent;
		// 			while (tmp && current == tmp->right)
		// 			{
		// 				current = tmp;
		// 				tmp = tmp->parent;
		// 			}
		// 		}
		// 		return (tmp);
		// }       


        map_iterator operator++(int) {
            map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const map_iterator operator++(int) const {
            map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        map_iterator &operator--() {
            node_ptr tmp;
            if (!_curr_pointer)
            {
                tmp = _root_pointer;
                while (tmp && tmp->right)
                    tmp = tmp->right;
            }
            else if (_curr_pointer->left)
            {
                tmp = _curr_pointer->left;
                while (tmp && tmp->right)
                    tmp = tmp->right;
            }
            else
            {
                tmp = _curr_pointer->parent;
                while (tmp && _curr_pointer == tmp->left)
                {
                    _curr_pointer = tmp;
                    tmp = tmp->parent;
                }
            }
            _curr_pointer = tmp;
            // _curr_pointer = minusMinus(_curr_pointer);
            return *this;
        }


			// node_ptr minusMinus(node_ptr current) {

			// 	node_ptr tmp;
				
			// 	if (current == NULL)
			// 	{
			// 		tmp = _root_pointer;
			// 		while (tmp && tmp->right)
			// 			tmp = tmp->right;
			// 	}
			// 	else if (current->left) // if left exists, go left once and right as long as possible
			// 	{
			// 		tmp = current->left;
			// 		while (tmp && tmp->right)
			// 			tmp = tmp->right;
			// 	}
			// 	else // go to parent: while parent is bigger -> go further up
			// 	{
			// 		tmp = current->parent;
			// 		while (tmp && current == tmp->left)
			// 		{
			// 			current = tmp;
			// 			tmp = tmp->parent;
			// 		}
			// 	}
			// 	return (tmp);
			// }

        // const map_iterator &operator--() const {
        //     node_ptr tmp;
        //     if (!_curr_pointer)
        //     {
        //         tmp = _root_pointer;
        //         while (tmp && tmp->right)
        //             tmp = tmp->right;
        //     }
        //     else if (_curr_pointer->left)
        //     {
        //         tmp = _curr_pointer->left;
        //         while (tmp && tmp->right)
        //             tmp = tmp->right;
        //     }
        //     else
        //     {
        //         tmp = _curr_pointer->parent;
        //         while (tmp && _curr_pointer == tmp->left)
        //         {
        //             _curr_pointer = tmp;
        //             tmp = tmp->parent;
        //         }
        //     }
        //     _curr_pointer = tmp;
        //     return *this;
        // }

        map_iterator operator--(int) {
            map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        const map_iterator operator--(int) const {
            map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        value_type *operator->() const { return (&(_curr_pointer->data)); }

        // const value_type *operator->() const { return &(_pointer->data); }

        value_type &operator*() const { return (_curr_pointer->data); }

        // const value_type &operator*() const {
        //     return (static_cast<node_ptr>(_pointer)->data);


        // friend bool operator==(const map_iterator<key_type, mapped_type> &lhs,
        //                        const map_iterator<key_type, mapped_type> &rhs) {
        //     return lhs->getPointer() == rhs.getPointer();
        // }

        // friend bool operator!=(const map_iterator<key_type, mapped_type> &lhs,
        //                        const map_iterator<key_type, mapped_type> &rhs) {
        //     return lhs->getPointer() != rhs->getPointer();
        // }
    };

    template <typename k, typename v_type>
    bool operator==(const map_iterator<k, v_type>  &lhs, const map_iterator<k, v_type>  &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <typename k, typename v_type>
    bool operator!=(const map_iterator<k, v_type>  &lhs, const map_iterator<k, v_type>  &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <typename k1, typename k2, typename v_type>
    bool operator==(const map_iterator<k1, v_type>  &lhs, const map_iterator<k2, v_type>  &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <typename k1, typename k2, typename v_type>
    bool operator!=(const map_iterator<k1, v_type>  &lhs, const map_iterator<k2, v_type>  &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <typename k1, typename k2, typename v_type1, typename v_type2>
    bool operator==(const map_iterator<k1, v_type1>  &lhs, const map_iterator<k2, v_type2>  &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <typename k1, typename k2, typename v_type1, typename v_type2>
    bool operator!=(const map_iterator<k1, v_type1>  &lhs, const map_iterator<k2, v_type2>  &rhs)
    {
        return (lhs.base() != rhs.base());
    }


    //----------------------REVERSE ITERATOR----------------------------------//
    template <typename map_iterator>
    class reverse_map_iterator  
    {
       public:
            typedef map_iterator                                iterator_type;
            typedef typename map_iterator::iterator_category    iterator_category;
            typedef typename map_iterator::node_ptr             node_pointer;
            typedef typename map_iterator::value_type           value_type;
        // typedef key											key_type;
        // typedef T											mapped_type;
        // typedef ft::pair<const key_type, mapped_type>		value_type;
        // typedef std::size_t									size_type;
        // typedef std::ptrdiff_t								difference_type;
        // typedef const value_type							&const_reference;
        // typedef typename BST<key_type, mapped_type>::node	*node_pointer;

       protected :

        // mutable node_pointer _pointer;
        // mutable node_pointer _first;
        // mutable node_pointer _last;
            iterator_type   _base;

       public:
       //-------------------DEFAULT CONSTRUCTOR-------------------//
        reverse_map_iterator() : _base() {
            if (M_DEBUG)
                std::cout << "[_REVERSE_MAP] Default constructor was invoked"
                          << std::endl;
        };

       //-------------------PARAMETERIZED CONSTRUCTOR-------------------//
        reverse_map_iterator(iterator_type it)
            : _base(it) {
            if (M_DEBUG)
                std::cout << "[REVERSE_MAP] Parameterized constructor was invoked"
                          << std::endl;
        }

        reverse_map_iterator(node_pointer ptr, node_pointer root_ptr) : _base(iterator_type(ptr, root_ptr))
        {

        }

       //-------------------DESTRUCTOR-------------------//
        ~reverse_map_iterator() {
            if (M_DEBUG)
                std::cout << "[REVERSE_MAP] Destructor was invoked" << std::endl;
        }

       //-------------------COPY CONSTRUCTOR-------------------//
        reverse_map_iterator(const reverse_map_iterator &rhs)
            : _base(rhs.base()) {
            if (M_DEBUG)
                std::cout << "[REVERSE_MAP] Copy constructor was invoked"
                          << std::endl;
        }

        template <typename Iter>
        reverse_map_iterator(const reverse_map_iterator<Iter> &rhs)
            :   _base(rhs.base())
        {

        }

       //-------------------GETTERS-------------------//
        iterator_type base() const { return _base; }

        // node_pointer getPointer() const { return _pointer; }

        // node_pointer getFirst() const { return _first; }

        // node_pointer getLast() const { return _last; }

        //----------------------OVERLOAD
        //OPERATORS----------------------------------//
        template <typename U>
        reverse_map_iterator &operator=(const reverse_map_iterator<U> &rhs) {
            // _pointer = rhs.getPointer();
            // _first = rhs.getFirst();
            // _last = rhs.getLast();
            _base = rhs._base;
            return *this;
        }

        // const reverse_map_iterator &operator=(
        //     const reverse_map_iterator &rhs) const {
        //     _pointer = rhs.getPointer();
        //     _first = rhs.getFirst();
        //     _last = rhs.getLast();
        //     return *this;
        // }

        reverse_map_iterator &operator--() {
            ++_base;
            return *this;
        }

        // const reverse_map_iterator &operator--() const {
        //     if (!_pointer)
        //         _pointer = _first;
        //     else if (_pointer->right != NULL) {
        //         _pointer = _pointer->right;
        //         while (_pointer->left != NULL) {
        //             _pointer = _pointer->left;
        //         }
        //     } else {
        //         node_pointer tmp = _pointer->parent;
        //         while (tmp && _pointer == tmp->right) {
        //             _pointer = tmp;
        //             tmp = tmp->parent;
        //         }
        //         _pointer = tmp;
        //     }
        //     return *this;
        // }

        reverse_map_iterator operator++(int) {
            reverse_map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        const reverse_map_iterator operator++(int) const {
            reverse_map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reverse_map_iterator &operator++() {
            --_base;
            return *this;
        }

        // const reverse_map_iterator &operator++() const {
        //     if (!_pointer)
        //         _pointer = _last;
        //     else if (_pointer && _pointer->left != NULL) {
        //         _pointer = _pointer->left;
        //         while (_pointer && _pointer->right != NULL) {
        //             _pointer = _pointer->right;
        //         }
        //     } else {
        //         node_pointer tmp = _pointer->parent;
        //         while (tmp && _pointer == tmp->left) {
        //             _pointer = tmp;
        //             tmp = tmp->parent;
        //         }
        //         _pointer = tmp;
        //     }
        //     return *this;
        // }

        reverse_map_iterator operator--(int) {
            reverse_map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        const reverse_map_iterator operator--(int) const {
            reverse_map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        value_type *operator->() const { return (&(operator*())); }

        // const value_type *operator->() const { return (&(_pointer->data)); }

        value_type &operator*() const
        {
            iterator_type tmp = _base;
            return (*(--tmp));
        }



        // const value_type &operator*() const {
        //     return (static_cast<node_ptr>(_pointer)->data);
        // }

        // friend bool operator==(
        //     const reverse_map_iterator<key_type, mapped_type> &lhs,
        //     const reverse_map_iterator<key_type, mapped_type> &rhs) {
        //     return lhs.getPointer() == rhs.getPointer();
        // }

        // friend bool operator!=(
        //     const reverse_map_iterator<key_type, mapped_type> &lhs,
        //     const reverse_map_iterator<key_type, mapped_type> &rhs) {
        //     return !(lhs.getPointer() == rhs.getPointer());
        // }
    };

    template <typename key1, typename key2>
    bool operator==(const reverse_map_iterator<key1>  &lhs, const reverse_map_iterator<key2>  &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <typename key1, typename key2>
    bool operator!=(const reverse_map_iterator<key1>  &lhs, const reverse_map_iterator<key2>  &rhs)
    {
        return (lhs.base() != rhs.base());
    }
};  // namespace ft

    #endif