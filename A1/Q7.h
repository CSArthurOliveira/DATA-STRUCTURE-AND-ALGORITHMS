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
            std::cout << "Fila vazia!" << std::endl;
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
        }else{
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
                std::cout << "Valor não encontrado!" << std::endl;
            }
            else
            {
                std::cout << "Valor encontrado!" << std::endl;
            }
        }
    }

    int size()
    {
        return queue->queueSize;
    }
};