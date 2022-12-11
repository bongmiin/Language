#include<iostream>
using namespace std;


int main()
{
	//"HI"를 출력하고 다음 줄로 넘어간다
	cout.put('H');
	cout.put('i');
	cout.put(33); // 33은 ! 문자
	cout.put('\n');

	// C++를 출력한다
	cout.put('C').put('+').put('+').put(' ');

	char str[] = "I love programming";
	cout.write(str, 6); // str 배열의 6개 문자 I love를 스트림에 출력
}