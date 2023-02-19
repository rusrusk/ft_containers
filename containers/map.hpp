#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <map>
#include <vector>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../iterators/ft_iterator_traits.hpp"
#include "../iterators/ft_utils.hpp"
#include "binary_search_tree.hpp"

namespace ft {
template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<pair<const Key, T> > >
class map {
   public:
    typedef Key                                                     key_type;
    typedef T                                                       mapped_type;
    typedef pair<const Key, T>                                      value_type;
    typedef const pair<const Key, T>                                const_value_type;
    typedef Compare                                                 key_compare;
    typedef Allocator                                               allocator_type;
    typedef typename allocator_type::reference                      reference;
    typedef typename allocator_type::const_reference                const_reference;
    typedef typename allocator_type::pointer                        pointer;
    typedef typename allocator_type::const_pointer                  const_pointer;
    typedef std::ptrdiff_t                                          difference_type;
    typedef std::size_t                                             size_type;
	typedef BST<Key, T, Compare, Allocator>								binary_tree;
    typedef typename binary_tree::node_pointer                      node_pointer;
    typedef typename binary_tree::const_node_pointer             	const_node_pointer;
    // typedef typename BST<key_type, mapped_type>::node               			node;

    typedef map_iterator<node_pointer, value_type>				            				iterator;
    typedef map_iterator<const_node_pointer, const_value_type>						const_iterator;
    typedef reverse_map_iterator<iterator>                        							reverse_iterator;
    typedef reverse_map_iterator<const_iterator>			                  				const_reverse_iterator;

    // typedef ft::map_iterator<node_pointer, value_type>            				iterator;
    // typedef const ft::map_iterator<const_node_pointer, const_value_type>        const_iterator;
    // typedef ft::reverse_map_iterator<iterator>                        			reverse_iterator;
    // typedef const ft::reverse_map_iterator<const_iterator>                  	const_reverse_iterator;

   private:
    binary_tree					_root;
    key_compare                 _compare;
    allocator_type              _allocator;

   public:
    
    explicit map(const key_compare &comp = key_compare(),
                 const allocator_type &alloc = allocator_type())
        : _root(), _compare(comp), _allocator(alloc) {
        if (M_DEBUG)
            std::cout << "[BST] Default constructor was invoked" << std::endl;
    }

    //-------------------RANGE CONSTRUCTOR-------------------//
    template <typename InputIterator>
    map(InputIterator first, InputIterator last,
        const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type())
        : _compare(comp), _allocator(alloc) {
        InputIterator tmp = first;
        while (tmp != last)
            insert(*tmp++);
    }

    //-------------------COPY CONSTRUCTOR-------------------//
    map(const map &rhs) : _compare(rhs._compare), _allocator(rhs._allocator) {
		this->_root.removeAll(_root.getRoot());
        this->_root.duplicate_tree(rhs._root.getToRoot());
    }

    //-------------------DESTRUCTOR-------------------//
    ~map() { clear(); }

    map &operator=(const map &rhs) {
        if (*this == rhs) return *this;
        _root.removeAll();
        _root.duplicate_tree(rhs._root.getToRoot());
        return *this;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***VALUE_COMPARE
    // CLASS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    class value_compare {
        friend class map;

       protected:
        key_compare comp;
        value_compare(Compare c) : comp(c) {}

       public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;

        bool operator()(const value_type &x, const value_type &y) const {
            return comp(x.first, y.first);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***CAPACITY***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //-------------------empty()-------------------//
    bool empty() const { return (_root.size() == 0); }

    size_type size() const { return _root.size(); }

    size_type max_size() const { return _root.max_size(); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ELEMENT
    // ACCESS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------operator[]-------------------//
    mapped_type &operator[](const key_type &key) {
        // return ((*(this->insert(ft::make_pair(key, mapped_type())))));
        iterator tmp = find(key);
        if (!tmp.base())
            insert(value_type(key, mapped_type()));
        tmp = find(key);
        return ((*tmp).second);
    }

    mapped_type &at(const key_type &key) {
        iterator tmp = find(key);
        if (tmp == end())
            throw std::out_of_range("at() element is not in the range");
        return tmp->second;
    }

    const mapped_type &at(const key_type &key) const {
        iterator tmp = find(key);
        if (tmp == end())
            throw std::out_of_range("at() element is not in the range");
        return tmp->second;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***MODIFIERS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------insert()-------------------//
    // single element
    pair<iterator, bool> insert(const value_type &val) {
        if (M_DEBUG)
            std::cout << "[map] insert() [single element] was invoked"
                      << std::endl;
        ft::pair<iterator, bool> tmp;
        if (_root.similar_key_exists(val.first, _root.getRoot()))
            tmp.second = false;
        else
            tmp.second = true;
        tmp.first = iterator(_root.insertNode(val), _root.getRoot());
        return tmp;
    }

    //-------------------insert()-------------------//
    // with hint
    iterator insert(iterator position, const value_type &val) {
        if (M_DEBUG)
            std::cout << "[map] insert() [with hint] was invoked" << std::endl;
        (void)position;
        iterator it = find(val.first);
        if (it != end()) return it;
        return (iterator(_root.insertNode(val), _root._root));
    }

    //-------------------insert()-------------------//
    // range
    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last) {
        if (M_DEBUG)
            std::cout << "[map] insert() [by range] was invoked" << std::endl;
        while (first != last)
            insert(*first++);
    }

    //-------------------erase()-------------------//
    void erase(iterator position) {
        if (M_DEBUG)
            std::cout << "[map] erase() [single element] was invoked"
                      << std::endl;
        _root.erase_elem(((*position).first));
    }

    size_type erase(const key_type &key) {
        if (M_DEBUG)
            std::cout << "[map] erase() [by key] was invoked" << std::endl;
        if (_root.findKey(key)) {
            _root.erase_elem(key);
            return 1;
        }
        return 0;
    }

    void erase(iterator first, iterator last) {
        if (M_DEBUG)
            std::cout << "[map] erase() [with range] was invoked" << std::endl;
        while (first != last) _root.removeNode((++first).base());
    }

    //-------------------swap()-------------------//
    void swap(map &x) {
        BST<key_type, mapped_type> tmp_root;
        key_compare tmp_compare;
        allocator_type tmp_allocator;

        tmp_root = _root;
        tmp_compare = _compare;
        tmp_allocator = _allocator;

        _root = x._root;
        _compare = x._compare;
        _allocator = x._allocator;

        x._root = tmp_root;
        x._compare = tmp_compare;
        x._allocator = tmp_allocator;
    }

    //-------------------clear()-------------------//
    void clear()
	{ 
		_root.removeAll(); 
		_root._size = 0;
	}

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***OBSERVERS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    key_compare key_comp() const { return _compare; }

    value_compare value_comp() const { return value_compare(_compare); }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***OPERATIONS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //-------------------find()-------------------//
    iterator find(const key_type &key) {
        // return (iterator(this->_root.findKey(key)));
        node_pointer tmp = _root.findKey(key);
        if (tmp)
            return iterator(tmp, _root._root);
        else
            return iterator(NULL, _root._root);
    }

    const_iterator find(const key_type &key) const {
        node_pointer tmp = _root.findKey(key);
        if (tmp)
            return iterator(tmp, _root._root);
        else
            return iterator(NULL, _root._root);
    }

    //-------------------count()-------------------//
    size_type count(const key_type &key) const {
        if (!_root.findKey(key)) return 0;
        return 1;
    }

    //-------------------lower_bound()-------------------//
    iterator lower_bound(const Key &key) {
        iterator it = begin();
        while (it != end() && _compare(it->first, key)) ++it;
        return it;
    }

    const_iterator lower_bound(const Key &key) const {
        const_iterator it = begin();
        while (it != end() && _compare(it->first, key)) ++it;
        return it;
    }

    //-------------------upper_bound()-------------------//
    iterator upper_bound(const Key &key) {
        iterator it = begin();
        while (it != end() && !_compare(key, it->first)) ++it;
        return it;
    }

    const_iterator upper_bound(const Key &key) const {
        const_iterator it = begin();
        while (it != end() && !_compare(key, it->first)) ++it;
        return it;
    }

    //-------------------equal_range()-------------------//
    ft::pair<iterator, iterator> equal_range(const key_type &key) {
        return (ft::make_pair(lower_bound(key), upper_bound(key)));
    }
    ft::pair<const_iterator, const_iterator> equal_range(
        const key_type &key) const {
        return (ft::make_pair(lower_bound(key), upper_bound(key)));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ITERATORS***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------begin()-------------------//
    iterator begin() {
        return iterator(_root.begin(), _root._root);
    }

    const_iterator begin() const {
        return const_iterator(_root.begin(), _root._root);
    }

    iterator end() { return iterator(_root.end(), _root._root); }

    const_iterator end() const {
        return const_iterator(_root.end(), _root._root);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(_root.end(), _root._root);
    }

    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(_root.end(), _root._root);
    }

    reverse_iterator rend() {
        return reverse_iterator(_root.begin(), _root._root);
    }

    const_reverse_iterator rend() const {
        return const_reverse_iterator(_root.begin(), _root._root);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //***ALLOCATOR***/////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    //-------------------get_allocator()-------------------//
    allocator_type get_allocator() const { return _allocator; }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//***NON-MEMBER METHODS  -  RELATIONAL OPERATORS***//////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Key, typename T, typename Compare, typename Alloc>
void swap(ft::map<Key, T, Compare, Alloc> &lhs,
          ft::map<Key, T, Compare, Alloc> &rhs) {
    lhs.swap(rhs);
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator==(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs) {
    if (lhs.size() != rhs.size()) return false;
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs) {
    return (!(lhs == rhs));
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &lhs,
               const map<Key, T, Compare, Alloc> &rhs) {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                        rhs.end()));
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &lhs,
               const map<Key, T, Compare, Alloc> &rhs) {
    return (lhs < rhs);
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs) {
    return (!(rhs < lhs));
}

template <typename Key, typename T, typename Compare, typename Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
                const map<Key, T, Compare, Alloc> &rhs) {
    return (!(lhs < rhs));
}
}  // namespace ft

#endif