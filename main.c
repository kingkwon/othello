#include <stdio.h>
#include <stdlib.h>
#define	N	8						//칸 수는 macro로 선언  

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
	init_othello();
	print_othello(); 
	
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
