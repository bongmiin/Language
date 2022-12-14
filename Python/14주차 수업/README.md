### NumPy

- 배열의 Shape, aixs는 0부터 점차 늘어남
	1차원: 리스트
	2차원: 행렬
	3차원: 행렬 + 폭
	
### NumPy 기본값이 정해진 초기화 배열 만들기

- **명령어 잘 기억하기**
-------------
|함수|설명|사용법|
|--------|--------|--------|
|**zeros((s), ..)**|지정(s) 배열 생성 후 값을 모두 0으로 초기화|zeros((3, 4))|
|ones((s), ..)|지정(s) 배열 생성 후 값을 모두 1로 초기화|ones((3,4))|
|full((s), n,..)|지정(s) 배열 생성 후 값을 모두 n으로 초기화|full((3,4))|
|**eye(s, ..)**|지정(s) 배열 생성 후 단위행렬(대각선이 1) 생성|eye(4)|
|like(a, ..)|지정한 배열(a)과 같은 배열 생성 후 초기화|zeros_like(a), ..|

### NumPy 조건을 이용해 다양한 범위로 배열 생성하기

|함수|설명|사용법|
|-------|--------|--------|
|**arange(start, stop, step, ..)**|데이터를 기준으로 step 간격으로 데이터를 생성한 후 배열을 지정|arange(0, 1, 5)|
|**linspace(start, stop, n, ..)**|요소 기준으로 n개만큼 균일하게 배열 생성|linspace(0, 1, 5)|
|logspace(start, stop, n, ..)|
### NumPy의 다양한 난수 생성

|함수|설명|
|------|-------|
|**random.rand(s)**|0부터 1까지 균등하게 무작위 추출하여 s 배열 생성 <br> ex) random.rand(3, 4)|
|random.randint(start, end, (s), ..)|지정된 수 범위에서 정수를 균등하게 추출하여 s배열 생성|
|random.rands(s)|정규분포로 수를 추출하여 s 배열 생성|

### NumPy 값 추출, 변경
- 슬라이싱과 인덱스 사용

### Matplotlib

- 데이터를 시각화할 때 가장 많이 사용하는 라이브러리
	- import matplotlib.pyplot

### Matplotlib 제목과 레이블 설정하기

- 제목, x레이블, y레이블 추가하기
	- .title
	- .xlabel
	- .ylabel
- 범례 추가하기
	- .legend

### Matplotlib 분포도 그리기
- .scatter

### Matplotlib 막대그래프 그리기
- plt.bar: 수직그래프
- plt.barh: 수평그래프

### NumPy의 값 Matplotlib으로 시각화하기
