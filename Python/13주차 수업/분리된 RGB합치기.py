from PIL import Image  

img = Image.open('baby.jpg')
print(img.mode)

r, g, b = img.split()

RGB_img = Image.merge('RGB', (g,r,b))
RGB_img.show()

GRB_img = Image.merge('RGB', (r, b, g))
GRB_img.show()