class Consumidor extends Thread{
	private Cola cola;
	private int n;

	public Consumidor (Cola c,int n){
		cola=c;
		this.n=n;
	}
	
	public void run(){
		String valor;
		for (int i=0;i<5;i++){
			valor=cola.get(); //pone el número
			System.out.println("Consumidor->"+valor);
		}
	}
}