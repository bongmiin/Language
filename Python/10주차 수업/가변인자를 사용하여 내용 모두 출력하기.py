def Todaymenu(*menu):
    print("오늘의 메뉴")
    for i in range(len(menu)) : print (menu[i])
    print("Service Charge, VAT 10% will be added")

Todaymenu("만두","만두","만두")