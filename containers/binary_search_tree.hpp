#ifndef BST_HPP
#define BST_HPP

#include <cstdio>

#include "../iterators/ft_bidirectional_iterator.hpp"
#include "../iterators/ft_iterator_traits.hpp"
#include "../iterators/ft_utils.hpp"

namespace ft {
template <typename Key, typename T>
// struct representing a node of BST
struct Node {
    ft::pair<const Key, T> data;  // Key is type of key and T is type of value
    Node* left;
    Node* right;
    Node* parent;
};

// Compare is comparator func object that compares 2 keys of type "Key" and
// returns bool indication whether 1st arg is less than 2nd
template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Alloc = std::allocator<ft::pair<const Key, T> > >
class BST {
    // types to define iterator types and other types of class
   public:
    typedef Key key_type;   // type of keys stored in map
    typedef T mapped_type;  // type of values stored in map
    typedef pair<const Key, T>
        value_type;  // type of elems stored in map, which is pair of const key
                     // and value
    typedef const pair<const Key, T> const_value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;  // diff between 2 itrs
    typedef Compare
        key_compare;  // binary func object used to compare keys in map
    typedef Alloc alloc_type;
    typedef typename Alloc::reference
        reference;  // aliases for ref and const_ref types used to access elems
                    // in map
    typedef typename Alloc::const_reference const_reference;
    typedef typename Alloc::pointer
        pointer;  // aliases for pointer and const_pointer types used to access
                  // elems in map
    typedef typename Alloc::const_pointer const_pointer;
    typedef Node<Key, T>* node_pointer;  // ptr to a node in the map
    typedef const Node<Key, T>* const_node_pointer;

    typedef map_iterator<node_pointer, value_type>
        iterator;  // custom itr type used to iterate over elems in map
    typedef map_iterator<const_node_pointer, const_value_type> const_iterator;
    typedef reverse_map_iterator<iterator> reverse_iterator;
    typedef reverse_map_iterator<const_iterator> const_reverse_iterator;

    //---------------------------MEMBER
    // ATTRIBUTES---------------------------------------//
   public:
    key_compare _bst_compare;
    std::allocator<Node<Key, T> > _node_allocator;
    alloc_type _bst_allocator;
    size_type _bst_size;

   public:
        Node<Key, T>* _bst_root;

   public:
    //---------------------------CONSTRUCTOR---------------------------------------//
    BST(const Compare& comp = Compare())
        : _bst_compare(comp), _bst_size(0), _bst_root(NULL) {
        if (M_DEBUG)
            std::cout << "[BST] Default constructor was invoked" << std::endl;
    }

    //---------------------------------------DESTRUCTOR-------------------------------------------//
    ~BST() {
        if (M_DEBUG) std::cout << "[BST] Destructor was invoked" << std::endl;
    }

    //---------------------------COPY ASSIGNMENT
    // OPERATOR----------------------------------------//
    BST& operator=(const BST& rhs) {
        deleteAll();
        duplicateTree(rhs.getRoot());
        return (*this);
    }

    //---------------------------COPY
    // STUFF---------------------------------------// takes ptr to the root and
    // recursively duplcates entire tree by inserting data of each node into a
    // new tree
    void duplicateTree(node_pointer root = NULL) {
        if (root == NULL) return;
        insertNode(root->data);
        duplicateTree(root->left);
        duplicateTree(root->right);
    }

    //---------------------------GETTERS---------------------------------------//
    node_pointer getBstRoot(void) const { return _bst_root; }

    //---------------------------ITERATORS---------------------------------------//
    node_pointer begin(void) const {
        node_pointer tmp = _bst_root;
        while (tmp && tmp->left) tmp = tmp->left;
        return (tmp);
    }

    node_pointer end(void) const {
        node_pointer tmp = _bst_root;
        if (!tmp) return (NULL);
        while (tmp && tmp->right) tmp = tmp->right;
        return (tmp->right);
    }

    //---------------------------CAPACITY----------------------------------------//

    bool empty() const { return !_bst_size; }

    size_type size() const { return _bst_size; }

    size_type max_size() const { return _bst_allocator.max_size(); }

    //---------------------------MODIFIERS----------------------------------------//

    node_pointer createNewNode(const value_type& new_data,
                               node_pointer parent = NULL) {
        node_pointer newNode = _node_allocator.allocate(1);
        _bst_allocator.construct(&(newNode->data), new_data);
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = parent;
        _bst_size++;
        return (newNode);
    }

    node_pointer insertNode(const value_type& data) {
        //start at root of tree
        //if tree is empty, create new node and set it as root
    //     if (_bst_root == NULL)
    //     {
    //         _bst_root = createNewNode(data);
    //         return _bst_root;
    //     }
    //     //otherwise compare key of newelem to key of curr node
    //     node_pointer tmp = _bst_root;
    //     while (true)
    //     {
    //         //if key of newelem is less than key of curr node, go left
    //         if (data.first < tmp->data.first)
    //         {
    //             if (tmp->left == NULL)
    //             {
    //                 tmp->left = createNewNode(data, tmp);
    //                 return tmp->left;
    //             }
    //             else
    //                 tmp = tmp->left;
    //         }
    //         //if key of newelem is less than key of curr node, go right
    //         else if (data.first > tmp->data.first)
    //         {
    //             //creating new node and attaching to leaf node as the left or right child, dependin on comparison
    //             if (tmp->right == NULL)
    //             {
    //                 tmp->right = createNewNode(data, tmp);
    //                 return tmp->right;
    //             }
    //             else
    //                 tmp = tmp->right;
    //         }
    //         //if equal, elem is already in the tree and no further action is required
    //         else
    //             return tmp;
    //     }
    // }

    //     if (_bst_root == NULL) {
    //         _bst_root = createNewNode(data);
    //         return _bst_root;
    //     }
    //     node_pointer found = searchForKey(data.first); //<-- do i need this? insertNode only called if key is not found, i might avoid redundant traversal
    //     if (found != NULL) {
    //         return found;
    //     }
    //     node_pointer parent = NULL;
    //     node_pointer current = _bst_root;
    //     while (current != NULL) {
    //         parent = current;
    //         if (_bst_compare(data.first, current->data.first)) {
    //             current = current->left;
    //         } else {
    //             current = current->right;
    //         }
    //     }
    //     node_pointer newNode = createNewNode(data, parent);
    //     if (_bst_compare(data.first, parent->data.first)) {
    //         parent->left = newNode;
    //     } else {
    //         parent->right = newNode;
    //     }
    //     return newNode;
    // }
        //here i directly insert newnode at correct position, without need for additional call searchForKey.
        //also i use iterative approach instead of recursive one, and check if tree is empty to avoid unnecessary comparison when inserting root node
        node_pointer parent = NULL;
        node_pointer curr = _bst_root;
        while (curr != NULL)
        {
            parent = curr;
            if (_bst_compare(data.first, curr->data.first))
                curr = curr->left;
            else if (_bst_compare(curr->data.first, data.first))
                curr = curr->right;
            else
                return curr;
        }
        node_pointer newNode = createNewNode(data, parent);
        if (parent == NULL)
            _bst_root = newNode;
        else if (_bst_compare(data.first, parent->data.first))
            parent->left = newNode;
        else
            parent->right = newNode;
        return newNode;
    }

    // node_pointer insertNode(const value_type& data) {
    // node_pointer parent = NULL;
    // node_pointer curr = _bst_root;
    // while (curr != NULL)
    // {
    //     parent = curr;
    //     if (_bst_compare(data.first, curr->data.first))
    //         curr = curr->left;
    //     else if (_bst_compare(curr->data.first, data.first))
    //         curr = curr->right;
    //     else
    //         return curr;
    // }
    // node_pointer newNode = createNewNode(data, parent);
    // if (parent == NULL)
    //     _bst_root = newNode;
    // else if (_bst_compare(data.first, parent->data.first))
    //     parent->left = newNode;
    // else
    //     parent->right = newNode;
    // // AVL balancing
    // balanceTree(newNode);
    // return newNode;
    // }
    

    // void balanceTree(node_pointer node) {
    //     while (node != NULL) {
    //         int balanceFactor = getBalanceFactor(node);
    //         if (balanceFactor > 1) {
    //             if (getBalanceFactor(node->left) < 0) {
    //                 rotateLeft(node->left);
    //             }
    //             rotateRight(node);
    //         } else if (balanceFactor < -1) {
    //             if (getBalanceFactor(node->right) > 0) {
    //                 rotateRight(node->right);
    //             }
    //             rotateLeft(node);
    //         }
    //         node = node->parent;
    //     }
    // }

    // int getBalanceFactor(node_pointer node) {
    //     int leftHeight = getHeight(node->left);
    //     int rightHeight = getHeight(node->right);
    //     return leftHeight - rightHeight;
    // }

    // int getHeight(node_pointer node) {
    //     if (node == NULL) {
    //         return 0;
    //     } else {
    //         int leftHeight = getHeight(node->left);
    //         int rightHeight = getHeight(node->right);
    //         return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    //     }
    // }

    // void rotateLeft(node_pointer node) {
    //     node_pointer rightChild = node->right;
    //     rightChild->parent = node->parent;
    //     if (node->parent == NULL) {
    //         _bst_root = rightChild;
    //     } else if (node == node->parent->left) {
    //         node->parent->left = rightChild;
    //     } else {
    //         node->parent->right = rightChild;
    //     }
    //     node->right = rightChild->left;
    //     if (rightChild->left != NULL) {
    //         rightChild->left->parent = node;
    //     }
    //     node->parent = rightChild;
    //     rightChild->left = node;
    // }

    // void rotateRight(node_pointer node) {
    //     node_pointer leftChild = node->left;
    //     leftChild->parent = node->parent;
    //     if (node->parent == NULL) {
    //         _bst_root = leftChild;
    //     } else if (node == node->parent->left) {
    //         node->parent->left = leftChild;
    //     } else {
    //         node->parent->right = leftChild;
    //     }
    //     node->left = leftChild->right;
    //     if (leftChild->right != NULL) {
    //         leftChild->right->parent = node;
    //     }
    //     node->parent = leftChild;
    //     leftChild->right = node;
    // }


    //---------------------------REMOVAL
    // METHODS---------------------------------------//
    void deleteNode(node_pointer to_delete) {
        if (!to_delete) return;
        if ((!to_delete->left) && (!to_delete->right))
            deleteLeaf(to_delete);
        else {
            node_pointer next;
            if (to_delete->left)
                next = getPredecessor(to_delete);
            else
                next = getSuccessor(to_delete);
            if (!swapNodeValue(to_delete, next)) _bst_root = next;
            deleteNode(to_delete);
        }
    }

    size_type erase(const key_type& key) {
        node_pointer found = searchForKey(key);

        if (!_bst_root || !found) return (0);
        deleteNode(found);
        return (1);
    }

    void deleteLeaf(node_pointer to_delete) {
        if (to_delete == NULL) return;
        node_pointer parent = to_delete->parent;
        if (parent == NULL)
            _bst_root = NULL;
        else if (to_delete == parent->left)
            parent->left = NULL;
        else if (to_delete == parent->right)
            parent->right = NULL;
        _node_allocator.destroy(to_delete);
        _node_allocator.deallocate(to_delete, 1);
        _bst_size--;
    }

    void deleteAll(node_pointer root = NULL) {
        if (root == NULL) root = _bst_root;
        if (root == NULL) return;
        if (root->left != NULL) deleteAll(root->left);
        if (root->right != NULL) deleteAll(root->right);
        deleteLeaf(root);
    }

    //---------------------------PREDECESSOR AND SUCCESSOR
    // METHODS---------------------------------------//
    static node_pointer getSuccessor(node_pointer node) {
        if (node->right != NULL)
            return treeMinimumNode(node->right);
        else {
            node_pointer parent = node->parent;
            while (parent != NULL && node == parent->right) {
                node = parent;
                parent = parent->parent;
            }
            node = parent;
        }
        return node;
    }

    static node_pointer getPredecessor(node_pointer node) {
        if (node->left != NULL)
            return treeMaximumNode(node->left);
        else {
            node_pointer parent = node->parent;
            while (parent != NULL && node == parent->left) {
                node = parent;
                parent = parent->parent;
            }
            node = parent;
        }
        return node;
    }

    //---------------------------SWAP
    // STUFF---------------------------------------// returns bool val
    // indicating
    // whether root of tree was changed during swap saves all vars, updates
    // parent n child ptrs of both nodes to point to other node also updates
    // parent ptr of childrent of both nodes updates left and right children of
    // both nodes to their orig values, and updates parent ptrs of those
    // children
    static bool swapNodeValue(node_pointer node1, node_pointer node2) {
        node_pointer parent1 = node1->parent;
        node_pointer node1Left = node1->left;
        node_pointer node1Right = node1->right;
        node_pointer parent2 = node2->parent;
        node_pointer node2Left = node2->left;
        node_pointer node2Right = node2->right;

        if (parent1 != NULL && parent1->left == node1)
            parent1->left = node2;
        else if (parent1 != NULL)
            parent1->right = node2;
        node2->parent = parent1;

        if (parent2 != NULL && parent2->left == node2)
            parent2->left = node1;
        else if (parent2 != NULL)
            parent2->right = node1;
        if (parent2 != node1)
            node1->parent = parent2;
        else
            node1->parent = node2;

        if (node1Left == node2) {
            node2->left = node1;
            node2->right = node1Right;
        } else if (node1Right == node2) {
            node2->right = node1;
            node2->left = node1Left;
        } else {
            node2->left = node1Left;
            node2->right = node1Right;
        }

        if (node1Right && node1Right != node2) node1Right->parent = node2;
        if (node1Left && node1Left != node2) node1Left->parent = node2;

        node1->left = node2Left;
        if (node2Left) node2Left->parent = node1;
        node1->right = node2Right;
        if (node2Right) node2Right->parent = node1;

        if (parent1 == NULL) return false;
        return true;
    }

    void swap(BST& other) {
        if (this == &other) return;
        std::swap(this->_bst_root, other._bst_root);
        std::swap(this->_bst_size, other._bst_size);
    }

    //---------------------------OBSERVERS----------------------------------------//

    static node_pointer treeMaximumNode(node_pointer curr) {
        while (curr && curr->right) curr = curr->right;
        return (curr);
    }

    static node_pointer treeMinimumNode(node_pointer curr) {
        while (curr && curr->left) curr = curr->left;
        return (curr);
    }

    bool sameKeyExists(const key_type& data, node_pointer m_root) const {
        // if (m_root == NULL) return false;
        // if (m_root->data.first == data)
        //     return true;
        // if (_bst_compare(data, m_root->data.first))
        //     return sameKeyExists(data, m_root->left);
        // else
        //     return sameKeyExists(data, m_root->right);

        //func repeatedly compares the key with the data in curr node and moves left or right depending on
        //comparison result until it finds a matching node or reaches the end of the tree. This can avoid
        //overhead of recursive function calls and reduce call stack depth because in previous implementation i used tail recursion
        //meaning last operation is recursive call.
        while (m_root != NULL)
        {
            if (m_root->data.first == data)
                return true;
            else if (_bst_compare(data, m_root->data.first))
                m_root = m_root->left;
            else
                m_root = m_root->right;
        }
        return false;
    }

    node_pointer searchForKey(const key_type& key) const {
        node_pointer tmp = _bst_root;

        while (tmp != NULL && tmp->data.first != key) {
            if (_bst_compare(key, tmp->data.first))
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
        return (tmp);
    }
};
};  

#endif