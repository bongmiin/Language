from PIL import Image  

img = Image.open('baby.jpg')
print(img.mode)

r, g, b = img.split()
r.show()
g.show()
b.show()