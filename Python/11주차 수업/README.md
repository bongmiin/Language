### Tkinter 라이브러리

- 그래픽 기반(GUI)의 프로그램을 만들기 위한 도구
```python
from tkinter import *
rook = Tk()
root.mainloop()
```

### Tkinter 구성요소 이름 알기

|명칭|설명|
|----|-----|
|창 | (Root 또는 window)|
|위젯|구성요소|
|메뉴|
|레이블|
|라디오버튼|
|프레임|
|체크박스|
|버튼|
|엔트리|
|리스트 박스|

----------------

- 사용빈도가 높은 구성요소
	- Button
	- Entry
	- Lable
	- Menubutton
	- Menu
	- Message
	- Scale
	- Scrollbar
	- Text
	- Spinbox
	- tkMessageBox
	
### 레이블, 엔트리, 버튼 위젯 옵션 알아보기

```python
a = Lable(Master, Option, ...)
b = Entry(Master, Option, ...)
c = Button(Master, Option, ...)
```
--------------------
- bg : 배경색
- bd : 테두리 굵기
- font : 글씨체
- fg : 글씨의 색
- text : 위젯에 들어갈 내용
- height : 위젯의 세로 크기
- width : 위젯의 가로 크기
- highlightcolor : 위젯이 선택되었을 때 나타날 색
- cursor : 위젯에 마우스를 올릴 때 나타나는 커서 모양

> 레이블, 엔트리, 버튼 위젯 옵션 추가하기

> 함수를 이용하여 버튼으로 동작 만들기

- .get()
- .delete()
- .insert()
- .destroy

> messagebox 만들기

> 아이디와 패스워드 입력 요구 창 만들기

> 위젯을 격자로 위치시키기 Grid Manager

|(0,0)|(row=0,column=1)|
|------|-------|
|(1,0)|(1,1)|
|(2,0)|(2,1)|

### 이벤트에 다양한 기능 싣기 - 바인딩 기법
- bind() 메서드 이용, bind(이벤트명, 핸들러)

- 이벤트 명
	- <Button-1>
	- <Button-2>
	- <Button-3>
	- <B1-Motion>
	- <Double-Button-2>
	- <ButtonRelease-3>
	- <Key>
	- <Up>
	- <Return>
	- <Home>
	- <Leave>

- 핸들러
	- num : 마우스 이벤트 번호
	- x, y : 마우스 좌표
	- x_root, y_root : 마우스 절대좌표
	- char : 키보드 이벤트 발생 문자
	- key : 이벤트 발생 위젯
	- keycode : 키보드 이벤트 키 코드
	
> tkinter로 메모장 만들기

> GUI 계산기 만들기
	