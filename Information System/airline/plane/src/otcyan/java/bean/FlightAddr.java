package otcyan.java.bean;

public class FlightAddr {

	 private String a_id ;  //序列进行  拼接
	 private String  a_city ;   // 地点
	 public FlightAddr(String aId, String aCity, String aAir) {
		super();
		a_id = aId;
		a_city = aCity;
		a_air = aAir;
	}
	private String  a_air ;  //机场名称
	public String getA_id() {
		return a_id;
	}
	public void setA_id(String aId) {
		a_id = aId;
	}
	public String getA_city() {
		return a_city;
	}
	public void setA_city(String aCity) {
		a_city = aCity;
	}
	public String getA_air() {
		return a_air;
	}
	public void setA_air(String aAir) {
		a_air = aAir;
	}
	@Override
	public String toString() {
		return "FlightAddr [a_air=" + a_air + ", a_city=" + a_city + ", a_id="
				+ a_id + "]";
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((a_air == null) ? 0 : a_air.hashCode());
		result = prime * result + ((a_city == null) ? 0 : a_city.hashCode());
		result = prime * result + ((a_id == null) ? 0 : a_id.hashCode());
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
		FlightAddr other = (FlightAddr) obj;
		if (a_air == null) {
			if (other.a_air != null)
				return false;
		} else if (!a_air.equals(other.a_air))
			return false;
		if (a_city == null) {
			if (other.a_city != null)
				return false;
		} else if (!a_city.equals(other.a_city))
			return false;
		if (a_id == null) {
			if (other.a_id != null)
				return false;
		} else if (!a_id.equals(other.a_id))
			return false;
		return true;
	}
}
