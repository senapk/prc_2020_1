class Carro:
    nPessoas = 0
    maxPessoas = 2
    gasolina = 0
    def embarcar(self):
        if self.nPessoas < self.maxPessoas:
            self.nPessoas += 1
            print("embarcou")
            return True
        print("ta lotado")
        return False

carro = Carro()
carro2 = carro #
carro.embarcar()
carro.embarcar()
carro.embarcar()
print(carro.nPessoas)
print(carro2.nPessoas)