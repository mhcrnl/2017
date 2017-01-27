package phone;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */

//A simple class to store a name, address and phone number.
public class Contact implements Item {
	//Instance variables:
	private String name;
	private String address;
	private String phoneNumber;

	//	Constructor that sets name, address and number to empty strings.
	public Contact () {
		name= "";
		address="";
		phoneNumber="";
	}

	/**
	 * Constructor that sets name, address and phone number to given values.
	 * @param  name   The initial name
	 * @param  address   The initial name
	 * @param  phone number The initial phone number
	 */
	public Contact (String name, String address, String phoneNumber) {
		this.name = name;
		this.address = address;
		this.phoneNumber = phoneNumber;
	}

	//	Accessor method to retrieve the name.
	public String getName() {
		return name;
	}

	//	Mutator method to set name to given value.
	public void setName(String name) {
		this.name = name;
	}

	//	Accessor method to retrieve the address.
	public String getAddress() {
		return address;
	}

	//	Mutator method to address to given value.
	public void setAddress(String address) {
		this.address = address;
	}

	//	Accessor method to retrieve the phone number.
	public String getPhoneNumber() {
		return phoneNumber;
	}

	//	Mutator method to set phone number to given value.
	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}
}