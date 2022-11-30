class block_factory:
    def __init__(self, company, color, shape):
        self. company = company # 초기화
        self.color = color
        self.shape = shape
    def make_pink(self):
        self.color = "PINK"

newblock = block_factory("Gole", "blue", "long") # 객체생성
print("블록 정보 출력")
print(f"제조 회사: {newblock.company}, 블록 컬러: {newblock.color}, 블록 모양: {newblock.shape}")

newblock.make_pink() # make_pink() 메서드 호출
print("블록 정보 출력")
print(f"제조 회사: {newblock.company}, 블록 컬러: {newblock.color}, 블록 모양: {newblock.shape}")

