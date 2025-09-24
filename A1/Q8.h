#include <iostream>

struct Node
{
    int info;
    Node *next;
    Node *previous;
};

class Q8DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Q8DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Q8DoubleLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void add(int value, int position)
    {
        Node *newNode = new Node();
        newNode->info = value;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else if (position <= 0)
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else if (position >= size)
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        else
        {
            Node *current = head;
            int currentIndex = 0;
            while (current != nullptr && currentIndex < position)
            {
                current = current->next;
                currentIndex++;
            }
            current->previous->next = newNode;
            newNode->previous = current->previous;
            newNode->next = current;
            current->previous = newNode;
        }
        size++;
    }

    void remove(int value)
    {
        if(head == nullptr && tail == nullptr){
            std::cout << "Lista Vazia!" << std::endl;
        }else{
            Node *selected;
            Node *current = head;
            while (current != nullptr)
            {
                if (current->info == value)
                {
                    selected = current;
                    
                    if (current->previous != nullptr)
                        current->previous->next = current->next;
                    else
                        head = current->next;
    
                    if (current->next != nullptr)
                        current->next->previous = current->previous;
                    else
                        tail = current->previous;
    
                    delete selected;
                    size--;
                }
                current = current->next;
            }
        }
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->info << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void isOnList(int value){
        int position = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if(current->info == value){
                std::cout << "Elemento " << value << " encontrado na posicao: " << position << std::endl;
                break;
            }

            position++;
            current = current->next;
        }
        std::cout << std::endl;
    }
};
