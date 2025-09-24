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
            std::cout << "Pilha vazia!" << std::endl;
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
            std::cout << "Pilha vazia!" << std::endl;
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
            std::cout << "Pilha vazia!" << std::endl;
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
            std::cout << "Valor encontrado!" << std::endl;
        else
            std::cout << "Valor nao encontrado!" << std::endl;
    }

    int stackSize()
    {
        return stack->stackSize;
    }
};