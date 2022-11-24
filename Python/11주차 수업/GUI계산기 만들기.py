from tkinter import *
root = Tk()
root.title("계산기")

def numinput(event):
    ent.insert(END, event)
def delentry():
    ent.delete(0, END)
def calc():
    con = eval(ent.get())
    ent.delete(0, END)
    ent.insert(0, con)

# 7 8 9 + 4 5 6 - 1 2 3 X C 0 = / 순서대로 배치
ent = Entry(root)
ent.grid(row=0, column=0, columnspan=4)

button7 = Button(root, text="7", command=lambda: numinput(7)).grid(row=1,column=0,ipadx=10)
button8 = Button(root, text="8", command=lambda: numinput(8)).grid(row=1,column=1,ipadx=10)
button9 = Button(root, text="9", command=lambda: numinput(9)).grid(row=1,column=2,ipadx=10)
buttonplus = Button(root, text="+", command=lambda: numinput("+")).grid(row=1,column=3,ipadx=10)
button4 = Button(root, text="4", command=lambda: numinput(4)).grid(row=2,column=0,ipadx=10)
button5 = Button(root, text="5", command=lambda: numinput(5)).grid(row=2,column=1,ipadx=10)
button6 = Button(root, text="6", command=lambda: numinput(6)).grid(row=2,column=2,ipadx=10)
buttonminus = Button(root, text="-", command=lambda: numinput("-")).grid(row=2,column=3,ipadx=10)
button1 = Button(root, text="1", command=lambda: numinput(1)).grid(row=3,column=0,ipadx=10)
button2 = Button(root, text="2", command=lambda: numinput(2)).grid(row=3,column=1,ipadx=10)
button3 = Button(root, text="3", command=lambda: numinput(3)).grid(row=3,column=2,ipadx=10)
buttonmultiply = Button(root, text="X", command=lambda: numinput("*")).grid(row=3,column=3,ipadx=10)
buttonC = Button(root, text="C", command=delentry).grid(row=4,column=0,ipadx=10)
button0 = Button(root, text="0", command=lambda: numinput(0)).grid(row=4,column=1,ipadx=10)
buttoneval = Button(root, text="=", command=calc).grid(row=4,column=2,ipadx=10)
buttondivision = Button(root, text="/", command=lambda: numinput("/")).grid(row=4,column=3,ipadx=10)
ent.delete(0,END)
root.mainloop()

