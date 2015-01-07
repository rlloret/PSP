import java.util.Random;


public class Persona extends Thread{

	private Cuenta cuenta;
	private String n;

	public Persona (Cuenta c, String n){
		cuenta=c;
		this.n=n;
	}
	
	
	public void run(){

		
			    Random r = new Random();
			    int pasta = r.nextInt(100)+1;

				cuenta.meter(pasta); //ingresa
				System.out.println(n+" Ingresa: "+pasta);
	 			try {
					sleep(100);
				}catch (InterruptedException e){}
	 			
	 			
	 			
	 			Random r2 = new Random();
			    int pasta2 = r.nextInt(100)+1;
	 			cuenta.sacar(pasta2); //
				System.out.println(n+" Reintegro: "+pasta2);
	 			try {
					sleep(100);
				}catch (InterruptedException e){}
	 			
	 			
	 			int saldo=cuenta.leer();
	 			System.out.println("Saldo: "+saldo);
			
		}
	
	
}
