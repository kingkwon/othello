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
void init_othello(void)		;
void print_othello(void)	;
int put_stone(int turn)		;
void cnt_stones(void)		;
 
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
	
	//���� ���� ���� 1. �� ĭ �־ return fnd =0�̸� ����, fnd=1�̸� �Է� ���� 2. �� ĭ�� ���� �� 3. 
	while(isGameEnd() == 0)
	{
		
	} 
	
	 
	for(k=0; k<2; k++)
	{
		turn =k+1	;
	
		put_stone(turn)		;
		print_othello()		; 

	}	
	
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

	cnt_stones()	;
	
}
//��ġ�� ĭ ��ǥ �Է� �� �� ����  
int put_stone(int turn)
{
	int R_here, C_here	;
	
	//���� turn�� player�� �� ���� �ȳ� 
	switch(turn)
	{
		case 1:
			printf(" Your stone is WHITE(1).\n\n")	;
			break	;
		case 2:
			printf(" Your stone is BLACK(2).\n\n")	;
			break	;
	}
	
	//��ġ�� ĭ ��ǥ �Է¿� ���� �ȳ� 
	printf(" Where would you like to put it?\n")	;
	printf("\tRow    : ")		;
	scanf("%d", &R_here)	; 
	printf("\tColumn : ")	;
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
}
//���� ��ġ�� ���� ���� counting �� ���� ���  
void cnt_stones(void)
{
	//counting �ʱ�ȭ  
	int W_cnt =0	;
	int B_cnt =0	;
	int X_cnt =0	;
	int i, j	;
	
	//�迭 ��Ҹ� �ϳ��� �� ���Ͽ� ���ǰ� �´� ������ 1 ����  
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
	printf(" WHITE(1) : %d, BLACK(2) : %d, Empty Section(0) : %d\n\n", W_cnt, B_cnt, X_cnt)	;
}
//���� ��ġ�� ���� ������ �� �ִ� ĭ Ž��
int find_section(int turn)
{
	//turn =2
	//1�� ĭ�� ��� ���
	//������ ĭ gameboard[i][j]
	//�̸� �ѷ��� 8���� ���ǿ� 2�� �ִ°�?
	//�ִٸ� 1�� ����Ī�� �������� ����ִ°�?
	
	int fnd		;	//0(��ġ ������ ĭ�� ����.)Ȥ�� 1(��ġ ������ ĭ�� �ִ�.) ���� ����. 
	int res		=0;	//8���⿡ ���� ��ġ ������ ĭ�� �˾ƺ� ��, �ϳ� �̻��� fnd =1�� �����ϴ� �� �˾ƺ��� ���� ������ ����  
	int fnd1, fnd2, fnd3, fnd4, fnd5, fnd6, fnd7, fnd8	;
	
	switch(turn)
	{
		case(1) :
			for(i=0; i<N; i++)
			{
				for(j=0; j<N; j++)
				{
					if(gameboard[i][j] == 2)
					{
						fnd1 =one_direction(i, j)	;	//gameboard[i-1][j-1]
						fnd2 =two_direction(i, j)	;	//gameboard[i-1][j]
						fnd3 =thr_direction(i, j)	;	//gameboard[i-1][j+1]
						fnd4 =fou_direction(i, j)	;	//gameboard[i][j-1]
						fnd5 =fiv_direction(i, j)	;	//gameboard[i][j+1]
						fnd6 =six_direction(i, j)	;	//gameboard[i+1][j-1]
						fnd7 =sev_direction(i, j)	;	//gameboard[i+1][j]
						fnd8 =eig_direction(i, j)	;	//gameboard[i+1][j+1]
				
						res = fnd1 + fnd2 + fnd3 + fnd4 + fnd5 + fnd6 + fnd7 + fnd8 ;
						
						if(res >= 1)
						{
							res++	;
						}
						else
						{
							res = res	;
						}
					}
					else
					{
						gameboard[i][j] = gameboard[i][j]	;
					}	
				}
			}
			if(res > 8)
			{
				fnd = 1;
			}
			else
			{
				fnd = 0;
			}
			break	;
			
		case(2) :
			for(i=0; i<N; i++)
			{
				for(j=0; j<N; j++)
				{
					if(gameboard[i][j] == 1)
					{
						fnd1 =one_direction(i, j)	;	//gameboard[i-1][j-1]
						fnd2 =two_direction(i, j)	;	//gameboard[i-1][j]
						fnd3 =thr_direction(i, j)	;	//gameboard[i-1][j+1]
						fnd4 =fou_direction(i, j)	;	//gameboard[i][j-1]
						fnd5 =fiv_direction(i, j)	;	//gameboard[i][j+1]
						fnd6 =six_direction(i, j)	;	//gameboard[i+1][j-1]
						fnd7 =sev_direction(i, j)	;	//gameboard[i+1][j]
						fnd8 =eig_direction(i, j)	;	//gameboard[i+1][j+1]
				
						res = fnd1 + fnd2 + fnd3 + fnd4 + fnd5 + fnd6 + fnd7 + fnd8 ;
						
						if(res >= 1)
						{
							res++	;
						}
						else
						{
							res = res	;
						}
					}
					else
					{
						gameboard[i][j] = gameboard[i][j]	;
					}	
				}
			}
			if(res > 8)
			{
				fnd = 1;
			}
			else
			{
				fnd = 0;
			}	
			break	;		
	}
	
	
	return fnd	;
} 
int one_direction(int i, int j, int turn)
{
	int k	;
	int fnd	;
	
/*	while(fnd =0)
	{
		for(k=2; i-k > 0 && j-k > 0; k++)
		{
			if(gameboard[i-k][j-k] == turn || gameboard[i-k][j-k] == 0)
			{
				fnd =0	;
			}
			else
			{
				fnd =1	;
			}	
		}
	}
*/	
	
	
	 
	//1�� ���� : gameboard[i-1][j-1] != turn
	//2�� ���� : for�� ������ ���� turn�� ������ �ʰ� 0�� ���;� ��. != turn�� for������ ��� Ž��  
	if((gameboard[i-1][j-1] != turn) && (gameboard[i-1][j-1] != 0))
	{
		fnd =1	;
	}
	else
	{
		fnd =0;
	}
	
	
	return fnd	; 
}
