#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "crossfireOperations.h"

int *nearestPlayer(int counter, int playerPosition[], int pNum, int sNum)
{
	int current, nearest, i = 0;
	int *index = malloc(2 * sizeof(int));
	
	current = counter;
	
	index[0] = sNum;
	index[1] = -1;
	
	nearest = sNum;
	
	for(i = 0; i < pNum; i++)
	{
		if(i == current)
		{
		}
		else if(abs((playerPosition[current] - playerPosition[i]) == nearest))
		{
			index[1] = i;
		}
		else if(abs(playerPosition[current] - playerPosition[i]) < nearest)
		{
			nearest = abs(playerPosition[current] - playerPosition[i]);
			index[0] = i;
		}
	}
	
	if(nearest != abs(playerPosition[current] - playerPosition[index[1]]))
	{
		index[1] = -1;
	}
	
	return index;
} // End nearestPlayer