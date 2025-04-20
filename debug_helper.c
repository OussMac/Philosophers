#include "philo.h"

void    print_table(t_table *table)
{
    printf(GRN"[+] Number Of Philos %d\n"RST, table->philo_number);
    printf(GRN"[+] Time To Die  %ld\n"RST, table->time_to_die);
    printf(GRN"[+] Time To Eat  %ld\n"RST, table->time_to_eat);
    printf(GRN"[+] Time To Sleep  %ld\n"RST, table->time_to_sleep);
    printf(GRN"[+] Number Of Meals  %d\n"RST, table->nbr_of_meals);
    printf(GRN"  =======================  \n"RST);
    printf(GRN"[+] Start Time %ld\n"RST, table->start);
}
