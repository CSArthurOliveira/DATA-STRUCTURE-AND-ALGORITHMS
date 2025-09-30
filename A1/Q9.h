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

    bool isEmpty()
    {
        return size == 0 && head == nullptr && tail == nullptr;
    }

    bool insertAtEnd(int value)
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
                std::cout << "\n\nValor ja existe na lista!\n\n"
                          << std::endl;
                delete newNode;
                return false;
            }
            else
            {
                tail->next = newNode;
                newNode->previous = tail;
                tail = newNode;
            }
        }
        size++;
        return true;
    }

    bool insertAtBeggining(int value)
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
                std::cout << "\n\nValor ja existe na lista!\n\n"
                          << std::endl;
                delete newNode;
                return false;
            }
            else
            {
                head->previous = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        size++;
        return true;
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

    void Menu()
    {
        int oprt;
        int toInsert;
        do
        {
            system("cls");
            std::cout << "INFORME A OPERACAO: \n1 - INSERIR NO INICIO\n2 - INSERIR NO FIM\n3 - MOSTRAR\n4 - ENCERRAR O PROGRAMA\n\nOPERACAO: ";
            std::cin >> oprt;

            switch (oprt)
            {
            case 1:
                system("cls");
                std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
                std::cin >> toInsert;
                if (insertAtBeggining(toInsert))
                {
                    std::cout << "\n\nValor inserido com sucesso!\n\n"
                              << std::endl;
                }
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
                std::cin >> toInsert;
                if (insertAtBeggining(toInsert))
                {
                    std::cout << "\n\nValor inserido com sucesso!\n\n"
                              << std::endl;
                }
                system("pause");
                break;
            case 3:
                system("cls");
                display();
                std::cout << std::endl;
                system("pause");
                break;
            case 4:
                std::cout << "PROGRAMA ENCERRADO!" << std::endl;
                break;
            default:
                std::cout << "OPERACAO INVALIDA!" << std::endl;
                system("pause");
                break;
            }
        } while (oprt != 4);
    }
};