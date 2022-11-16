def cal():
    a = eval(input("수식 입력 : "))
    a = abs(a)
    a = round(a, 0)
    a = int(a)

    if 90>=a>=65 or 122>=a>=97:
        print(chr(a))

    else:
        print(str(a))

cal()