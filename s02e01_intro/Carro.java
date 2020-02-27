import java.util.Scanner;

public class Carro{
    int nPessoas = 0;
    int maxPessoas = 2;
    float gasolina = 0;
    float maxGasolina = 100;
    float odometro = 0;

    boolean embarcar(){
        if (this.nPessoas < this.maxPessoas){
            this.nPessoas += 1;
            System.out.println("embarcou");
            return true;
        }
        System.out.println("ta lotado");
        return false;
    }

    void abastecer(float gasolina){
        this.gasolina += gasolina;
        if(this.gasolina > this.maxGasolina)
            this.gasolina = this.maxGasolina;
    }

    void dirigir(float distancia){
        if(this.nPessoas == 0){
            System.out.println("Nao tem quem dirija");
            return;
        }
        if(this.gasolina >= distancia){
            this.gasolina -= distancia;
            this.odometro += distancia;
            System.out.println("Dirigindo");
            return;
        }
        System.out.println("nao tem gasolina");
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Carro carro = new Carro();
        System.out.println("Digite embarcar, abastecer _qtd, dirigir qtd");
        while(true){
            String line = scanner.nextLine();
            String ui[] = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else if(ui[0].equals("embarcar")){
                carro.embarcar();
            }else if(ui[0].equals("abastecer")){//qtd
                float combustivel = Float.parseFloat(ui[1]);
                carro.abastecer(combustivel);
            }else if(ui[0].equals("dirigir")){//distancia
                float distancia = Float.parseFloat(ui[1]);
                carro.dirigir(distancia);
            }else {
            	System.out.println("Comando invalido");
            }
        }
        scanner.close();
    }

}


