#include <stdio.h>

#define BLOCKSIZE 20
#define LENGHT 	  70

int main()
{
	int i,j;

	//长度分块处理，每次处理指定长度
	for( i = 0;i < LENGHT/BLOCKSIZE; i++)  //取整
	{
		for(j = 0;j < BLOCKSIZE; j++)
		{	
			printf("%d\n",(i*BLOCKSIZE)+j);
		}
	}

	//剩余数据单独处理
	int remaing = LENGHT%BLOCKSIZE; //取余
	if(remaing > 0)
	{
		for(j = 0; j < remaing;j++)
		{
			printf("2==%d\n",(i * BLOCKSIZE)+j );
		}
	}

	return 0;

}

