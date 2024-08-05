
public class Order {

	private Customer customer;
	private String pro1;
	private String pro2;
	private String pro3;
	private int pos1;
	private int pos2;
	private int pos3;

	
	public Order(Customer customer, String pro1, int pos1, String pro2, int pos2, String pro3, int pos3) {
		this.customer = customer;
		this.pro1 = pro1;
		this.pro2 = pro2;
		this.pro3 = pro3;
		this.pos1 = pos1;
		this.pos2 = pos2;
		this.pos3 = pos3;
	}

	public void printData() {
		System.out.println("Order " + this.getClass().getName() + " has been created.");
	}
	

	public void execute(int orderID, Product jam1, Product jam2, Product jam3, Product jam4) {
		
		if(orderID == 1) {
			jam1.setPosotita(jam1.getPosotita() - this.pos1);
			jam3.setPosotita(jam3.getPosotita() - this.pos2);
			System.out.println("Order executed. Fraoula: " + jam1.getPosotita() + " Portokali: " + jam3.getPosotita() + "\n");
		}else if(orderID == 2) {
			jam4.setPosotita(jam4.getPosotita() - this.pos1);
			jam3.setPosotita(jam3.getPosotita() - this.pos2);
			System.out.println("Order executed. Mantarini: " + jam4.getPosotita() + " Portokali: " + jam3.getPosotita() + "\n" );
		}else if(orderID == 3) {
			jam2.setPosotita(jam2.getPosotita() - this.pos1);
			jam3.setPosotita(jam3.getPosotita() - this.pos2);
			jam1.setPosotita(jam1.getPosotita() - this.pos3);
			System.out.println("Order executed. Kerasi: " + jam2.getPosotita() + " Portokali: " + jam3.getPosotita() + " Fraoula: " + jam1.getPosotita() + "\n");
		}else if(orderID == 4) {
			jam4.setPosotita(jam4.getPosotita() - this.pos1);
			System.out.println("Order executed. Mantarini: " + jam4.getPosotita() + "\n" );
		}
		
	}
}
