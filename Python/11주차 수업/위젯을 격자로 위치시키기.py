from tkinter import *
r = Tk()
r.title("ID와 PW 입력창")
lb1 = Label(r, text=" 아이디 ")
lb2 = Label(r, text="비밀번호")
ent1 = Entry(r)
ent2 = Entry(r)
btn = Button(r, text="확인") #위젯 생성 완료

lb1.grid(row=0, column=0) #배치 시작
ent1.grid(row=0, column=1)
lb2.grid(row=1, column=0)
ent2.grid(row=1, column=1)
btn.grid(row=2, column=1)
r.mainloop()
