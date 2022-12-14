## 객체와 클래스

- 클래스
	- 객체
		- 인스턴스
			- method

- 상속

### 객체와 클래스의 개념

```python

class seal: # 클래스 정의
	pass
	
	stamp = seal() # 인스턴스 = 클래스명()
```

### 클래스 선언하기

- 객체를 만드는 틀 클래스 만들기
```python

class block_factory:
	pass

block = block_factory()
```
- 클래스의 기본, 클래스 초기화 메서드 '__init__'
```python
class block_factory:
	def __init__(self): # 괄호 안 self는 클래스 자기 자신을 가리킴
		pass
```		
- 클래스 초기화하기
```python
class block_factory:
	def __init__(self, company):
		self.company = company

newblock = block_factory("Gole")
```

### 객체를 생성하고 정보 출력하기 

> 초기화 메서드 생성해두고 사용하기

> 여러 객체를 생성하기

> 클래스에 메서드(.method) 추가하기

> .method로 계산기 만들기

### 클래스의 메서드를 상속받기

1. 클래스의 메서드를 생성
```python
class Korea:
	def say(self):
		print("I'm from Korea")
```
2. 클래스를 추가 생성
```python
class South_korea(Korea): #Korea 클래스를 상속받음
	pass
```

## 클래스의 다양한 속성들 정의하는 법 - 매직 메서드
- 객체가 시작될 때 또는 종료될 때

|이름|설명|
|-----|------|
|\_\_init__(cls, ..)|인스턴스가 생성되면 처음 하는 동작 지정|
|\_\_new__(self, ..)|인스턴스가 생성되면 처음 실행하는 동작 지정|
|\_\_del__(self)|객체가 소멸할 때 동작 지정|
|\_\_str__(self)|객체의 데이터를 문자열로 만들어서 반환, print(a)로 출력하면 해당 부분 호출|
- 객체의 속성과 관련된 부분

|이름|설명|
|------|------|
|\_\_getattribute__(self, name, ..)|객체의 속성(데이터)를 참조할 때 무조건 호출|
|\_\_getattr__(self, name, ..)|참조 시, 속성이 존재하지 않을 때 호출|
|\_\_setattr_(self, name, ..)|객체의 속성을 변경할 때 호출|

- 다른 객체를 변경할 때

|이름|설명|
|-------|---------|
|\_\_get__(self, instance, owner)|특정 객체의 값을 참조할 때 호출|
|\_\_set__(self, instance, value)|특정 객체의 값을 변경할 때 호출|

- 연산자 재정의

|이름|설명|
|--------|---------|
|\_\_neg__(self)|-a(객체)를 정의한다|
|\_\_gt__(self, other)|x > y 를 정의한다.|
|\_\_add__(self, other)|x + y를 정의한다|
|\_\_int__(self)|int(a)를 정의한다|

> 캐릭터의 공격과 방어
