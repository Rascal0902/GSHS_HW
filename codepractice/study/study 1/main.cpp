//소스 -> (컴파일)목적 파일 ->(링크)  실행 파일
//%i : 10진
//%o: 8진
//%x %X 16진
//%e 부동 소수점 형식의 실수로 반환 1.234560e+002   123.456000
//%g %e %f 중 더 짧은 형식 출력
//%p 포인터의 번지수 출력
//%n 출력된 문자 개수를 포인터 변수에 대입한다.
//clrscr 화면을 깔끔히 지운다
//gotoxy(x,y) //출력될 위치 변화 80*25
//wherex() wherey()  현재 위치 나타냄
//puts(문자열) 서식을 다루지 않고 속도도 빠르다
//gets( 변수) str 배열 공백 없이 입력
//putch( c) 문자 하나만 출력
//getch() 문자 하나만 입력(문자 입력 필요 없음)
//delay(n) 1/1000초 단위로 기다림
//exit(0) 강제 로 끝냄
//kbhit() 키가 눌려져 있는지 조사
//int -2147483648 +2147483647
//__int64 64비트 지원 %l64d
//실 수 부호+ 지수부+ 가수부
/*#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void gotoxy(int x,int y)
{

COORD pos={x,y};

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
main()
{
     char ch='B';
     printf("문자일 때 = %c, 정수일 때 = %d\n",ch,ch);
     gotoxy(ch,5);
     putch(ch);
}*/
//\~ 확장열

