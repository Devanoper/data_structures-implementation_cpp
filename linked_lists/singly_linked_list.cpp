#include <iostream>
using namespace std;

template <typename T>
class singlylinkedlist
{
public:
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

    node* head;
    //constructor
    singlylinkedlist() : head(NULL) {}

    //destructor
    ~singlylinkedlist()
    {
        node* current = head;
        while (current != nullptr)
        {
            node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Public methods

    //check if node exists using key value
    node* nodeExists(int k) const
    {
        node* temp = nullptr;
        node* ptr = head;
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

    //append node at end of list
    void appendNode(node* n)
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
                cout << "Node appended \n";
            }
            else
            {
                node* ptr = head;
                while (ptr->next != nullptr)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended \n";
            }
        }
    }

    //prepend node to beginning of the list
    void prependNode(node* n)
    {
        if (nodeExists(n->key) != nullptr)
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
    void insertNodeAfter(int key, node* n)
    {
        node* ptr = nodeExists(key);
        if (nodeExists(n->key) != nullptr)
        {
            cout << "Node already exists with key value " << n->key << '\n';
        }
        else if (ptr == nullptr)
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
        if (head == nullptr)
        {
            cout << "Singly linked list already empty, can't delete \n";
        }
        else if (nodeExists(key) == nullptr)
        {
            cout << "Key not found \n";
        }
        else
        {
            if (head->key == key)
            {
                node* temp = head;
                head = head->next;
                delete temp;
                cout << "Node unlinked with key value " << key << '\n';
            }
            else
            {
                node* prevPtr = head;
                node* currentPtr = head->next;
                while (currentPtr != nullptr)
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
        node* ptr = nodeExists(key);
        if (ptr == nullptr)
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
    void printList() const
    {
        node* start = head;
        if (start == nullptr)
        {
            cout << "No nodes in the singly linked list\n";
        }
        else
        {
            while (start != nullptr)
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

    s.appendNode(new singlylinkedlist<int>::node(1, 10));
    s.appendNode(new singlylinkedlist<int>::node(2, 20));
    s.appendNode(new singlylinkedlist<int>::node(3, 30));

    cout << "List after appending nodes:\n";
    s.printList();

    s.prependNode(new singlylinkedlist<int>::node(0, 5));
    cout << "List after prepending a node:\n";
    s.printList();

    s.insertNodeAfter(1, new singlylinkedlist<int>::node(1, 15));
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
