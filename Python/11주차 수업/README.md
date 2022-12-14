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

|사용빈도가 높은 구성요소|설명|
|----------|---------------|
|Button|이벤트를 발생시키는 버튼을 만든다|
|Entry|텍스트를 입력할 수 있는 한 줄짜리 칸을 만든다|
|Lable|사용자에게 보일 한 줄짜리 텍스트를 넣는다|
|Menubutton|Root에 Menu를 만든다|
|Menu|메뉴 버튼 아래 각각의 메뉴를 구성한다|
|Message|사용자에게 여러 줄의 텍스트를 보여 준다|
|Scale|슬라이더를 사용한 위젯을 제공한다|
|Scrollbar|여러 리스트를 스크롤바가 있는 박스로 보여 준다|
|Text|여러 줄의 텍스트를 사용자에게 보여 준다|
|Spinbox|화살표로 숫자의 크기를 올리거나 내리는 창을 만든다|
|tkMessageBox|사용자에게 메시지 박스에 메시지를 실어 출력한다|
	
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

- .get(): 담긴 텍스트를 추출한다
- .delete(): 담긴 텍스트를 삭제한다
- .insert(): index 위치에 텍스트를 추가한다
- .destroy(): 해당 창 또는 위젯을 삭제한다

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
	- \<Button-1>
	- \<Button-2>
	- \<Button-3>
	- \<B1-Motion>
	- \<Double-Button-2>
	- \<ButtonRelease-3>
	- \<Key>
	- \<Up>
	- \<Return>
	- \<Home>
	- \<Leave>

- 핸들러
	- num : 마우스 이벤트 번호
	- x, y : 마우스 좌표
	- x_root, y_root : 마우스 절대좌표
	- char : 키보드 이벤트 발생 문자
	- key : 이벤트 발생 위젯
	- keycode : 키보드 이벤트 키 코드
	
> tkinter로 메모장 만들기

> GUI 계산기 만들기
	
