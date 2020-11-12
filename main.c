#include <stdio.h>
#include <stdlib.h>
#define	N	8						//ĭ ���� macro�� ����  

//------------------------------------
//�������� 
//------------------------------------ 
int gameboard[N][N]	;

//------------------------------------
//����� ���� �Լ� 
//------------------------------------
void init_othello(void);
void print_othello(void);
 
//------------------------------------
//MAIN
//------------------------------------
void main(void)
{
	init_othello();
	print_othello(); 
	
	return 0	;
}

//���� �ʱ�ȭ  
void init_othello(void)
{
	int i, j	;
	
	//�켱 ��� �迭�� "�� ĭ =0"���� ����. 
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			gameboard[i][j] =0	;
		}
		
	} 
	
	//�ʱ� ������ �迭 : �� �� =1, ���� �� =2 
	gameboard[N/2 -1][N/2 -1] 	= 1		; 
	gameboard[N/2 -1][N/2]		= 2		;
	gameboard[N/2][N/2 -1] 		= 2		;
	gameboard[N/2][N/2]			= 1		;
		
}
//��ġ ���� ���  
void print_othello(void)
{
	int i, j	;
	
	//�迭�� Column  
	printf("\n")					;
	for(i=0; i<N; i++)
	{
		printf("---------")			;
	}
	printf("\n")					;
	for(i=0; i<N; i++)
	{
		printf("\tC[%d]", i+1)		;
	}
	printf("\n")					;
	for(i=0; i<N; i++)
	{
		printf("---------")			;
	}
	printf("\n")					;
	
	//�� �迭����� ��   
	for(i=0; i<N; i++)
	{
		//�迭�� Row 
		printf("R[%d]\t", i+1)	;
		for(j=0; j<N; j++)
		{
			printf("%d\t", gameboard[i][j])	;
		}
		printf("\n\n\n")			;
	}
	
}
