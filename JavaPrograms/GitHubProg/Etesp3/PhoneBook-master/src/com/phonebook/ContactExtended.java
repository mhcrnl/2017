package phone;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */

//	A sub class of the contact class to extend an email and age instance variables.

public class ContactExtended extends Contact implements ItemExtended{
//	the added instance variables
	private String email;
	private String age;
	
//	Accessor method to retrieve the email.
	public String getEmail() {
		return email;
	}
//	Mutator method to set email to given value.
	public void setEmail(String email) {
		this.email = email;
	}
//	Mutator method to set age to given value.
	public void setAge(String age) {
		this.age = age;
	}
//	Accessor method to retrieve the age.
	public String getAge() {
		return age;
	}
//	Constructor that calls a super class constructor and sets email and age to empty strings.
	public ContactExtended(){
		super();
		email="";
		age="";
	}
	/**
	 * Constructor that calls a super class constructor and sets email and age to given values.
	 * @param  email   The initial email
	 * @param  age   The initial age
	 */
	public ContactExtended(String name, String address, String phoneNumber, String email, String age){
		super(name,address,phoneNumber);
		this.email=email;
		this.age=age;
	}
}
