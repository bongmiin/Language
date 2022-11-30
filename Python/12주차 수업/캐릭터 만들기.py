class 캐릭터생성:
    def __init__(self, job, hp):
        self.job = job
        self.hp = int(hp)

    def 공격(self, enemy):
        enemy.hp = enemy.hp - 10
        print(f"상대 {enemy.job}에게 10 피해를 입혔습니다.")
        print(f"{self.job}: {self.hp}   {enemy.job}: {enemy.hp}")

    def 방어(self):
        self.hp = self.hp -5
        print(self.job, "은(는) 5 피해를 입었습니다.")
        print(f"{self.job} : {self.hp}")
