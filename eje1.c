#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int gato[10][10];
	int i,j;
	
	for(i=0;i<10;++i)
	{
		for(j=0;j<10;++j)
		{
			if((i==j) || ((i+j)==9))
			{
				gato[i][j] = 1;
				
				
			}else
			{
				gato[i][j]=0;
				
			}
			printf("%d",gato[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	return 0;
}
