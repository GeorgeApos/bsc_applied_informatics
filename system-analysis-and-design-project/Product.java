

public class Product {

	private String eidos;
	private String name; 
	private int posotita;

	public Product(String name, String eidos, int posotita) {
		this.eidos = eidos;
		this.setPosotita(posotita);
		this.name = name;
	}
	
	public void printData() {
		System.out.println("Object " + this.getName() + " has been created." );
	}

	public int getPosotita() {
		return posotita;
	}

	public void setPosotita(int posotita) {
		this.posotita = posotita;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getEidos() {
		return eidos;
	}

	public void setEidos(String eidos) {
		this.eidos = eidos;
	}
	
	
}
