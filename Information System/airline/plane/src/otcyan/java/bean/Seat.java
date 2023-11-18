package otcyan.java.bean;

public class Seat {

	 private FlightInfo fInfo ;//航班号  
     private String s_type ;//舱位类型
	 private String s_number ;//每个航班对就舱位的数量
	public Seat(FlightInfo fInfo, String sType, String sNumber, double sPrice) {
		super();
		this.fInfo = fInfo;
		s_type = sType;
		s_number = sNumber;
		s_price = sPrice;
	}
	private double s_price ;//对应舱位的价格
	public FlightInfo getfInfo() {
		return fInfo;
	}
	public void setfInfo(FlightInfo fInfo) {
		this.fInfo = fInfo;
	}
	public String getS_type() {
		return s_type;
	}
	public void setS_type(String sType) {
		s_type = sType;
	}
	public String getS_number() {
		return s_number;
	}
	public void setS_number(String sNumber) {
		s_number = sNumber;
	}
	public double getS_price() {
		return s_price;
	}
	public void setS_price(double sPrice) {
		s_price = sPrice;
	}
	@Override
	public String toString() {
		return "Seat [fInfo=" + fInfo + ", s_number=" + s_number + ", s_price="
				+ s_price + ", s_type=" + s_type + "]";
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((fInfo == null) ? 0 : fInfo.hashCode());
		result = prime * result
				+ ((s_number == null) ? 0 : s_number.hashCode());
		long temp;
		temp = Double.doubleToLongBits(s_price);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		result = prime * result + ((s_type == null) ? 0 : s_type.hashCode());
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Seat other = (Seat) obj;
		if (fInfo == null) {
			if (other.fInfo != null)
				return false;
		} else if (!fInfo.equals(other.fInfo))
			return false;
		if (s_number == null) {
			if (other.s_number != null)
				return false;
		} else if (!s_number.equals(other.s_number))
			return false;
		if (Double.doubleToLongBits(s_price) != Double
				.doubleToLongBits(other.s_price))
			return false;
		if (s_type == null) {
			if (other.s_type != null)
				return false;
		} else if (!s_type.equals(other.s_type))
			return false;
		return true;
	}
	

}
