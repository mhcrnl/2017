package phone;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */
//A sub class of the phone book to extend a method for looking up an email.
public class PhonebookExtended extends Phonebook{

//	an empty constructor that constructs the phonebookextended class
	public PhonebookExtended() {

	}
//	Constructor that calls the super class and sets name.	
	public PhonebookExtended (String phonebookName) {
		super(phonebookName);
	}
	/**
	 * Method to search the phone book and return the Contact corresponding to the given name.
	 * @param  aName   The given name.
	 * @return A Contact containing all attributes.
	 */
	public void searchItemByEmail (String anEmail){
		boolean found = false;
		for(Item tmp:myItems){
			if(anEmail.equals(((ItemExtended) tmp).getEmail())){
				found = true;
				System.out.println("\n****SEARCH FOUND****");
				System.out.println("\tName:" +tmp.getName());
				System.out.println("\tAddress:" +tmp.getAddress());
				System.out.println("\tPhone Number:" +tmp.getPhoneNumber());
				System.out.println("\tEmail:" +((ItemExtended) tmp).getEmail());
				System.out.println("\tAge:" +((ItemExtended) tmp).getAge());
			}		
		}
		if(!found){
			System.out.println("\n****SORRY, NOT FOUND****");
		}
	}	
}
