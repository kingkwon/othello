#include <stdio.h>
#include <stdlib.h>
#define	N	6						//칸 수는 macro로 선언  

//------------------------------------
//전역변수 
//------------------------------------ 
int gameboard[N][N]	;

//------------------------------------
//사용자 정의 함수 
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
	
		//현재 turn의 player의 알 색깔 안내 
		switch(turn)
		{
			case 1:
				printf(" Your stone is WHITE(1).\n")	;
				break	;
			case 2:
				printf(" Your stone is BLACK(2).\n")	;
				break	;
		}
	
		//현재 배치된 알의 개수  
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

	
		//배치할 칸 좌표 입력에 대한 안내 
		printf(" Where would you like to put it?\n")	;
		printf(" Row : ")		;
		scanf("%d", &R_here)	; 
		printf(" Column : ")	;
		scanf("%d", &C_here)	; 
	
		//선택한 칸에 player의 알 정보(1 or 2) 저장  
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
	//현재 배치된 알의 개수_final
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

//게임 초기화  
void init_othello(void)
{
	int i, j	;
	
	//우선 모든 배열을 "빈 칸 =0"으로 만듦. 
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			gameboard[i][j] =0	;
		}
		
	} 
	
	//초기 상태의 배열 : 흰 돌 =1, 검은 돌 =2 
	gameboard[N/2 -1][N/2 -1] 	= 1		; 
	gameboard[N/2 -1][N/2]		= 2		;
	gameboard[N/2][N/2 -1] 		= 2		;
	gameboard[N/2][N/2]			= 1		;
		
}
//배치 상태 출력  
void print_othello(void)
{
	int i, j	;
	
	//배열의 Column  
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
	
	//각 배열요소의 값   
	for(i=0; i<N; i++)
	{
		//배열의 Row 
		printf("R[%d]\t", i+1)	;
		for(j=0; j<N; j++)
		{
			printf("%d\t", gameboard[i][j])	;
		}
		printf("\n\n\n")			;
	}
	
}
