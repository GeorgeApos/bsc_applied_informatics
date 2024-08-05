

public class Customer {

	private String eponimo;
	private String onoma;
	private String afm;
	private String doy;
	private String objName;

	public Customer(String objName, String eponimo, String onoma, String afm, String doy) {
		this.eponimo = eponimo;
		this.onoma = onoma;
		this.afm = afm;
		this.doy = doy;
		this.objName = objName;
	}
	
	public void printData() {
		System.out.println("Customer " + this.getObjName() + " has been created.");
	}

	public String getEponimo() {
		return eponimo;
	}

	public void setEponimo(String eponimo) {
		this.eponimo = eponimo;
	}

	public String getOnoma() {
		return onoma;
	}

	public void setOnoma(String onoma) {
		this.onoma = onoma;
	}

	public String getAfm() {
		return afm;
	}

	public void setAfm(String afm) {
		this.afm = afm;
	}

	public String getDoy() {
		return doy;
	}

	public void setDoy(String doy) {
		this.doy = doy;
	}

	public String getObjName() {
		return objName;
	}

	public void setObjName(String objName) {
		this.objName = objName;
	}
	
	
	
}
