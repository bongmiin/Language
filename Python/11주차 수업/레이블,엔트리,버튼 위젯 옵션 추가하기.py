from tkinter import *
root = Tk()

label = Label(root, text = "Welcome, Please input your name", bg="beige", font="arial")
label.pack()

entry = Entry(root, text="input here", bd=5, cursor="pirate")
entry.pack()

button = Button(root, text="확인", fg="red", cursor= "arrow", height = 10)
button.pack()

root.mainloop()
