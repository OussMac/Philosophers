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

static void print_philo(t_philo philo)
{
    printf("👴 Philo ID: %d\n", philo.ph_id);
    printf("🧵 Thread ID: %lu\n", philo.th_id);
    printf("🍲 Meals Eaten: %d\n", philo.meals_eaten);
    printf("🥣 Last Meal: %ld\n", philo.last_meal);
    // printf("🥄 Right Fork: %d\n", philo.right_fork->fork_id);
    // printf("🥄 Left Fork: %d\n", philo.left_fork->fork_id);
    printf("  =======================  \n");
}

static void print_philos(t_table *table)
{
    int i;

    i = 0;
    printf(BLU);
    while(i < table->philo_number)
    {
        print_philo(table->philos[i]);
        i++;
    }
    printf(RST);
}

void    print_scene(t_table *table)
{
    print_table(table);
    print_philos(table);
}