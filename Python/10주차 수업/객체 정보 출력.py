def simul(a):
    a = list(map(str,a))
    print("자료 요소 참 여부:", all(a))
    print("자료 길이 :", len(a))
    print("자료 중 최대 값 :", max(a))
    print("정렬 시 자료 순서 :", sorted(a))
    print("자료 번호 :", list(enumerate(a)))

simul([1, 3, 5, "A", "B"])