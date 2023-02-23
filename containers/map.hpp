#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <map>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../iterators/ft_iterator_traits.hpp"
#include "../iterators/ft_utils.hpp"
#include "binary_search_tree.hpp"

namespace ft {
template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<pair<const Key, T> > >
class map {
   public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef pair<const Key, T> value_type;
    typedef const pair<const Key, T> const_value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef Compare key_compare;
    typedef Alloc alloc_type;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef BST<Key, T, Compare, Alloc> binary_tree;
    typedef typename binary_tree::node_pointer node_pointer;
    typedef typename binary_tree::const_node_pointer const_node_pointer;

    typedef map_iterator<node_pointer, value_type> iterator;
    typedef map_iterator<const_node_pointer, const_value_type> const_iterator;
    typedef reverse_map_iterator<iterator> reverse_iterator;
    typedef reverse_map_iterator<const_iterator> const_reverse_iterator;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***VALUE_COMPARE
    // CLASS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    // this class is helper class to imolement various member
    // functions(find,lower,upper_bound,equal_range) that require comparison of
    // values stored in map container
    class value_compare {
        friend class map;

       protected:
        key_compare _map_compare;  // represents comparison func used to compare
                                   // keys of elems in map
        value_compare(Compare c) : _map_compare(c) {}

       public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;

        // compares keys of 2 value_type objs using map_compare comparison
        // function and returns true if key of 1st object is less than key of
        // 2nd obj, and false otherwise
        bool operator()(const value_type& lhs, const value_type& rhs) const {
            return (_map_compare(lhs.first, rhs.first));
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***CONSTRUCTORS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------DEFAULT
    // CONSTRUCTOR---------------------------------------//
    explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc())
        : _map_compare(comp), _map_allocator(alloc) {
        if (M_DEBUG)
            std::cout << "[BST] Default constructor was invoked" << std::endl;
    }

    //---------------------------RANGE
    // CONSTRUCTOR---------------------------------------//
    template <class InputIt>
    map(InputIt first, InputIt last, const Compare& comp = Compare(),
        const Alloc& alloc = Alloc())
        : _map_compare(comp), _map_allocator(alloc) {
        for (; first != last; first++) this->_root.insertNode(*first);
    }

    //---------------------------COPY
    // CONSTRUCTOR---------------------------------------//
    map(const map& other)
        : _map_compare(other._map_compare),
          _map_allocator(other._map_allocator) {
        _root.deleteAll(_root._bst_root);
        _root.duplicateTree(other._root._bst_root);
    }

    //---------------------------------------DESTRUCTOR-------------------------------------------//
    ~map(void) { clear(); }

    //---------------------------COPY ASSIGNMENT
    // OPERATOR----------------------------------------//
    map& operator=(const map& rhs) {
        if (*this == rhs) return *this;
        _map_allocator = rhs._map_allocator;
        _map_compare = rhs._map_compare;
        _root.deleteAll();
        _root.duplicateTree(rhs._root._bst_root);
        return (*this);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ITERATORS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------ITERATOR
    // METHODS----------------------------------------//
    iterator begin() { return iterator(_root.begin(), _root._bst_root); }

    const_iterator begin() const {
        return const_iterator(_root.begin(), _root._bst_root);
    }

    iterator end() { return iterator(_root.end(), _root._bst_root); }

    const_iterator end() const {
        return const_iterator(_root.end(), _root._bst_root);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(_root.end(), _root._bst_root);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(_root.end(), _root._bst_root);
    }

    reverse_iterator rend() {
        return reverse_iterator(_root.begin(), _root._bst_root);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(_root.begin(), _root._bst_root);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***CAPACITY***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------empty()----------------------------------------//
    bool empty() const { return (_root.empty()); }

    //---------------------------size()----------------------------------------//
    size_type size() const { return (_root.size()); }

    //---------------------------max_size()----------------------------------------//
    size_type max_size() const { return _root.max_size(); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ELEMENT
    // ACCESS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------at()----------------------------------------//
    mapped_type& at(const key_type& key) {
        iterator tmp = find(key);
        if (tmp.base())
            return ((*tmp).second);
        else
            throw std::out_of_range("Invalid key for 'at()'");
    }

    //---------------------------at()
    // const----------------------------------------//
    const mapped_type& at(const key_type& key) const {
        iterator tmp = find(key);
        if (tmp.base())
            return ((*tmp).second);
        else
            throw std::out_of_range("Invalid key for 'at()'");
    }

    //---------------------------operator[]()----------------------------------------//
    mapped_type& operator[](const key_type& key) {
        iterator tmp = find(key);
        if (!tmp.base()) {
            insert(value_type(key, mapped_type()));
        }
        tmp = find(key);
        return ((*tmp).second);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***MODIFIERS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------clear()----------------------------------------//
    void clear() {
        _root.deleteAll();
        _root._bst_size = 0;
    }

    //---------------------------insert() single
    // element----------------------------------------//
    ft::pair<iterator, bool> insert(const value_type& value) {
        ft::pair<iterator, bool> tmp;

        if (_root.sameKeyExists(value.first, _root._bst_root))
            tmp.second = false;
        else
            tmp.second = true;
        tmp.first = iterator(
            _root.insertNode(value),
            _root._bst_root);  // returned [tr is used to construct itr obj
                               // which is them returned as part of "pair"
        return (tmp);
    }

    //---------------------------insert() with
    // hint----------------------------------------//
    iterator insert(iterator position, const value_type& value) {
        (void)position;
        iterator it = find(value.first);
        if (it != end()) return (it);
        return (iterator(_root.insertNode(value), _root._bst_root));
     
    }

    //---------------------------insert()
    // range----------------------------------------//
    template <class InputIt>
    void insert(InputIt first, InputIt last) {
        while (first != last) insert(*first++);
    }

    //---------------------------erase()
    // single----------------------------------------//
    void erase(iterator pos) { _root.erase((*pos).first); }

    //---------------------------erase()
    // range----------------------------------------//
    void erase(iterator first, iterator last) {
        while (first != last) _root.deleteNode((first++).base());
    }

    //---------------------------erase() with
    // key----------------------------------------//
    size_type erase(const Key& key) {
        node_pointer tmp = _root.searchForKey(key);
        if (tmp) {
            _root.erase(key);
            return (1);
        }
        return (0);
    }

    //---------------------------swap()----------------------------------------//
    void swap(map& x) {
        if (this == &x) return;
        this->_root.swap(x._root);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***OBSERVERS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------key_comp()----------------------------------------//
    key_compare key_comp() const { return (_map_compare); }

    //---------------------------value_comp()----------------------------------------//
    value_compare value_comp() const { return (value_compare(_map_compare)); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***OPERATIONS***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //---------------------------count()----------------------------------------//
    size_type count(const key_type& key) const {
        if (_root.sameKeyExists(key, _root._bst_root))
            return (1);
        else
            return (0);
    }

    //---------------------------find()----------------------------------------//
    // returns itr pointing to node if found, otherwise it returns itr pointing
    // to end of tree
    iterator find(const key_type& key) {
        node_pointer tmp = _root.searchForKey(key);
        if (tmp)
            return iterator(tmp, _root._bst_root);
        else
            return iterator(NULL, _root._bst_root);
    }

    //---------------------------find()----------------------------------------//
    const_iterator find(const key_type& key) const {
        node_pointer tmp = _root.searchForKey(key);
        if (tmp)
            return const_iterator(tmp, _root._bst_root);
        else
            return const_iterator(NULL, _root._bst_root);
    }

    //---------------------------equal_range()----------------------------------------//
    ft::pair<iterator, iterator> equal_range(const Key& key) {
        return (
            ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
    }

    //---------------------------equal_range()----------------------------------------//
    ft::pair<const_iterator, const_iterator> equal_range(
        const key_type& key) const {
        return (ft::pair<const_iterator, const_iterator>(lower_bound(key),
                                                         upper_bound(key)));
    }

    //---------------------------lower_bound()----------------------------------------//
    iterator lower_bound(const Key& key) {
        iterator it = begin();
        for (; it != end(); it++) {
            if (!_map_compare(it.base()->data.first, key)) break;
        }
        return (it);
    }

    //---------------------------lower_bound()
    // const----------------------------------------//
    const_iterator lower_bound(const Key& key) const {
        const_iterator it = begin();
        for (; it != end(); it++) {
            if (!_map_compare(it.base()->data.first, key)) break;
        }
        return (it);
    }

    //---------------------------upper_bound()----------------------------------------//
    iterator upper_bound(const Key& key) {
        iterator it = begin();
        for (; it != end(); it++) {
            if (_map_compare(key, it.base()->data.first)) return (it);
        }
        return (end());
    }

    //---------------------------upper_bound()
    // const----------------------------------------//
    const_iterator upper_bound(const Key& key) const {
        const_iterator it = begin();
        for (; it != end(); it++) {
            if (_map_compare(key, it.base()->data.first)) return (it);
        }
        return (end());
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ALLOCATOR***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //-------------------get_allocator()-------------------//
    alloc_type get_allocator(void) const { return _map_allocator; }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***PRIVATE MEMBER
    // ATTRIBUTES***//////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
   private:
    key_compare _map_compare;
    alloc_type _map_allocator;
    binary_tree _root;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//***NON-MEMBER
// METHODS***//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------SWAP
//(non-member)--------------------------------//

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs) {
    lhs.swap(rhs);
}

    //---------------------------RELATIONAL OPERATORS
    //(non-member)--------------------------------//

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs) {
        if (lhs.size() != rhs.size()) return (false);
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs) {
        return (!(lhs == rhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const map<Key, T, Compare, Alloc>& lhs,
                   const map<Key, T, Compare, Alloc>& rhs) {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                            rhs.end()));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs) {
        return (!(rhs < lhs));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const map<Key, T, Compare, Alloc>& lhs,
                   const map<Key, T, Compare, Alloc>& rhs) {
        return (rhs < lhs);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const map<Key, T, Compare, Alloc>& lhs,
                    const map<Key, T, Compare, Alloc>& rhs) {
        return (!(lhs < rhs));
    }

    }  // namespace ft

#endif