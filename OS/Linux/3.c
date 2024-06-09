#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 10  // 缓冲区大小

int buffer[BUFFER_SIZE];
int count = 0;  // 缓冲区中的项目数

sem_t empty;   // 缓冲区空槽信号量
sem_t full;    // 缓冲区满槽信号量
pthread_mutex_t mutex;  // 互斥锁

void* producer(void* arg) {
    while (1) {
        int item = rand() % 100;  // 生成一个项目
        sem_wait(&empty);  // 等待空槽
        pthread_mutex_lock(&mutex);  // 加锁

        // 将项目放入缓冲区
        buffer[count] = item;
        count++;
        printf("生产者生产了项目 %d，当前库存: %d\n", item, count);

        pthread_mutex_unlock(&mutex);  // 解锁
        sem_post(&full);  // 增加满槽信号量

        sleep(1);  // 每秒生产一个项目
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&full);  // 等待满槽
        pthread_mutex_lock(&mutex);  // 加锁

        // 从缓冲区取出项目
        int items_to_consume = rand() % 5 + 1;  // 随机消费1到5个项目
        for (int i = 0; i < items_to_consume && count > 0; ++i) {
            printf("消费者消费了项目 %d\n", buffer[count - 1]);
            count--;
        }
        printf("当前库存: %d\n", count);

        pthread_mutex_unlock(&mutex);  // 解锁
        sem_post(&empty);  // 增加空槽信号量

        sleep(3);  // 每3秒消费一次
    }
}

int main() {
    pthread_t prod_thread, cons_thread;

    // 初始化信号量和互斥锁
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // 创建生产者和消费者线程
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // 等待线程结束
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // 销毁信号量和互斥锁
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
