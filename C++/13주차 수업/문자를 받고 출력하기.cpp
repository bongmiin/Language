#include<iostream>
using namespace std;

void get1() {
	cout << "cin.get()로 <Enter> 키까지 입력 받고 출력합니다>>";
	int ch; //EOF와 비교를 위해 int로 선언
	while((ch = cin.get()) != EOF) { // 문자 읽기. EOF는 -1
		cout.put(ch);
		if (ch == '\n')
			break;
	}
}

void get2() {
	cout << "cin.get(char&)로 <Enter> 키까지 입력 받고 출력합니다>>";
	char ch; 
	while (true) { // 문자 읽기
		cin.get(ch);
		if(cin.eof()) break;
			cout.put(ch);
		if (ch == '\n')
			break;
	}
}
int main()
{
	get1(); 
	get2(); 
}