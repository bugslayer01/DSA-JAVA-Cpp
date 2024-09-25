#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at the start of the list
    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end of the list
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Search for a value in the list
    bool search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->val == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Insert after a specific value
    void insertAfterValue(int afterVal, int newVal)
    {
        Node *temp = head;
        while (temp != nullptr && temp->val != afterVal)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            Node *newNode = new Node(newVal);
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Value " << afterVal << " not found in the list." << endl;
        }
    }

    // Delete at the start of the list
    void deleteAtStart()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at the end of the list
    void deleteAtEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete a specific node by value
    void deleteSpecificNode(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->val == val)
        {
            deleteAtStart();
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr && temp->next->val != val)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Node with value " << val << " not found!" << endl;
            return;
        }

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Display the entire list
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = nullptr;
    }

    // Insert at the start of the list
    void insertAtStart(int val)
    {
        // before inserting at start we need to check wether we have a empty LinkedList
        Node *newNode = new Node(val);

        // if(head=nullptr){
        //     head=newNode;
        // }

        // Node* temp = head;
        // while(temp->next!=nullptr)
        // temp=temp->next;

        // temp->next=newNode;
        // newNode->next=head;
        // head=newNode;
        // If the list is empty, point newNode to itself and set it as head
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head; // Circular link
        }
        else
        {
            Node *temp = head;
            // Traverse to the last node (the node whose next points to head)
            while (temp->next != head)
            {
                temp = temp->next;
            }

            // Insert the new node at the start
            temp->next = newNode; 
            newNode->next = head; 
            head = newNode;      
        }
    }


// Insert at the end of the list
void insertAtEnd(int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head; // Circular link
    }
    else
    {
        Node *temp = head;
        // Traverse to the last node (the node whose next points to head)
        while (temp->next != head)
        {
            temp = temp->next;
        }


        // Insert the new node at the end
        temp->next = newNode;  // Last node points to new node
        newNode->next = head;  // New node points to head to maintain circular structure

        
    }
}
    // Search for a value in the list
    bool search(int val){
}

// Insert after a specific value
void insertAfterValue(int afterVal, int newVal)
{
}

// Delete at the start of the list
void deleteAtStart()
{
}

// Delete at the end of the list
void deleteAtEnd()
{
}

// Delete a specific node by value
void deleteSpecificNode(int val)
{
}

// Display the entire list
void display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
};

int main()
{
    LinkedList list;
    LinkedList l;
    list.insertAtStart(10);
    list.insertAtStart(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Initial List: ";
    list.display();

    list.insertAfterValue(30, 35);
    cout << "After inserting 35 after 30: ";
    list.display();

    list.deleteAtStart();
    cout << "After deleting at start: ";
    list.display();

    list.deleteAtEnd();
    cout << "After deleting at end: ";
    list.display();

    list.deleteSpecificNode(35);
    cout << "After deleting node with value 35: ";
    list.display();

    if (list.search(30))
    {
        cout << "30 found in the list." << endl;
    }
    else
    {
        cout << "30 not found in the list." << endl;
    }

    return 0;
}
