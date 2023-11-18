package otcyan.java.bean;

public class FlightInfo {

	private String f_number; //航班号
    private String f_type ;   //航班机型
	public FlightInfo(String fNumber, String fType, String fStartTime,
			String fEndTime, FlightAddr fStart, FlightAddr fEnd, String fCompany) {
		super();
		f_number = fNumber;
		f_type = fType;
		f_start_time = fStartTime;
		f_end_time = fEndTime;
		f_start = fStart;
		f_end = fEnd;
		f_company = fCompany;
	}
	private String  f_start_time ;//出发时间
	private String  f_end_time ;  //达到时间
	private FlightAddr  f_start ;   //始发机场  
	private FlightAddr  f_end ;     //目的地
	private String f_company ;
	public String getF_number() {
		return f_number;
	}
	public void setF_number(String fNumber) {
		f_number = fNumber;
	}
	public String getF_type() {
		return f_type;
	}
	public void setF_type(String fType) {
		f_type = fType;
	}
	public String getF_start_time() {
		return f_start_time;
	}
	public void setF_start_time(String fStartTime) {
		f_start_time = fStartTime;
	}
	public String getF_end_time() {
		return f_end_time;
	}
	public void setF_end_time(String fEndTime) {
		f_end_time = fEndTime;
	}
	public FlightAddr getF_start() {
		return f_start;
	}
	public void setF_start(FlightAddr fStart) {
		f_start = fStart;
	}
	public FlightAddr getF_end() {
		return f_end;
	}
	public void setF_end(FlightAddr fEnd) {
		f_end = fEnd;
	}
	public String getF_company() {
		return f_company;
	}
	public void setF_company(String fCompany) {
		f_company = fCompany;
	}
	@Override
	public String toString() {
		return "FlightInfo [f_company=" + f_company + ", f_end=" + f_end
				+ ", f_end_time=" + f_end_time + ", f_number=" + f_number
				+ ", f_start=" + f_start + ", f_start_time=" + f_start_time
				+ ", f_type=" + f_type + "]";
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result
				+ ((f_company == null) ? 0 : f_company.hashCode());
		result = prime * result + ((f_end == null) ? 0 : f_end.hashCode());
		result = prime * result
				+ ((f_end_time == null) ? 0 : f_end_time.hashCode());
		result = prime * result
				+ ((f_number == null) ? 0 : f_number.hashCode());
		result = prime * result + ((f_start == null) ? 0 : f_start.hashCode());
		result = prime * result
				+ ((f_start_time == null) ? 0 : f_start_time.hashCode());
		result = prime * result + ((f_type == null) ? 0 : f_type.hashCode());
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
		FlightInfo other = (FlightInfo) obj;
		if (f_company == null) {
			if (other.f_company != null)
				return false;
		} else if (!f_company.equals(other.f_company))
			return false;
		if (f_end == null) {
			if (other.f_end != null)
				return false;
		} else if (!f_end.equals(other.f_end))
			return false;
		if (f_end_time == null) {
			if (other.f_end_time != null)
				return false;
		} else if (!f_end_time.equals(other.f_end_time))
			return false;
		if (f_number == null) {
			if (other.f_number != null)
				return false;
		} else if (!f_number.equals(other.f_number))
			return false;
		if (f_start == null) {
			if (other.f_start != null)
				return false;
		} else if (!f_start.equals(other.f_start))
			return false;
		if (f_start_time == null) {
			if (other.f_start_time != null)
				return false;
		} else if (!f_start_time.equals(other.f_start_time))
			return false;
		if (f_type == null) {
			if (other.f_type != null)
				return false;
		} else if (!f_type.equals(other.f_type))
			return false;
		return true;
	} 
}
