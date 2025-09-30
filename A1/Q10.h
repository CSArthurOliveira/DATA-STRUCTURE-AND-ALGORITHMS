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

    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
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

    bool remove(int value)
    {
        if (isEmpty())
            return false;

        Node *current = head;
        Node *previous = nullptr;

        do
        {
            if (current->data == value)
            {
                if (current == head && current == tail) // Only one node
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else if (current == head) // Removing head
                {
                    head = head->next;
                    head->previous = tail;
                    tail->next = head;
                }
                else if (current == tail) // Removing tail
                {
                    tail = tail->previous;
                    tail->next = head;
                    head->previous = tail;
                }
                else // Removing middle node
                {
                    previous->next = current->next;
                    current->next->previous = previous;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        return false; // Value not found
    }

    void display()
    {
        if (head == nullptr && tail == nullptr)
        {
            std::cout << "\n\nLista Vazia\n\n"
                      << std::endl;
        }
        Node *current = head;
        do
        {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }

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

    void Menu()
    {
        int oprt;
        int toInsert, toVerify, toRemove;
        do
        {
            system("cls");
            std::cout << "INFORME A OPERACAO: \n1 - INSERIR NO INICIO\n2 - INSERIR NO FIM\n3 - REMOVER\n4 - MOSTRAR\n5 - ENCERRAR O PROGRAMA\n\nOPERACAO: ";
            std::cin >> oprt;

            switch (oprt)
            {
            case 1:
                system("cls");
                std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
                std::cin >> toInsert;
                insertAtBeginning(toInsert);
                std::cout << "\n\nValor inserido com sucesso!\n\n"
                          << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
                std::cin >> toInsert;
                insertAtEnd(toInsert);
                std::cout << "\n\nValor inserido com sucesso!\n\n"
                          << std::endl;
                system("pause");
                break;
            case 3:
                system("cls");
                if (!isEmpty())
                {
                    display();
                    std::cout << std::endl;
                    std::cout << "INFORME O VALOR QUE DESEJA REMOVER: ";
                    std::cin >> toRemove;
                    if (remove(toRemove))
                    {
                        std::cout << "\n\nValor removido com sucesso!\n\n"
                                  << std::endl;
                    }
                    else
                    {
                        std::cout << "\n\nFalha ao remover valor da lista!\n\n"
                                  << std::endl;
                    };
                }
                else
                {
                    std::cout << "\nFila vazia!\n\n"
                              << std::endl;
                }
                system("pause");
                break;
            case 4:
                system("cls");
                display();
                std::cout << std::endl;
                system("pause");
                break;
            case 5:
                std::cout << "PROGRAMA ENCERRADO!" << std::endl;
                break;
            default:
                std::cout << "OPERACAO INVALIDA!" << std::endl;
                system("pause");
                break;
            }
        } while (oprt != 5);
    }
};