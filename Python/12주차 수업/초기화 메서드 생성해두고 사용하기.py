class block_factory:
    def __init__(self, company, color, shape):
        self. company = company
        self.color = color
        self.shape = shape

newblock = block_factory("Gole", "blue", "long")

print("불록 정보 출력")
print("제조 회사 :", newblock.company)
print(f"블록 컬러 : {newblock.color}")
print("블록 모양 :", newblock.shape)