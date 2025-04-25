#include "philo.h"

static void print_table(t_table *table)
{
    printf(GRN);
    printf("  =======================  \n");
    printf("[+] Number Of Philos %d\n", table->philo_number);
    printf("[+] Number Of Meals  %d\n", table->nbr_of_meals);
    printf("  =======================  \n");
    printf("[+] Start Time %ld\n", table->start);
    printf("  =======================  \n");
    printf("[+] Time To Die  %ld\n", table->time_to_die);
    printf("[+] Time To Eat  %ld\n", table->time_to_eat);
    printf("[+] Time To Sleep  %ld\n", table->time_to_sleep);
    printf("  =======================  \n");
    printf(RST);
}


static void print_philos(t_table *table)
{
    int i;

    i = 0;
    while(i < table->philo_number)
    {
        printf(BLU);
        printf("👴 Philo ID: %d\n", table->philos[i].ph_id);
        printf("🧵 Thread ID: %lu\n", table->philos[i].th_id);
        printf("🍲 Meals Eaten: %d\n", table->philos[i].meals_eaten);
        printf("🥣 Last Meal: %ld\n", table->philos[i].last_meal);
        printf(YLW"🥄 Left Fork: %d\n", table->philos[i].left_fork->fork_id);
        printf(MGN"🥄 Right Fork: %d\n"BLU, table->philos[i].right_fork->fork_id);
        printf("  =======================  \n");
        printf(RST);
        i++;
    }
}

void    print_scene(t_table *table)
{
    pthread_mutex_lock(&table->print_lock);
    print_table(table);
    print_philos(table);
    pthread_mutex_unlock(&table->print_lock);

}