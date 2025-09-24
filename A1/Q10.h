#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *previous;
};

class Q10CircularLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    Q10CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~Q10CircularLinkedList()
    {
        if (head == nullptr)
            return;
        Node *current = head;
        Node *nextNode;
        do
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->previous = tail;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
            tail->next = head;
            head->previous = tail;
        }
    }

    void insertAtBeginning(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        if (head == nullptr && tail == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->previous = tail;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
            head->previous = tail;
            tail->next = head;
        }
    }

    void display()
    {
        if (head == nullptr && tail == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
        }
        Node *current = head;
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};