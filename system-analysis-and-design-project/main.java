import java.util.*;

public class main {

	public static void main(String[] args) {
		
		String[] katalogosProiontwn = new String[4];
		Product jam1 = new Product("jam1","fraoula", 600);
		jam1.printData();
		Product jam2 = new Product("jam2","kerasi", 420);
		jam2.printData();
		Product jam3 = new Product("jam3","portokali", 480);
		jam3.printData();
		Product jam4 = new Product("jam4","mantarini", 360);
		jam4.printData();
		katalogosProiontwn[0] = ((Product) jam1).getEidos();
		katalogosProiontwn[1] = ((Product) jam2).getEidos();
		katalogosProiontwn[2] = ((Product) jam3).getEidos();
		katalogosProiontwn[3] = ((Product) jam4).getEidos();
		
		System.out.println("\n");
		
		String[] katalogosPelatwn = new String[2];
		Customer customer1 = new Customer("customer1","Patidou","Olga","046208830","DOY B Peiraia");
		customer1.printData();
		Customer customer2 = new Customer("customer2","Alexiou","Nikolaos","180226310","DOY Ilioupolis");
		customer2.printData();
		katalogosPelatwn[0] = ((Customer) customer1).getObjName();
		katalogosPelatwn[1] = ((Customer) customer2).getObjName();
		
		System.out.println("\n");
		
		Order order1 = new Order(customer1,"fraoula",50,"portokali",14,"0",0);	
		order1.printData();
		order1.execute(1,jam1,jam2,jam3, jam4);
		Order order2 = new Order(customer1,"mantarini",120,"portokali",45,"0",0);
		order2.printData();
		order2.execute(2,jam1,jam2,jam3, jam4);
		Order order3 = new Order(customer2,"kerasi",80,"portokali",35,"fraoula",28);
		order3.printData();
		order3.execute(3,jam1,jam2,jam3, jam4);
		Order order4 = new Order(customer2,"mantarini",60,"0",0,"0",0);
		order4.printData();
		order4.execute(4,jam1,jam2,jam3, jam4);
		
		System.out.println("O katalogos twn proiontwn einai o eksis:");
		for(int i=0; i<4; i++) {
			System.out.println(katalogosProiontwn[i]);
		}
		
	}

}
