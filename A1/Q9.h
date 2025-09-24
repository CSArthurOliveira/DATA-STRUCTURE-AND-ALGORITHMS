#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *previous;
};

class Q9DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Q9DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Q9DoubleLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool isEmpty()
    {
        return size == 0 && head == nullptr && tail == nullptr;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->previous = nullptr;
        newNode->next = nullptr;

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            if (exists(value))
            {
                std::cout << "Valor ja existe na lista." << std::endl;
                delete newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
        }
        size++;
    }

    void insertAtBeggining(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->previous = nullptr;
        newNode->next = nullptr;

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            if (exists(value))
            {
                std::cout << "Valor ja existe na lista." << std::endl;
                delete newNode;
            }
            else
            {
                head->previous = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        size++;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    bool exists(int value)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};