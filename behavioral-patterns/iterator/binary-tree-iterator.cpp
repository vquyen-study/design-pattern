#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryNode;

template <typename T>
struct Node
{
    T value{};
    shared_ptr<Node<T>> left{nullptr}, right{nullptr}, parent{nullptr};
    Node(const T& _value) : value{_value} 
    {

    }

    friend ostream& operator<<(ostream& _os, const Node& obj)
    {
        _os << obj.value;
        return _os;
    }
};

template <typename T>
struct BinaryNode
{
    // vector<shared_ptr<Node<T>>> root;
    shared_ptr<Node<T>> root{nullptr};
    size_t size{0};
    // BinaryNode() : root{make_shared<Node<T>>()} {}
     
    void add_node(shared_ptr<Node<T>> _node)
    {
        // Todo
        vector<uint8_t> reverse_path;
        size_t temp_size = size;
        if (size == 0)
        {
            root = _node;
            size++;
            // cout << "adding " << root << " " << *root << ", parent " << root->parent << endl;
            return ;
        }

        do
        {
            temp_size = ((temp_size % 2) ? ((temp_size - 1) / 2) : ((temp_size - 2) / 2));
            reverse_path.push_back(temp_size % 2);
        } while (temp_size);
        
        shared_ptr<Node<T>> temp_node = root;           
        for (auto itor = reverse_path.rbegin(); itor != (reverse_path.rend() - 1); ++itor)
        {                                                // ^^^^^^^^^^^^^^^^^^^^^ We do minus 1 because last is parent of current node.
            if (*(itor + 1) % 2) 
                temp_node = temp_node->left;
            else
                temp_node = temp_node->right;            
        }

        if (size % 2)
            temp_node->left = _node;
        else
            temp_node->right = _node;
        
        _node->parent = temp_node;
        size++;

        return;
    }


    template <typename U>
    class IteratorBinaryTreePreOder
    {
        shared_ptr<Node<U>> curr_node;
    public:
        IteratorBinaryTreePreOder(shared_ptr<Node<U>> _bn) : curr_node{_bn} {}

        bool operator!=(const IteratorBinaryTreePreOder<U>& obj)
        {
            return curr_node != obj.curr_node;
        }

        Node<U>& operator*()
        {
            return *curr_node;
        }

        shared_ptr<Node<U>> operator++()
        {
            shared_ptr<Node<U>> prev_node;
            if (curr_node)
            {
                if (curr_node->left)
                {
                    curr_node = curr_node->left;
                    return curr_node;
                }

                while (curr_node)
                {
                    prev_node = curr_node;
                    curr_node = curr_node->parent;
                    if (curr_node)
                        if (curr_node->right != nullptr && prev_node != curr_node->right)
                        {
                            curr_node = curr_node->right;
                            return curr_node;
                        }
                }
            }

            return curr_node;
        }

        friend ostream& operator<<(ostream& _os, const IteratorBinaryTreePreOder& obj)
        {
            _os << obj.curr_node << ", " << *(obj.curr_node) << endl;
            return _os;
        }
    };

    typedef IteratorBinaryTreePreOder<T> iterator;

    iterator begin()
    {
        return iterator{root};
    }

    iterator end()
    {
        return iterator{nullptr};
    }

    void print_tree(shared_ptr<Node<T>> _root)
    {
        if (_root != nullptr)
        {
            cout << *_root << endl;
            print_tree(_root->left);
            print_tree(_root->right);
        }
    }

    void print_preoder_tree(void)
    {
        shared_ptr<Node<T>> _root = root;
        print_tree(_root);
    }
};

template <typename T, typename ... Args>
auto create_node(Args... args) -> shared_ptr<T>
{
    return shared_ptr<T>(new T(forward<Args>(args)...));
}

int main(int argc, char **argv)
{
    BinaryNode<string> binary_tree;

    binary_tree.add_node(create_node<Node<string>>("Q0"));
    binary_tree.add_node(create_node<Node<string>>("Q1"));
    binary_tree.add_node(create_node<Node<string>>("Q2"));
    binary_tree.add_node(create_node<Node<string>>("Q3"));
    binary_tree.add_node(create_node<Node<string>>("Q4"));
    binary_tree.add_node(create_node<Node<string>>("Q5"));
    binary_tree.add_node(create_node<Node<string>>("Q6"));
    binary_tree.add_node(create_node<Node<string>>("Q7"));
    binary_tree.add_node(create_node<Node<string>>("Q8"));
    binary_tree.add_node(create_node<Node<string>>("Q9"));
    binary_tree.add_node(create_node<Node<string>>("Q10"));
    binary_tree.add_node(create_node<Node<string>>("Q11"));
    binary_tree.add_node(create_node<Node<string>>("Q12"));

    cout << "Print pre-oder binary tree..." << endl;
    binary_tree.print_preoder_tree();

    cout << "\nUsing iterator pattern to traverse binary tree..." << endl;
    for (auto it = binary_tree.begin(); it != binary_tree.end(); ++it)
        cout << *it << endl;

    return 0;
}