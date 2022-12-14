## 함수

```python
def 함수명():
	함수에 들어갈 작업들
```
- 함수명은 일반적으로 함수의 동작을 설명한다. ex) GetSum, DrawSquare 등 이해하기 쉽게 정한다.

### 매개 변수
```python
def function(매개변수):
	print(x * x * x)
```
- 인자값 2개 - 매개변수 2개

### return을 이용하여 변수에 함수 결과 값 입력하기

- return은 함수가 처리한 내용을 다시 함수 바깥으로 꺼내줌

### 인자의 기본값 지정하기
```python
def sayhello(name, place="파이썬월드"):
```
### 가변인자 사용

- 애스터리스크(\*)를 이용하여 하나의 매개변수에 여러 인자를 받을 수 있다.

> 가변인자를 사용하여 내용 모두 출력하기

### docstring
```python
help(함수명)
함수명.__doc__
```
- 함수에 대한 설명은 함수 시작후 따옴표 세 개로 이루어진 주석문을 달면 만들 수 있다. 이는 함수에 대한 문서화된(doc)설명을 출력한다.

### 람다함수
- map()의 사용법
```python
a = list(map(lambda x: x*10,(3,5,7,9)))
```

## 내장함수와 외장함수

- 내장함수: 일반적으로 많이 사용하는 함수, 파이썬에서 바로 사용
- 외장함수: 파있너에서 함께 제공되는 함수, import 후 사용
```python
help(함수명) # 내장함수 사용법에 대한 도움말 함수
help(__builtins__) # 내장함수 종류 보기 
```
----------------

|역할|함수명|예제|
|-----|----|-----|
|절댓값|abs(x)|abs(-15)|
|연산 결과값 리턴|eval('a')|
|몫과 나머지 리턴|divmod(x, y)|a = divmod(9,2)|
|10진수->16진수|hex()|hex(15)|
|자료형->문자형|str(x)|str(12345)|
|객체의 메서드, 객체의 함수|dir(a)|dir([1,2,3]), dir(5)|
|a의 자식클래스 여부 판단|isinstance(a, class)|isinstance(son,dad)|
|반복가능한 객체의 자료 전체 요소 참 확인|all(a)|a = [1,2,3] all(a)|
|리스트, 튜플 형태 변환|list(a), tuple(a)|
|**최대값과 최솟값**|max(a), min(a)|
|정렬|sorted(a)|
|**문자열, 리스트의 길이 구하기**|len()|
|객체 요소 간의 짝 구성|zip(a,...)|a = zip(['영희','철수'],[여,남])|
|자료 순서와 값 반환|enumerate(a)|
|조건에 알맞은 객체 반환|filter(def, a)|
|객체의 함수 실행 결과 반환|map(def, a)|
|**반올림**|round(a,0)|round(3.13, 0)|

> 텍스트 계산기

> 객체 정보 출력

### 표준 라이브러리
- 외장함수, 내장 라이브러리, 표준 라이브러리
	- import 하여 사용
---------------

|역할|함수명|예시|
|----|------|---------|
|**파이썬 객체를 그대로 저장**|pickle( )|pickle.dump(a,f) <br> pickle.load(f)|
|**난수 발생**|random( )|random.radint(1, 100) <br> 1부터 100까지의 랜덤값 반환|
|웹브라우저와 인터넷에 관련된 라이브러리|webbrowser|
|웹의 데이터 이용하기|urllib|
|**날짜이용하기**|datetime|datetime.date.today( )|
|isoformat()<br> YYYY-MM-DD|ctime()<br> 날짜와 시간 출력|strftime()<br>표시 형태대로 출력|

### random 라이브러리

|함수명|역할|
|------|------|
|.uniform( )|uniform은 범위가 클 때 사용|
|.randrange( )|range와 용법이 같음|
|choice(a), sample(a, x)|정해진 리스트 안에서 무작위로 고르기|

### time 라이브러리

- timedelta
	- 날짜 또는 시간끼리의 차이를 구하기 위해 사용하는 모듈
	