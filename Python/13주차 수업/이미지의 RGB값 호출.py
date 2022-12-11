from PIL import Image, ImageTk
import tkinter

root = tkinter.Tk()
cv = tkinter.Canvas(root, width=500, height=300)
def click(e):
    print("클릭 위치:", e.x,e.y)
    r, g, b = img.getpixel((e.x,e.y))
    print(f"R:{r} G:{g} b:{b}")
    
cv.bind("<Button-1>", click)
cv.pack()

img = Image.open('baby.jpg')
img_tk = ImageTk.PhotoImage(img)
cv.create_image(250, 250, image=img_tk)

root.mainloop()