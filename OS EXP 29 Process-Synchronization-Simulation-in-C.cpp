#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3; // buffer size
int x = 0;     // item counter

void wait(int *s) { (*s)--; }
void signal(int *s) { (*s)++; }

void producer() {
    wait(&mutex);
    wait(&empty);
    x++;
    printf("Producer produces item %d\n", x);
    signal(&full);
    signal(&mutex);
}

void consumer() {
    wait(&mutex);
    wait(&full);
    printf("Consumer consumes item %d\n", x);
    x--;
    signal(&empty);
    signal(&mutex);
}

int main() {
    int n;
    printf("\n--- Producer Consumer Problem Simulation ---\n");
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:
                if ((mutex =
