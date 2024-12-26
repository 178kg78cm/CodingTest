from tkinter import *
window = Tk()
l=Label(window, text="Creating Entry & Label")
l.pack()

l2=Label(window, text="Creating Entry & Label")
l2.pack()


t=Entry(window, width=50) #Entry 생성: 50px 너비의 입력창 생성
t.pack()
window.mainloop() #이벤트 루프를 생성하는 역할