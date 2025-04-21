#include "philo.h"
#include <stdatomic.h>

int balance = 0;

void *routine(void *arg)
{
    int i = 0;
    pthread_t t = *(pthread_t *)arg;

    printf("Entered thread %lu\n", t % 10000);
    while (i < 200000)
    {
        balance++;
        i++;
    }
    return (NULL);

}


int main(void)
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, routine, &t1);
    pthread_create(&t2, NULL, routine, &t2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("balance ===> %d", balance);
    return(EXIT_SUCCESS);
}