from tkinter import *
from tkinter import messagebox
def buttonclick():
    ent_text = et.get()
    print(ent_text)
    lb['fg'] = ent_text
    et.delete

    messagebox.showinfo("제목", ent_text+" (으)로 색을 변경합니다.")
    #showinfo() showwarning() showerror() 종류의 메시지박스가 있습니다.

window = Tk()
window.title("버튼 이벤트 만들기") #창의 제목
lb = Label(window, text="아래 빈칸에 텍스트를 입력하세요", width=40)
et = Entry(window, width=40)
bt = Button(window, text="확인", width=40, bg="pink", command=buttonclick)
lb.pack()
et.pack()
bt.pack()
window.mainloop()