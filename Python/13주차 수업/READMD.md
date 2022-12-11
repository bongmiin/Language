### Pillow

1. 이미지 사이즈 확인
```python
from PIL import Image  #PIL 안의 Image 클래스 이용
img = Image.open('baby.jpg') # 객체에 이미지 저장
print(img.size)
img.show() 
```

2. img.crop로 잘라내기
```python
xy = (500, 100, 900, 400)
crop_img = img.crop(xy)
crop_img.show() # 잘라낸 이미지 다른 이름으로 저장하기
```

### .paste를 이용하여 이미지 붙여넣기

1. 병합할 이미지 사이즈 알아내기
2. 붙여넣을 곳 좌표 지정하여 붙이기 .paste(병합할 사진, 크기)
3. 이미지 확인하고 저장하기

### 이미지 회전, 리사이즈, 뒤집기

1. 이미지 회전 .rotate(각도)
2. 사이즈 조절 .resize((x, y))
3. 이미지 확인하고 저장하기 .transpose(Image.FLIP_LEFT_RIGHT) TOP BOTTOM LEFT RIGHT

### RGB 

> mode 확인 후 색상값 분리하여 담기

> 분리된 RGB 합치기

> ImageFilter 클래스에서 이미지필터 사용하기

> tkinter와 pillow 함께 사용하기

> 클릭하는 곳의 좌표 얻기

> 이미지의 RGB값 호출

