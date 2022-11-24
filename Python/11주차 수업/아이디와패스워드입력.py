from tkinter import *
from tkinter import messagebox
root = Tk()
root.title("로그인 하세요.")
root.resizable(False, False)

IDPW = {"봉민":"aj1357", }

def check_IDPW():
    get_id = user_id.get()
    if get_id in IDPW:
        if IDPW[get_id]==user_pw.get():
            messagebox.showinfo("로그인 성공", get_id+"님 안녕하세요.")
            root.destroy()
        else:
            messagebox.showerror("로그인 실패", "패스워드를 확인해주세요.")
    else:
        messagebox.showerror("로그인 실패", "아이디가 존재하지 않습니다.")

label1 = Label(root, text="ID를 입력하세요")
user_id = Entry(root, width=30)
label2 = Label(root, text="PASSWORD를 입력하세요")
user_pw = Entry(root, width=30, show="●")
button = Button(root, text="로그인", width=20, command=check_IDPW)
label1.pack()
user_id.pack()
label2.pack()
user_pw.pack()
button.pack()
root.mainloop()
