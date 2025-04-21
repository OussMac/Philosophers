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
    printf(BLU);
    while(i < table->philo_number)
    {
        printf("👴 Philo ID: %d\n", table->philos[i].ph_id);
        // printf("🧵 Thread ID: %lu\n", table->philos[i].th_id);
        printf("🍲 Meals Eaten: %d\n", table->philos[i].meals_eaten);
        printf("🥣 Last Meal: %ld\n", table->philos[i].last_meal);
        // printf("🥄 Right Fork: %d\n", philo.right_fork->fork_id);
        // printf("🥄 Left Fork: %d\n", philo.left_fork->fork_id);
        printf("  =======================  \n");
        i++;
    }
    printf(RST);
}

void    print_scene(t_table *table)
{
    print_table(table);
    print_philos(table);
}