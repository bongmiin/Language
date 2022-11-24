from tkinter import *

def buttonclick():
    ent_text = et.get() # et.get() -> 엔트리에 있는 값을 읽음
    print(ent_text)
    lb['fg'] = ent_text  # fg -> 폰트색
    et.delete

window = Tk()
window.title("버튼 이벤트 만들기") # 창의 제목

lb = Label(window, text="아래 빈칸에 텍스트를 입력하세요", width=40)
et = Entry(window, width=40)
bt = Button(window, text="확인", width=40, bg="pink", command=buttonclick)
lb.pack()
et.pack()
bt.pack()

window.mainloop()