class Conta {
    private float saldo;
    private String id;

    Conta(String id){
        this.id = id;
    }
    public String getId(){
        return id;
    }
    public void setId(String id){
        if(id.contains(" ")){
            System.out.println("Id nao pode ter espaco");
            return;
        }
        this.id = id;
    }
    public float getSaldo(){
        return saldo;
    }
    public void debito(float valor){
        saldo -= valor;
    }
    public void credito(float valor){
        saldo += valor;
    }
}

public class Banco{
    public static void main(String[] args) {
        Conta conta = new Conta();
        conta.id = "123";
        sysout(conta.getSaldo());
        conta.saldo = 50;
    }
}
