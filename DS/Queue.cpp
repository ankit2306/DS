#ifndef __QUEUE__
#define __QUEUE__

#include "Node.cpp"

template <class T>
class Queue
{
    private:
        Node<T> *front, *rear;
        unsigned int capacity, size; 

    public:
        Queue(unsigned int cap)
        {
            this->front = this->rear = nullptr;
            this->capacity = cap;
            this->size = 0;
        }

        Node<T>* Front()
        {
            return this->front;
        }

        Node<T>* Rear()
        {
            return this->rear;
        }

        unsigned int Size()
        {
            return this->size;
        }

        void Enqueue(T data)
        {
            if(this->size == capacity)
            {
                throw "Invalid Operation: Queue size exceeded capacity.";
            }
            if(this->size == 0)
            {
                this->front = this->rear = Node<T>::CreateNode(data);
                size++;
            } 
            else
            {
                this->rear->next = Node<T>::CreateNode(data);
                this->rear = this->rear->next;
                size++;
            }
        }

        T Dequeue()
        {
            if(this->size == 0)
            {
                throw "Invalid Operation: Dequeue cannot be performed on an empty queue.";
            }
            T data;
            if(this->size == 1)
            {
                data = this->front->data;
                this->front->DeleteNode();
                this->front = this->rear = nullptr;
                size--;
                return data;
            }
            else
            {
                data = this->front->data;
                Node<T>* next = this->front->next;
                this->front->DeleteNode();
                this->front = next;
                size--;
            }
            return data;
        }
};

#endif