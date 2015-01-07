public class Cola {
	//atributos
	private String nombre;
	private boolean disponible=false;  // inicialmente vacia

	//metodos
	//sacar
	public synchronized String get(){
		while (disponible==false) { //si esta vacia
			try {
				wait();
			}catch (InterruptedException e){};
		
		}	
		disponible=false;
		notifyAll();
		return nombre; //no hay numero 
	}

	public synchronized void put(String valor){
		while (disponible==true) { //si no esta vacia
			try {
				wait();
			}catch (InterruptedException e){};
		
		}
		nombre=valor;
		disponible=true;
		notifyAll();
		
	}





}
