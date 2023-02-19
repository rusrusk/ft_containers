#ifndef BST_HPP
#define BST_HPP

#include <cstdio>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../iterators/ft_iterator_traits.hpp"
#include "../iterators/ft_utils.hpp"

namespace ft
{
    //---------------------------------------STRUCT------------------------------------------//
    template <typename Key, typename T>
    struct node {
        node *left;
        node *right;
        node *parent;
        ft::pair<const Key, T> data;
    };

    template <typename Key, typename T, typename Compare = std::less<Key>,
              typename Allocator = std::allocator<ft::pair<const Key, T> > >
    class BST {
       public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const Key, T> value_type;
        typedef const pair<const Key, T> const_value_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;

        typedef node<Key, T> *node_pointer;
        typedef const node<Key, T> *const_node_pointer;

        typedef ft::map_iterator<node_pointer, value_type> iterator;
        typedef ft::map_iterator<const_node_pointer, const_value_type> const_iterator;
        typedef ft::reverse_map_iterator<iterator> reverse_iterator;
        typedef ft::reverse_map_iterator<const_iterator> const_reverse_iterator;

    //---------------------------------------PRIVATE
    // ATTRIBUTES------------------------------------------//
   public:
    size_type _size;
    allocator_type _allocator;
    std::allocator<node<Key, T> > _node_allocator;
    key_compare _comp;

    //---------------------------------------PUBLIC
    // ATTRIBUTES------------------------------------------//
   public:
    node<Key, T> *_root;

   public:
    //---------------------------------------DEFAULT
    // CONSTRUCTOR------------------------------------------//
    BST(const Compare &comp = Compare()) : _size(0), _comp(comp), _root(NULL)  {
        if (M_DEBUG)
            std::cout << "[BST] Default constructor was invoked" << std::endl;
    }

    //---------------------------------------OVEERLOAD
    // OPERATORS------------------------------------------//
    BST &operator=(const BST &rhs) {
        // _root = rhs._root;
        // _size = rhs._size;
        // _allocator = rhs._allocator;
        // _node_allocator = rhs._node_allocator;
        removeAll();
        duplicate_tree(rhs.getRoot());
        return *this;
    }

    bool operator==(const BST &rhs) { return (getRoot() == rhs.getRoot()); }

    bool operator!=(const BST &rhs) { return !(getRoot() == rhs.getRoot()); }

    //---------------------------------------DESTRUCTOR------------------------------------------//
    ~BST() {
        if (M_DEBUG) std::cout << "[BST] Destructor was invoked" << std::endl;
    }

    //-------------------COPY STUFF-------------------//

    void duplicate_tree(node_pointer root = NULL) {
        if (!root) return;
        insertNode(root->data);
        duplicate_tree(root->left);
        duplicate_tree(root->right);
    }

    //-------------------ITERATOR METHODS-------------------//
    node_pointer begin(void) const {
        node_pointer tmp = this->_root;
        while (tmp && tmp->left) tmp = tmp->left;
        return tmp;
    }

    node_pointer end(void) const {
        node_pointer tmp = this->_root;
        if (!tmp) return NULL;
        while (tmp && tmp->right) tmp = tmp->right;
        return tmp->right;
    }

    // node_pointer rbegin() const {
    //     node_pointer tmp = this->_root;
    //     while (tmp && tmp->right) {
    //         tmp = tmp->right;
    //     }
    //     return tmp;
    // }

    // node_pointer rend() const {
    //     node_pointer tmp = this->_root;
    //     while (tmp && tmp->left) {
    //         tmp = tmp->left;
    //     }
    //     tmp = tmp->left;
    //     return tmp;
    // }

    //-------------------CAPACITY-------------------//
    bool empty() const { return this->_size = 0; }

    size_type size() const { return this->_size; }

    size_type max_size() const { return this->_allocator.max_size(); }

    //-------------------MODIFIERS-------------------//
    node_pointer newNode(const value_type &value, node_pointer parent = NULL) {
        node_pointer new_node = _node_allocator.allocate(1);
        _allocator.construct(&(new_node->data), value);
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = parent;
        ++_size;
        return new_node;
    }

    node_pointer insertNode(const value_type &data) {
        if (!_root) {
            _root = newNode(data);
            return _root;
        }
        node_pointer found = findKey(data.first);
        if (found) return found;
        node_pointer tmp = NULL;
        found = _root;
        while (found) {
            tmp = found;
            if (_comp(data.first, found->data.first))
                found = found->left;
            else
                found = found->right;
        }
        found = newNode(data, tmp);
        if (_comp(data.first, tmp->data.first))
            tmp->left = found;
        else
            tmp->right = found;
        return found;
    }

    node_pointer treeMinimumNode(node_pointer bst) const {
        if (M_DEBUG) std::cout << "[BST] <Minimum Node>" << std::endl;
        node_pointer curr = bst;
        while (curr && curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }

    node_pointer treeMaximumNode(node_pointer bst) const {
        if (M_DEBUG) std::cout << "[BST] <Maximum Node>" << std::endl;
        node_pointer curr = bst;
        while (curr && curr->right != NULL) {
            curr = curr->right;
        }
        return curr;
    }

    //-----------------------DELETE OPERATIONS-----------------------//
    void removeLeaf(node_pointer deleted) {
        if (!deleted) return;
        node_pointer parent = deleted->parent;
        if (!parent)
            _root = NULL;
        else if (deleted == parent->left)
            parent->left = NULL;
        else if (deleted == parent->right)
            parent->right = NULL;
        _node_allocator.destroy(deleted);
        _node_allocator.deallocate(deleted, 1);
        --_size;
    }

    void removeNode(node_pointer to_delete) {
        if (M_DEBUG) std::cout << "[binary_search_tree.hpp] : removeNode()\n";
        if (!to_delete) return;
        if ((to_delete->left == NULL) && (to_delete->right == NULL))
            removeLeaf(to_delete);
        else {
            node_pointer next;
            if (to_delete->left)
                next = getPredecessor(to_delete);
            else
                next = getSuccessor(to_delete);
            if (!swapNode(to_delete, next)) _root = next;
            removeNode(to_delete);
        }
    }

    size_type erase_elem(const Key &key) {
        if (M_DEBUG) std::cout << "[binary_search_tree.hpp] : erase()\n";
        node_pointer found = findKey(key);
        if (!_root || !found) return 0;
        removeNode(found);
        return (1);
    }

    void removeAll(node_pointer root_arg = NULL) {
        if (!root_arg) root_arg = _root;
        if (!root_arg) return;
        if (root_arg->right) removeAll(root_arg->right);
        if (root_arg->left) removeAll(root_arg->left);
        removeLeaf(root_arg);
    }

    //-----------------------CRUCIAL FUNCTIONS-----------------------//
    // extract_key takes a value of any type and and returns the value.
    // template <class value>
    // value extract_key(value val) {
    //     return (val);
    // }

    // template <class first, class second>
    // first extract_key(ft::pair<first, second> pair) {
    //     return pair.first;
    // }

    // void changeData(node_pointer curr, const value_type &value) {
    //     _allocator.construct(&(curr->data), value);
    // }

    //---------PREDECESSOR AND SUCCESSOR----------//
    node_pointer getPredecessor(node_pointer node_value) {
        if (node_value->left != NULL)
            return treeMaximumNode(node_value->left);
        else {
            node_pointer tmp_parent = node_value->parent;
            while (tmp_parent != NULL && node_value == tmp_parent->left) {
                node_value = tmp_parent;
                tmp_parent = tmp_parent->parent;
            }
            node_value = tmp_parent;
        }
        return node_value;
    }

    // if the subtree of node_value is not empty, the successor of node_value is
    // just leftmost node in node_value's right subtree which is
    // treeMinimumNode(). else right subtree is empty and node_value has
    // successor tmp_parent, then tmp_parent is lowest ancestor of node_value
    // whose left child is also an ancestor of node_value.
    node_pointer getSuccessor(node_pointer node_value) {
        if (node_value->right)
            return treeMinimumNode(node_value->right);
        else {
            node_pointer tmp_parent = node_value->parent;
            while (tmp_parent && node_value == tmp_parent->right) {
                node_value = tmp_parent;
                tmp_parent = tmp_parent->parent;
            }
            node_value = tmp_parent;
        }
        return node_value;
    }

    //-----------------------SWAP METHOD-----------------------//
    static bool swapNode(node_pointer first_node, node_pointer second_node) {
        if (M_DEBUG) std::cout << "[binary_search_tree.hpp] : swapNode()\n";
        node_pointer first_parent = first_node->parent;
        node_pointer first_left_node = first_node->left;
        node_pointer first_right_node = first_node->right;
        node_pointer second_parent = second_node->parent;
        node_pointer second_left_node = second_node->left;
        node_pointer second_right_node = second_node->right;

        if (first_parent && first_parent->left == first_node)
            first_parent->left = second_node;
        else if (first_parent)
            first_parent->right = second_node;
        second_node->parent = first_parent;
        if (second_parent && second_parent->left == second_node)
            second_parent->left = first_node;
        else if (second_parent)
            second_parent->right = first_node;
        if (second_parent != first_node)
            first_node->parent = second_parent;
        else
            first_node->parent = second_node;
        if (first_left_node == second_node) {
            second_node->left = first_node;
            second_node->right = first_right_node;
        } else if (first_right_node == second_node) {
            second_node->right = first_node;
            second_node->left = first_left_node;
        } else {
            second_node->left = first_left_node;
            second_node->right = first_right_node;
        }
        if (first_right_node && first_right_node != second_node)
            first_right_node->parent = second_node;
        if (first_left_node && first_left_node != second_node)
            first_left_node->parent = second_node;
        first_node->left = second_left_node;
        if (second_left_node) second_left_node->parent = first_node;
        first_node->right = second_right_node;
        if (second_right_node) second_right_node->parent = first_node;
        if (!first_parent) return false;
        return true;
    }

    //-----------------------OBSERVERS-----------------------//
    bool similar_key_exists(const key_type &data, node_pointer curr) const {
        if (!curr) return false;
        if (curr->data.first <= data)
            return similar_key_exists(data, curr->right);
        else if (curr->data.first >= data)
            return similar_key_exists(data, curr->left);
        else
            return true;
    }

    node_pointer getRoot() const { return this->_root; }

    // I set ret to root of bst. It then enters loop that iterates until either
    // ret == null or the key of curr node is equal to desired key. In each
    // iteration, the function uses _comp func to compare desired key and key of
    // curr node. If desired key is less than curr, the func sets ret to the
    // left child of curr node. If desired key is more than curr, ret goes to
    // the right child of curr node. extract_key is used to allow findKey be
    // used with diff typed of data stored in bst.
    node_pointer findKey(const key_type &key) const {
        node_pointer result = _root;
        while (result && result->data.first != key) {
            if (_comp(key, result->data.first))
                result = result->left;
            else
                result = result->right;
        }
        return result;
    }

    node_pointer getToRoot() const {
        node_pointer tmp_root = _root;
        while (tmp_root->parent) tmp_root = tmp_root->parent;
        return tmp_root;
    }

    bool _isLeaf(node_pointer bst) const {
        return (bst->left == NULL && bst->right == NULL);
    }

    bool _isEmpty(node_pointer bst) const { return bst = NULL; }
    };
};  // namespace ft

#endif