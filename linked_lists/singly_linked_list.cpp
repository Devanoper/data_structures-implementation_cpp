#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    int key;
    T data;
    node* next;

    //constructors
    node() : key(0), data(0), next(NULL) {}
    node(int key, T data) : key(key), data(data), next(NULL) {}
};

template <typename T>
class singlylinkedlist
{
public:
    node<T>* head;
    //constructors
    singlylinkedlist() : head(NULL) {}
    singlylinkedlist(node<T>* head) : head(head) {}

    //methods

    //check if node exists using key value
    node<T>* nodeExists(int k)
    {
        node<T>* temp = NULL;
        node<T>* ptr = head;
        while (ptr != NULL)
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

    //append node at end of list
    void appendNode(node<T>* n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended \n";
            }
            else
            {
                node<T>* ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended \n";
            }
        }
    }

    //prepend node to beginning of the list
    void prependNode(node<T>* n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended\n";
        }
    }

    //insert a node after a particular node in the list
    void insertNodeAfter(int key, node<T>* n)
    {
        node<T>* ptr = nodeExists(key);
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else if (ptr == NULL)
        {
            cout << "Key not found \n";
        }
        else
        {
            n->next = ptr->next;
            ptr->next = n;
            cout << "Node inserted\n";
        }
    }

    //delete node using key
    void deleteNodeKey(int key)
    {
        if (head == NULL)
        {
            cout << "Singly linked list already empty, can't delete \n";
        }
        else if (nodeExists(key) == NULL)
        {
            cout << "Key not found \n";
        }
        else
        {
            if (head->key == key)
            {
                node<T>* temp = head;
                head = head->next;
                delete temp;
                cout << "Node unlinked with key value " << key << '\n';
            }
            else
            {
                node<T>* prevPtr = head;
                node<T>* currentPtr = head->next;
                while (currentPtr != NULL)
                {
                    if (currentPtr->key == key)
                    {
                        prevPtr->next = currentPtr->next;
                        delete currentPtr;
                        cout << "Node unlinked with key value " << key << '\n';
                        return;
                    }
                    prevPtr = currentPtr;
                    currentPtr = currentPtr->next;
                }
            }
        }
    }

    //update node value
    void updateNode(int key, T data)
    {
        node<T>* ptr = nodeExists(key);
        if (ptr == NULL)
        {
            cout << "Key does not exist \n";
        }
        else
        {
            ptr->data = data;
            cout << "Data updated \n";
        }
    }

    //print entire list
    void printList()
    {
        node<T>* start = head;
        if (start == NULL)
        {
            cout << "No nodes in the singly linked list\n";
        }
        else
        {
            while (start != NULL)
            {
                cout << "(" << start->key << ", " << start->data << ") -> ";
                start = start->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    singlylinkedlist<int> s;

    node<int>* n1 = new node<int>(1, 10);
    node<int>* n2 = new node<int>(2, 20);
    node<int>* n3 = new node<int>(3, 30);
    node<int>* n4 = new node<int>(4, 40);

    s.appendNode(n1);
    s.appendNode(n2);
    s.appendNode(n3);

    cout << "List after appending nodes:\n";
    s.printList();

    s.prependNode(new node<int>(0, 5));
    cout << "List after prepending a node:\n";
    s.printList();

    s.insertNodeAfter(1, new node<int>(1, 15));
    cout << "List after inserting a node after key 1:\n";
    s.printList();

    s.updateNode(3, 35);
    cout << "List after updating node with key 3:\n";
    s.printList();

    s.deleteNodeKey(2);
    cout << "List after deleting node with key 2:\n";
    s.printList();

    s.deleteNodeKey(0);
    cout << "List after deleting node with key 0:\n";
    s.printList();

    s.deleteNodeKey(5); // Trying to delete a non-existent key
    cout << "List after attempting to delete a non-existent key:\n";
    s.printList();

    return 0;
}
