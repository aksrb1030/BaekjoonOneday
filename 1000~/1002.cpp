// 1002번 문제
// 조규현과 백승환은 터렛에 근무하는 직원이다. 하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.
// 이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
// 조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.
// 한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.

// 출력
// 각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.
/*
입력
3
0 0 13 40 0 37
0 0 3 0 7 4
1 1 1 1 1 5

결과
2
1
0
*/


#include <iostream>
#include <math.h>

using namespace std;

typedef struct Circle
{
	double xpos;
	double ypos;
	double radius;
}Circle;


double getDistance(double x1, double y1, double x2, double y2);
double getNodalpoint(Circle circle1, Circle circle2);

int main()
{
	int num = 0;
	int *circleArr;

	Circle circle1, circle2;

	cin >> num;
	circleArr = (int*)malloc(sizeof(int)*num);

	for (int i = 0; i < num; i++)
	{
		cin >> circle1.xpos >> circle1.ypos >> circle1.radius >> circle2.xpos >> circle2.ypos >> circle2.radius;
		getDistance(circle1.xpos, circle1.ypos, circle2.xpos, circle2.ypos);
		circleArr[i] = getNodalpoint(circle1, circle2);
	}
	for (int i = 0; i < num; i++)
	{
		cout << circleArr[i] << endl;
	}

	free(circleArr);
	return 0;
}

double getDistance(double x1, double y1, double x2, double y2)
{
	double dis = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return dis;
}

double getNodalpoint(Circle circle1, Circle circle2)
{
	int nodalPoint = 0;
	double dis = getDistance(circle1.xpos, circle1.ypos, circle2.xpos, circle2.ypos);
	//  교점이 무한개 or 교점이 1개
	if (abs(circle1.radius - circle2.radius) == dis)
	{
		nodalPoint = 1;
		if (circle1.radius == circle2.radius)
		{
			nodalPoint = -1;
		}
	}
	//  교점이 0개 
	else if (abs(circle1.radius - circle2.radius) > dis)
	{
		nodalPoint = 0;
	}
	//  교점이 0개 
	else if (abs(circle1.radius + circle2.radius) < dis)
	{
		nodalPoint = 0;
	}
	//  교점이 1개
	else if (abs(circle1.radius + circle2.radius) == dis)
	{
		nodalPoint = 1;
	}
	//  교점이 2개
	else if (abs(circle1.radius - circle2.radius) < dis && abs(circle1.radius + circle2.radius) > dis)
	{
		nodalPoint = 2;
	}
	return nodalPoint;
}