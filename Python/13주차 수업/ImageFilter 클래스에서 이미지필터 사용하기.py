from PIL import Image  
from PIL import ImageFilter

img = Image.open('baby.jpg')

img1 = img.filter(ImageFilter.BLUR)
img2 = img.filter(ImageFilter.EMBOSS)
img3 = img.filter(ImageFilter.CONTOUR)

img1.show()
img2.show()
img3.show()