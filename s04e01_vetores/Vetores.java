import java.util.Scanner;
import java.util.ArrayList;

public class Vetores {

    static void show(ArrayList<Integer> vet){
        System.out.print("[ ");
        for(int i = 0; i < vet.size(); i++)
            System.out.print("" + vet.get(i) + " ");
        System.out.println("]");
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        ArrayList<Integer> vet = new ArrayList<Integer>();

        while(true){
            String line = scanner.nextLine();
            String[] ui = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else if(ui[0].equals("add")){
                for(int i = 1; i < ui.length; i++)
                    vet.add(Integer.parseInt(ui[i]));
            }else if(ui[0].equals("show")){
                Vetores.show(vet);   
            }else{
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();
    }
}