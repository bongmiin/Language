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
- 객체의 속성과 관련된 부분
- 다른 객체를 변경할 때
- 연산자 재정의
- **추가 필요**

> 캐릭터의 공격과 방어