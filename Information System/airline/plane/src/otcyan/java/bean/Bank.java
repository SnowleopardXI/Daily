package otcyan.java.bean;

import java.io.Serializable;

public class Bank implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int b_id ;
    private String b_name ;
    private String b_u_name ;
    private String b_u_card ;
    private String b_account ;
    private String b_balance ;
	public Bank(int bId, String bName, String bUName, String bUCard,
			String bAccount, String bBalance) {
		super();
		b_id = bId;
		b_name = bName;
		b_u_name = bUName;
		b_u_card = bUCard;
		b_account = bAccount;
		b_balance = bBalance;
	}
	public int getB_id() {
		return b_id;
	}
	public void setB_id(int bId) {
		b_id = bId;
	}
	public String getB_name() {
		return b_name;
	}
	public void setB_name(String bName) {
		b_name = bName;
	}
	public String getB_u_name() {
		return b_u_name;
	}
	public void setB_u_name(String bUName) {
		b_u_name = bUName;
	}
	public String getB_u_card() {
		return b_u_card;
	}
	public void setB_u_card(String bUCard) {
		b_u_card = bUCard;
	}
	public String getB_account() {
		return b_account;
	}
	public void setB_account(String bAccount) {
		b_account = bAccount;
	}
	public String getB_balance() {
		return b_balance;
	}
	public void setB_balance(String bBalance) {
		b_balance = bBalance;
	}
	@Override
	public String toString() {
		return "Bank [b_account=" + b_account + ", b_balance=" + b_balance
				+ ", b_id=" + b_id + ", b_name=" + b_name + ", b_u_card="
				+ b_u_card + ", b_u_name=" + b_u_name + "]";
	}
}
