class block_factory:
    def __init__(self, company, color, shape):
        self. company = company # 초기화
        self.color = color
        self.shape = shape

newblock = block_factory("Gole", "blue", "long") # 객체생성
newblock2 = block_factory("Gole", "black", "short")
newblock3 = block_factory("Oxfold", "red", "big")

print("블록 정보 출력")
print(f"제조 회사 :{newblock.company}, 블록 컬러 :{newblock2.color}, 블록 모양 :{newblock3.shape}")