/*
一次性排序，优先级相同时，按照剩余时间排序，剩余时间相同时，按照进程号排序
测试数据：0 2 3
         1 3 4
         2 4 5
         3 5 2
         4 4 1
预期结果：3 4 2 1 0
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
    unsigned int clock = 0, i = 0; 
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
        // Judge whether all processes have been executed
        bool flag = true;
        for (i=0; i<num; i++)
        {
            if (pcb[i]->required_time != pcb[i]->elapsed_time)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        // Run the first process until finished
        while (q->next->pcb->required_time <= q->next->pcb->elapsed_time)
        {
            q->next->pcb->run();
            clock++;
        }
        cout << "Process " << q->next->pcb->id << " is finished." << endl;
        q->pop();
        q->sort();
        // Print the queue
        cout << "The queue after " << clock << "s is: " << endl;
        queue *p = q->next;
        while (p != NULL)
        {
            cout << "PID: " << p->pcb->id << " Priority: " << p->pcb->priority << " Remaining time: " << p->pcb->required_time - p->pcb->elapsed_time << endl;
            p = p->next;
        }
        cout << "----------------------------------------" << endl;
    }
    return 0;
}