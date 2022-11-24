from tkinter import *
from tkinter import messagebox
root = Tk()
root.title("메모장")

def newfile():
    txt.delete(1.0, END)
def openfile():
    try:
        f = open('memojang.txt', 'r')
        a = f.read()
        txt.delete(1.0, END)
        txt.insert(1.0, a)
        f.close()
    except:
        messagebox.showerror("오류", "먼저 저장하세요")

def savefile():
    f = open('memojang.txt', 'w')
    f.write(txt.get(1.0, END))
    f.close()
def quit():
    root.quit()
    root.destroy()

txt = Text(root)
txt.pack()

menubar = Menu(root)
file = Menu(menubar, tearoff=0)
file.add_command(label="새 파일", command=newfile)
file.add_command(label="열기", command=openfile)
file.add_command(label="저장", command=savefile)
file.add_separator()
file.add_command(label="종료", command=quit)
menubar.add_cascade(label="파일", menu=file)
root.config(menu=menubar)
root.mainloop()
