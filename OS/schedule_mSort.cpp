/*
优先级相同时，按照剩余时间排序，剩余时间相同时，按照进程号排序
测试数据：0 2 3
         1 3 4
         2 4 5
         3 5 2
         4 4 1
预期结果：3 4 0 1 2
*/
#include <iostream>
#define num 5
using namespace std;
struct PCB
{
    unsigned int id;
    int priority;
    unsigned int elapsed_time;
    unsigned int required_time;

    PCB(unsigned int id, unsigned int priority, unsigned int elapsed_time, unsigned int required_time)
    {
        this->id = id;
        this->priority = priority;
        this->elapsed_time = elapsed_time;
        this->required_time = required_time;
    }

    void run()
    {
        this->elapsed_time++;
        this->priority--;
    }
};
struct queue
{
    PCB *pcb;
    queue *next;
    queue(PCB *pcb, queue *next)
    {
        this->pcb = pcb;
        this->next = next;
    }

    void push(PCB *pcb)
    {
        queue *q = this;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = new queue(pcb, NULL);
    }

    void pop()
    {
        queue *q = this->next;
        this->next = q->next;
        delete q;
    }

    void sort()
    {
        // Sort by highest priority, otherwise by remaining time, otherwise by id
        queue *p = this->next;
        while (p != NULL)
        {
            queue *q = p->next;
            while (q != NULL)
            {
                if (p->pcb->priority < q->pcb->priority)
                {
                    PCB *temp = p->pcb;
                    p->pcb = q->pcb;
                    q->pcb = temp;
                }
                else if (p->pcb->priority == q->pcb->priority)
                {
                    if (p->pcb->required_time > q->pcb->required_time)
                    {
                        PCB *temp = p->pcb;
                        p->pcb = q->pcb;
                        q->pcb = temp;
                    }
                    else if (p->pcb->required_time == q->pcb->required_time)
                    {
                        if (p->pcb->id > q->pcb->id)
                        {
                            PCB *temp = p->pcb;
                            p->pcb = q->pcb;
                            q->pcb = temp;
                        }
                    }
                }
                q = q->next;
            }
            p = p->next;
        }
    }
};

int main()
{
    unsigned int clock = 0, slice = 0, i = 0;
    queue *q = new queue(NULL, NULL);
    PCB *pcb[num];
    for (i=0; i<num; i++)
    {
        cout << "Please input the priority and required time of process " << i << ": ";
        unsigned int priority, required_time;
        cin >> priority >> required_time;
        pcb[i] = new PCB(i, priority, 0, required_time);
        q->push(pcb[i]);
    }
    q->sort();
    // Print the queue
    cout << "The initial queue is: " << endl;
    queue *p = q->next;
    while (p != NULL)
    {
        cout << "PID: " << p->pcb->id << " Priority: " << p->pcb->priority << " Required time: " << p->pcb->required_time << endl;
        p = p->next;
    }
    cout << "----------------------------------------" << endl;
    // Start scheduling
    while (q->next != NULL)
    {
        // Execute one clock per loop
        clock++;
        // If the process is finished, pop it
        if (q->next->pcb->elapsed_time == q->next->pcb->required_time)
        {
            cout << "Process " << q->next->pcb->id << " finished at " << clock << endl;
            q->pop();
        }
        // If the process is not finished, run it
        else
        {
            q->next->pcb->run();
            // If the process is not finished, push it to the end of the queue
            if (q->next->pcb->elapsed_time != q->next->pcb->required_time)
            {
                q->push(q->next->pcb);
                q->pop();
            }
        }
        // Print the queue
        cout << "The queue at " << clock << " is: " << endl;
        p = q->next;
        while (p != NULL)
        {
            cout << "PID: " << p->pcb->id << " Priority: " << p->pcb->priority << " Required time: " << p->pcb->required_time << endl;
            p = p->next;
        }
        cout << "----------------------------------------" << endl;
    }
    return 0;
}