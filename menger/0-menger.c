#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
* menger - draws a 2D Menger Sponge
* @level: level of the Menger Sponge to draw
*/
void menger(int level)
{
	int i, j, size, x, y, flag;
	char c;

	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size;)
		{
			c = '#';
			x = i;
			y = j++;
			flag = 0;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					c = ' ';
					if (flag)
						break;
					flag = 1;
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
