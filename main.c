#include <stdio.h>
#include <stdlib.h>
#define	N	6						//ĭ ���� macro�� ����  

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
	int C_here, R_here			;
	int turn					;
	int W_cnt, B_cnt, X_cnt		;
	int i, j, k					;
	
	init_othello();
	print_othello(); 
	
	for(k=0; k<2; k++)
	{
		turn =k+1	;
	
		//���� turn�� player�� �� ���� �ȳ� 
		switch(turn)
		{
			case 1:
				printf(" Your stone is WHITE(1).\n")	;
				break	;
			case 2:
				printf(" Your stone is BLACK(2).\n")	;
				break	;
		}
	
		//���� ��ġ�� ���� ����  
		W_cnt =0	;
		B_cnt =0	;
		X_cnt =0	;
		
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
			{
				if(gameboard[i][j] == 1)
				{
					W_cnt++		;
				}
				else if(gameboard[i][j] == 2)
				{
					B_cnt++		;
				}
				else
				{
					X_cnt++		;
				}
			
			}
		}
		printf(" WHITE(1) : %d, BLACK(2) : %d, Empty Section : %d\n", W_cnt, B_cnt, X_cnt)			;

	
		//��ġ�� ĭ ��ǥ �Է¿� ���� �ȳ� 
		printf(" Where would you like to put it?\n")	;
		printf(" Row : ")		;
		scanf("%d", &R_here)	; 
		printf(" Column : ")	;
		scanf("%d", &C_here)	; 
	
		//������ ĭ�� player�� �� ����(1 or 2) ����  
		switch(turn)
		{
			case 1:		//white =1
				gameboard[R_here -1][C_here -1]	=	turn	;
				break	;
			case 2:		//black =2
				gameboard[R_here -1][C_here -1]	=	turn	;
				break	;			
		}
	
		print_othello(); 

	}	
	//���� ��ġ�� ���� ����_final
	W_cnt =0	;
	B_cnt =0	;
	X_cnt =0	;
		
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(gameboard[i][j] == 1)
			{
				W_cnt++		;
			}
			else if(gameboard[i][j] == 2)
			{
				B_cnt++		;
			}
			else
			{
				X_cnt++		;
			}
	
		}
	}
	printf(" WHITE(1) : %d, BLACK(2) : %d, Empty section : %d\n", W_cnt, B_cnt, X_cnt)			;
	
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
