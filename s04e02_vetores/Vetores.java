import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

//collections - containers
//ArrayList - vector
//LinkedList - list
//TreeMap - map
//TreeSet - set

public class Vetores{
    public static void main(String[] args) {
        ArrayList<Integer> vet = new ArrayList<>();
        int[] vetor = new int[5];
        String banana = "banana";
        banana.equals("banana");

        vet.add(4);
        vet.add(6);
        vet.add(9);
        vet.addAll(Arrays.asList(1, 2, 3, 4, 6));
        vet.remove(Integer.valueOf(3));

        for(int i = 0; i < vet.size(); i++)
            System.out.println(vet.get(i));

        for(Integer value : vet)
            System.out.println(value);

        Iterator<Integer> it = vet.iterator();
        while(it.hasNext())
            System.out.println(it.next());
        /*
        vet.size()
        vetor.length

        vet.get(5)
        vetor[5]

        vet.set(5, 8);
        vetor[5] = 8;
         */
    }
}