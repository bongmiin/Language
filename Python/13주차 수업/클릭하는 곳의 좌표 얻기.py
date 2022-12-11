import tkinter  

root = tkinter.Tk()
cv = tkinter.Canvas(root, width=500, height=300)
def click(e):
    print("클릭 위치 :", e.x, e.y)
    
cv.bind("<Button-1>", click)
cv.pack()

root.mainloop()