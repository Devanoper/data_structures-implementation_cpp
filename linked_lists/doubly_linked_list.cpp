#include <iostream>
using namespace std;

class doublylinkedlist
{
public:
    class node
    {
    public:
        int data;
        int key;
        node *next;
        node *prev;

        // constructors
        node() : data(0), key(0), next(NULL), prev(NULL) {}
        node(int key, int data) : key(key), data(data), next(NULL), prev(NULL) {}
    };
    node *head;

    // constructors
    doublylinkedlist() : head(NULL) {}
    doublylinkedlist(node *head) : head(head) {}

    // methods

    // check if node exists using key value

    node *nodeExists(int k) const
    {
        node *temp = nullptr;
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->key == k)
            {
                temp = ptr;
                break; // Exit loop once node is found
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // append node at end of list
    void appendNode(node *n)
    {
        if (nodeExists(n->key))
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else
        {
            if (head == nullptr)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                node *ptr = head;
                while (ptr->next)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node appended" << endl;
            }
        }
    }

    // prepend node at start of list
    void prependNode(node *n)
    {
        if (nodeExists(n->key))
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else
        {
            if (head == nullptr)
            {
                head = n;
                cout << "Node prepended as head node" << endl;
            }
            else
            {
                head->prev = n;
                n->next = head;
                head = n;
                cout << "Node prepended" << endl;
            }
        }
    }

    // insert node after a particular node in the list
    void insertNodeAfter(int k, node *n)
    {
        node *ptr = nodeExists(k);
        if (ptr == nullptr)
        {
            cout << "Key not found" << endl;
        }
        else
        {
            if (nodeExists(n->key))
            {
                cout << "Node already exists with key value " << n->key << '\n';
            }
            else
            {
                node *nextNode = ptr->next;
                if (nextNode == nullptr)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                else
                {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }

    // delete node by key
    void deleteNodeByKey(int k)
    {
        node *ptr = nodeExists(k);
        if (ptr == nullptr)
        {
            cout << "Key not found" << endl;
        }
        else
        {
            if (head == ptr)
            {
                head = ptr->next;
                if (head != nullptr)
                    head->prev = nullptr;
                cout << "Node deleted (head node)" << endl;
            }
            else
            {
                node *nextNode = ptr->next;
                node *prevNode = ptr->prev;
                if (nextNode == nullptr)
                {
                    prevNode->next = nullptr;
                    cout << "Node deleted (last node)" << endl;
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node deleted" << endl;
                }
            }
            delete ptr;
        }
    }

    // destructor
    ~doublylinkedlist()
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            node *temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
        head = nullptr; // Ensure head is nullptr after all nodes are deleted
    }

    // update node by key
    void updateNodeByKey(int k, int d)
    {
        node *ptr = nodeExists(k);
        if (ptr == nullptr)
        {
            cout << "Key not found" << endl;
        }
        else
        {
            ptr->data = d;
            cout << "Node updated" << endl;
        }
    }

    // print list
    void printList() const
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *ptr = head;
            while (ptr != nullptr)
            {
                cout << ptr->key << " : " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    doublylinkedlist dll;

    // Creating nodes
    doublylinkedlist::node *n1 = new doublylinkedlist::node(1, 10);
    doublylinkedlist::node *n2 = new doublylinkedlist::node(2, 20);
    doublylinkedlist::node *n3 = new doublylinkedlist::node(3, 30);
    doublylinkedlist::node *n4 = new doublylinkedlist::node(4, 40);

    // Append nodes to the doubly linked list
    dll.appendNode(n1);
    dll.appendNode(n2);
    dll.appendNode(n3);

    // Print list after appending nodes
    cout << "List after appending nodes:" << endl;
    dll.printList();
    cout << endl;

    // Prepend a node to the doubly linked list
    doublylinkedlist::node *n0 = new doublylinkedlist::node(0, 5);
    dll.prependNode(n0);

    // Print list after prepending a node
    cout << "List after prepending a node:" << endl;
    dll.printList();
    cout << endl;

    // Insert a node after a specific key
    doublylinkedlist::node *n1_5 = new doublylinkedlist::node(1, 15);
    dll.insertNodeAfter(1, n1_5);

    // Print list after inserting a node after key 1
    cout << "List after inserting a node after key 1:" << endl;
    dll.printList();
    cout << endl;

    // Update a node by key
    dll.updateNodeByKey(3, 35);

    // Print list after updating node with key 3
    cout << "List after updating node with key 3:" << endl;
    dll.printList();
    cout << endl;

    // Delete nodes by key
    dll.deleteNodeByKey(2);

    // Print list after deleting node with key 2
    cout << "List after deleting node with key 2:" << endl;
    dll.printList();
    cout << endl;

    dll.deleteNodeByKey(0);

    // Print list after deleting node with key 0
    cout << "List after deleting node with key 0:" << endl;
    dll.printList();
    cout << endl;

    // Attempting to delete a non-existent key
    dll.deleteNodeByKey(5);

    // Print list after attempting to delete a non-existent key
    cout << "List after attempting to delete a non-existent key:" << endl;
    dll.printList();
    cout << endl;

    // Clean up allocated memory
    delete n0;
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n1_5;

    return 0;
}
