struct Node
{
    int info;
    Node *next;
};

struct QueueHead
{
    Node *head;
    int queueSize;
};

class Q7Queue
{
private:
    QueueHead *queue;

    bool isEmpty()
    {
        return queue->head == nullptr;
    }

    void clear()
    {
        while (queue->head != nullptr)
        {
            Node *current = queue->head;
            queue->head = queue->head->next;
            delete current;
        }
        queue->queueSize = 0;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->info = value;
        newNode->next = nullptr;
        if (queue->head == nullptr)
        {
            queue->head = newNode;
        }
        else
        {
            Node *current = queue->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        queue->queueSize++;
    }

    void dequeue()
    {
        if (queue->head == nullptr)
        {
            std::cout << "Fila vazia!" << std::endl;
            return;
        }
        Node *selected = queue->head;
        queue->head = queue->head->next;
        delete selected;
        queue->queueSize--;
    }

    void display()
    {
        if (queue->head == nullptr)
        {
            std::cout << "\nFila vazia!\n" << std::endl;
            return;
        }
        Node *current = queue->head;
        while (current != nullptr)
        {
            std::cout << current->info << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void isOnQueue(int value)
    {
        bool found = false;
        if (queue->head == nullptr)
        {
            std::cout << "Fila vazia!" << std::endl;
        }
        else
        {
            Node *current = queue->head;
            while (current != nullptr)
            {
                if (current->info == value)
                {
                    found = true;
                    break;
                }
                current = current->next;
            }
            if (found == false)
            {
                std::cout << "\n\nValor nao encontrado!\n\n" << std::endl;
            }
            else
            {
                std::cout << "\n\nValor encontrado!\n\n" << std::endl;
            }
        }
    }

    int size()
    {
        return queue->queueSize;
    }

public:
    Q7Queue()
    {
        queue = new QueueHead();
        queue->head = nullptr;
        queue->queueSize = 0;
    }

    ~Q7Queue()
    {
        clear();
        delete queue;
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
                enqueue(toInsert);
                std::cout << "\nValor inserido com sucesso!\n " << std::endl;
                system("pause");
                break;
            case 2:
                system("cls");
                std::cout << std::endl;
                if (!isEmpty())
                {
                    dequeue();
                    std::cout << "\nValor removido com sucesso!\n\n"
                              << std::endl;
                }
                else
                {
                    std::cout << "Fila vazia!\n\n"
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
                    isOnQueue(toVerify);
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