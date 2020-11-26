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
	
	//게임 종료 조건 1. 빈 칸 있어도 return fnd =0이면 종료, fnd=1이면 입력 받음 2. 빈 칸이 없을 때 3. 
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

	cnt_stones()	;
	
}
//배치할 칸 좌표 입력 및 값 저장  
int put_stone(int turn)
{
	int R_here, C_here	;
	
	//현재 turn의 player의 알 색깔 안내 
	switch(turn)
	{
		case 1:
			printf(" Your stone is WHITE(1).\n\n")	;
			break	;
		case 2:
			printf(" Your stone is BLACK(2).\n\n")	;
			break	;
	}
	
	//배치할 칸 좌표 입력에 대한 안내 
	printf(" Where would you like to put it?\n")	;
	printf("\tRow    : ")		;
	scanf("%d", &R_here)	; 
	printf("\tColumn : ")	;
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
}
//현재 배치된 알의 개수 counting 및 상태 출력  
void cnt_stones(void)
{
	//counting 초기화  
	int W_cnt =0	;
	int B_cnt =0	;
	int X_cnt =0	;
	int i, j	;
	
	//배열 요소를 하나씩 값 비교하여 조건과 맞는 변수가 1 증가  
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
//기존 배치된 알을 뒤집을 수 있는 칸 탐색
int find_section(int turn)
{
	//turn =2
	//1인 칸을 모두 골라냄
	//임의의 칸 gameboard[i][j]
	//이를 둘러싼 8방향 섹션에 2가 있는가?
	//있다면 1을 점대칭한 맞은편이 비어있는가?
	
	int fnd		;	//0(배치 가능한 칸이 없다.)혹은 1(배치 가능한 칸이 있다.) 값만 가짐. 
	int res		=0;	//8방향에 대해 배치 가능한 칸이 알아본 후, 하나 이상의 fnd =1이 존재하는 지 알아보기 위한 임의의 변수  
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
	
	
	 
	//1번 조건 : gameboard[i-1][j-1] != turn
	//2번 조건 : for문 돌리는 동안 turn을 만나지 않고 0이 나와야 함. != turn은 for문으로 계속 탐색  
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
