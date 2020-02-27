package s02e01_intro;

public class Carro{
    int nPessoas = 0;
    int maxPessoas = 2;
    float gasolina = 0;

    boolean embarcar(){
        if (this.nPessoas < this.maxPessoas){
            this.nPessoas += 1;
            System.out.println("embarcou");
            return true;
        }
        System.out.println("ta lotado");
        return false;
    }

    public static void main(String[] args) {
        Carro carro = new Carro();
        Carro carro2 = carro;
        carro.embarcar();
        carro.embarcar();
        carro.embarcar();
        System.out.println(carro.nPessoas);
        System.out.println(carro2.nPessoas);
    }

}


