package otcyan.java.bean;

public class User {

	private String u_id ;  //用户名 主键
	private String  u_password ;           //密码
	private String  u_name ;  //用户姓名
	private String  u_sex ;//用户姓名
	public User(String uId, String uPassword, String uName, String uSex,
			String uTelephone, String uAddress, String uEmail, String uIdcard,
			String uPower) {
		super();
		u_id = uId;
		u_password = uPassword;
		u_name = uName;
		u_sex = uSex;
		u_telephone = uTelephone;
		u_address = uAddress;
		u_email = uEmail;
		u_idcard = uIdcard;
		u_power = uPower;
	}
	private String  u_telephone ;    //电话
	private String  u_address ;  //用户地址
	private String  u_email ;   //Email 
	private String u_idcard ;  //身份证号
	private String  u_power ;     //用户的权限  1表示机场人员，0表示旅客
	public String getU_id() {
		return u_id;
	}
	public void setU_id(String uId) {
		u_id = uId;
	}
	public String getU_password() {
		return u_password;
	}
	public void setU_password(String uPassword) {
		u_password = uPassword;
	}
	public String getU_name() {
		return u_name;
	}
	public void setU_name(String uName) {
		u_name = uName;
	}
	public String getU_sex() {
		return u_sex;
	}
	public void setU_sex(String uSex) {
		u_sex = uSex;
	}
	public String getU_telephone() {
		return u_telephone;
	}
	public void setU_telephone(String uTelephone) {
		u_telephone = uTelephone;
	}
	public String getU_address() {
		return u_address;
	}
	public void setU_address(String uAddress) {
		u_address = uAddress;
	}
	public String getU_email() {
		return u_email;
	}
	public void setU_email(String uEmail) {
		u_email = uEmail;
	}
	public String getU_idcard() {
		return u_idcard;
	}
	public void setU_idcard(String uIdcard) {
		u_idcard = uIdcard;
	}
	public String getU_power() {
		return u_power;
	}
	public void setU_power(String uPower) {
		u_power = uPower;
	}
	@Override
	public String toString() {
		return "User [u_address=" + u_address + ", u_email=" + u_email
				+ ", u_id=" + u_id + ", u_idcard=" + u_idcard + ", u_name="
				+ u_name + ", u_password=" + u_password + ", u_power="
				+ u_power + ", u_sex=" + u_sex + ", u_telephone=" + u_telephone
				+ "]";
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result
				+ ((u_address == null) ? 0 : u_address.hashCode());
		result = prime * result + ((u_email == null) ? 0 : u_email.hashCode());
		result = prime * result + ((u_id == null) ? 0 : u_id.hashCode());
		result = prime * result
				+ ((u_idcard == null) ? 0 : u_idcard.hashCode());
		result = prime * result + ((u_name == null) ? 0 : u_name.hashCode());
		result = prime * result
				+ ((u_password == null) ? 0 : u_password.hashCode());
		result = prime * result + ((u_power == null) ? 0 : u_power.hashCode());
		result = prime * result + ((u_sex == null) ? 0 : u_sex.hashCode());
		result = prime * result
				+ ((u_telephone == null) ? 0 : u_telephone.hashCode());
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
		User other = (User) obj;
		if (u_address == null) {
			if (other.u_address != null)
				return false;
		} else if (!u_address.equals(other.u_address))
			return false;
		if (u_email == null) {
			if (other.u_email != null)
				return false;
		} else if (!u_email.equals(other.u_email))
			return false;
		if (u_id == null) {
			if (other.u_id != null)
				return false;
		} else if (!u_id.equals(other.u_id))
			return false;
		if (u_idcard == null) {
			if (other.u_idcard != null)
				return false;
		} else if (!u_idcard.equals(other.u_idcard))
			return false;
		if (u_name == null) {
			if (other.u_name != null)
				return false;
		} else if (!u_name.equals(other.u_name))
			return false;
		if (u_password == null) {
			if (other.u_password != null)
				return false;
		} else if (!u_password.equals(other.u_password))
			return false;
		if (u_power == null) {
			if (other.u_power != null)
				return false;
		} else if (!u_power.equals(other.u_power))
			return false;
		if (u_sex == null) {
			if (other.u_sex != null)
				return false;
		} else if (!u_sex.equals(other.u_sex))
			return false;
		if (u_telephone == null) {
			if (other.u_telephone != null)
				return false;
		} else if (!u_telephone.equals(other.u_telephone))
			return false;
		return true;
	}
}
