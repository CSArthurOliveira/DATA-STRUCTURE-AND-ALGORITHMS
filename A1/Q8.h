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

    void insert(int value, int position)
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

    bool remove(int value)
    {
        if (head == nullptr && tail == nullptr)
        {
            std::cout << "Lista Vazia!" << std::endl;
            return false;
        }
        else
        {
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
                    return true;
                }
                current = current->next;
            }
        }
        return false;
    }

    void display()
    {
        displaying(head, tail);
        std::cout << std::endl;
    }

    void displaying(Node *start, Node *end)
    {
        if (head == nullptr && tail == nullptr)
        {
            std::cout << "\nLista vazia!\n"
                      << std::endl;
            return;
        }
        else if (start == end)
        {
            std::cout << start->info << " ";
            return;
        }
        else
        {
            std::cout << start->info << " ";
            displaying(start->next, end);
        }
    }

    bool isOnList(int value)
    {
        int position = 0;
        Node *current = head;
        while (current != nullptr)
        {
            if (current->info == value)
            {
                std::cout << "\n\nElemento " << value << " encontrado na posicao: " << position << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                return true;
                break;
            }

            position++;
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "\nElemento " << value << " nao encontrado na lista!\n\n"
                  << std::endl;
        return false;
    }

    bool isEmpty()
    {
        return head == nullptr && tail == nullptr;
    }

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

    void Menu()
    {
        int oprt;
        int toInsert, toVerify, toRemove, position;
        do
        {
            system("cls");
            std::cout << "INFORME A OPERACAO: \n1 - INSERIR\n2 - REMOVER\n3 - VERIFICAR\n4 - MOSTRAR\n5 - ENCERRAR O PROGRAMA\n\nOPERACAO: ";
            std::cin >> oprt;

            switch (oprt)
            {
            case 1:
                system("cls");
                std::cout << "INFORME O VALOR QUE DESEJA INSERIR: ";
                std::cin >> toInsert;
                std::cout << "INFORME A POSICAO QUE DESEJA INSERIR: ";
                std::cin >> position;
                insert(toInsert, position);
                std::cout << "\n\nValor inserido com sucesso!\n\n"
                          << std::endl;
                system("pause");
                break;
            case 2:
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
            case 3:
                system("cls");
                if (!isEmpty())
                {
                    std::cout << "INFORME O VALOR QUE DESEJA VERIFICAR: ";
                    std::cin >> toVerify;
                    isOnList(toVerify);
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
