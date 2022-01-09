#include <iostream>

struct Node {
    Node* bottomLeft;
    Node* bottomRight;
    int data;
};

class BinaryTree
{
public:
    static int maxSum;

    BinaryTree()    
    {
        root = nullptr;
    }

    void AddLeaf(int key)
    {
        AddLeafPrivate(key, root);
    }

    void PrintTree()
    {
        PrintTreePrivate(root);
    }

    void FindMaxSum()
    {
        FindMaxSumPrivate(root);
    }

    ~BinaryTree()
    {
        ReleaseBinaryTree(root);        
    }

private:
    Node* root; 

    Node* CreateLeaf(int key)
    {
        Node* node = new Node;
        node->data = key;

        node->bottomLeft = nullptr;
        node->bottomRight = nullptr;

        return node;
    }

    void AddLeafPrivate(int key, Node* ptr)
    {
        if (!root)
        {
            root = CreateLeaf(key);
        }
        else if (key <= ptr->data)
        {
            if (!ptr->bottomLeft)
            {
                ptr->bottomLeft = CreateLeaf(key);
            }
            else
            {
                AddLeafPrivate(key, ptr->bottomLeft);
            }
        }
        else if (key >= ptr->data)
        {
            if (!ptr->bottomRight)
            {
                ptr->bottomRight = CreateLeaf(key);
            }
            else
            {
                AddLeafPrivate(key, ptr->bottomRight);
            }
        }      
    }

    void PrintTreePrivate(Node* ptr)
    {
        if (root)
        {
            if (ptr->bottomLeft)
            {
                PrintTreePrivate(ptr->bottomLeft);
            }
            std::cout << ptr->data << " ";
            if (ptr->bottomRight)
            {
                PrintTreePrivate(ptr->bottomRight);
            }        
        }
        else
        {
            std::cout << "The tree is empty." << std::endl;
        }   
    }

    void FindMaxSumPrivate(Node* ptr)
    {
        if (root)
        {
            if (ptr->bottomLeft)
            {
                FindMaxSumPrivate(ptr->bottomLeft);
            }
            maxSum += ptr->data;
            if (ptr->bottomRight)
            {
                FindMaxSumPrivate(ptr->bottomRight);
            }        
        }
        else
        {
            std::cout << "The tree is empty." << std::endl;
        }   
    }

    void ReleaseBinaryTree(Node* ptr)
    {
        if (ptr != nullptr)
        {
            if (ptr->bottomLeft != nullptr)
            {
                ReleaseBinaryTree(ptr->bottomLeft);
            }

            if (ptr->bottomRight != nullptr)
            {
                ReleaseBinaryTree(ptr->bottomRight);
            }
            std::cout << "Deleting the node containing key : " << ptr->data << std::endl; 
            delete ptr;
        }
    }
};

int BinaryTree::maxSum = 0;

int main()
{
    int TreeKeys[10] = { 1, 8, 4, 2, 6, 9, 8, 5, 9, 3};

    BinaryTree myTree;

    std::cout << "Printing the tree in order\nBefore adding numbers.\n";
    myTree.PrintTree();


    for (size_t i = 0; i < 10; i++)
    {
        myTree.AddLeaf(TreeKeys[i]);
    }

    std::cout << "Printing the tree in order\nAfter adding numbers.\n";
    myTree.PrintTree();

    std::cout << std::endl;

    std::cout << "FINDING MAX SUM\n";
    myTree.FindMaxSum();
    std::cout << "MAX SUM = " << BinaryTree::maxSum << std::endl;

    std::cout << std::endl;
    return 0;
}