
import java.util.Scanner;

class Pessoa {
    String nome;
    int idade;
    public Pessoa(String nome, int idade){ //nao eh metodo, eh invocado automaticaticamente na criacao
        this.nome = nome;
        this.idade = idade;
    }
}

public class Motoca {
	Pessoa pessoa;
	int potencia;
	int tempo;

	public Motoca(int potencia){
		this.potencia = potencia;
	}
	
	void embarcar(Pessoa pessoa) {
		if(this.pessoa == null)
			this.pessoa = pessoa;
		else
			System.out.println("Ja tem gente na motoca");
	}

	void pagar(int value){
		this.tempo += value;
	}
	
	void desembarcar() {
		if(this.pessoa != null)
			this.pessoa = null;
		else
			System.out.println("Nao tem ninguem na moto");
	}

	void dirigir(int tempo){

		if(this.pessoa == null){
			System.out.println("Nao tem ninguem na moto");
			return;
		}
		if(this.tempo < tempo){
			System.out.println("compre mais minutos");
			return;
		}
		if(this.pessoa.idade < 2)
			System.out.println("Muito pequeno pra andar de moto");
		else if(this.pessoa.idade > 10)
			System.out.println("Muito grande pra andar de moto");
		else{
			this.tempo -= tempo;
			System.out.println(this.pessoa.nome + " "  + this.fazerBarulho());
		}
	}

	String fazerBarulho(){
		String out = "";
		for(int i = 0; i < this.potencia; i++)
			out += "run ";
		return out;
	}


	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Motoca motoca  = new Motoca(2);
		while(true) {
			String line = scanner.nextLine();
			String ui[] = line.split(" ");
			if(ui[0].equals("end")) {
				break;
			}else if(ui[0].equals("init")) { //potenia
				int potencia = Integer.parseInt(ui[1]);
				motoca = new Motoca(potencia);
			}else if(ui[0].equals("embarcar")) { //nome  idade
				int idade = Integer.parseInt(ui[2]);
				motoca.embarcar(new Pessoa(ui[1], idade));
			}else if(ui[0].equals("desembarcar")) {
				motoca.desembarcar();
			}else if(ui[0].equals("dirigir")) {
				motoca.dirigir(Integer.parseInt(ui[1]));
			}else if(ui[0].equals("pagar")) {//valor
				motoca.pagar(Integer.parseInt(ui[1]));
			}else {
				System.out.println("Comando invalido");
			}
		}
		scanner.close();
	}

}






