#include <iostream>

struct Node
{
    int info;
    Node *previous;
};

struct StackTop
{
    Node *top;
    int stackSize;
};

class Q6Stack
{
private:
    StackTop *stack;

    void clear()
    {
        while (stack->top != nullptr)
        {
            Node *current = stack->top;
            stack->top = stack->top->previous;
            delete current;
        }
        stack->stackSize = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->info = value;
        newNode->previous = stack->top;
        stack->top = newNode;
        stack->stackSize++;
    }

    void pop()
    {
        if (stack->top == nullptr)
        {
            std::cout << "\nPilha vazia!" << std::endl;
        }
        Node *selected = stack->top;
        stack->top = stack->top->previous;
        delete selected;
        stack->stackSize--;
    }

    void display()
    {
        if (stack->top == nullptr)
        {
            std::cout << "\nPilha vazia!" << std::endl;
        }
        Node *current = stack->top;
        while (current != nullptr)
        {
            std::cout << current->info << std::endl;
            current = current->previous;
        }
        std::cout << std::endl;
    }

    void isOnStack(int value)
    {
        bool found = false;
        if (stack->top == nullptr)
            std::cout << "\nPilha vazia!" << std::endl;
        else
        {
            Node *current = stack->top;
            while (current != nullptr)
            {
                if (current->info == value)
                {
                    found = true;
                    break;
                }
                current = current->previous;
            }
        }

        if (found)
            std::cout << "\n\nValor encontrado!\n\n"
                      << std::endl;
        else
            std::cout << "\n\nValor nao encontrado!\n\n"
                      << std::endl;
    }

    int stackSize()
    {
        return stack->stackSize;
    }

    bool isEmpty()
    {
        return stack->top == nullptr;
    }

public:
    Q6Stack()
    {
        stack = new StackTop();
        stack->top = nullptr;
        stack->stackSize = 0;
    }

    ~Q6Stack()
    {
        clear();
        delete stack;
    }

    void Menu()
    {
        int oprt;
        int toInsert, toVerify;
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
                push(toInsert);
                std::cout << "\nValor inserido com sucesso!\n " << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << std::endl;
                if (!isEmpty())
                {
                    pop();
                    std::cout << "\nValor removido com sucesso!\n\n"
                              << std::endl;
                }
                else
                {
                    std::cout << "Pilha vazia!\n\n"
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
                    isOnStack(toVerify);
                }
                else
                {
                    std::cout << "\nPilha vazia!\n\n"
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