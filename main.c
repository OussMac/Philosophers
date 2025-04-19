#include "philo.h"

int main(int argc, char *argv[])
{

	if(parse_input(argc, argv) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}