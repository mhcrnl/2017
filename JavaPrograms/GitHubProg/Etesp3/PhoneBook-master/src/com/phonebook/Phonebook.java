package phone;

import java.util.ArrayList;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */
 
/**
 * A class to store names, addresses and numbers in a phone book.
 * Methods for adding a name, address and number to the book, and
 * for looking up a name, are included.
 */
public class Phonebook {
	//Instance variables:
	private String phonebookName;
	private int maxSize=100;
	ArrayList<Item> myItems=new ArrayList<Item>();

//	Constructor that sets name to empty strings.
	public Phonebook () {
		phonebookName = "";
	}
//	Constructor that sets phone book name to given values.
	public Phonebook (String phonebookName) {
		this.phonebookName = phonebookName;
	}
//	Accessor method to retrieve the phone book name.
	public String getPhonebookName() {
		return phonebookName;
	}
//	Mutator method to set phone book name to given value.
	public void setPhonebookName(String phonebookName) {
		this.phonebookName = phonebookName;
	}
// Method to Add Item to the phone book
	public void addItem(Item newItem){
		if(myItems.size() < maxSize) {
			myItems.add(newItem);
		}
		else
			System.out.println("Sorry, Memory Full!");
	}

//	Method to return the existing number of entries
	public int getNumberItem(){
		return myItems.size();
	}

	/**
	 * Method to return the Item corresponding to the given position.
	 * @param  position   the position.
	 * @return An Item (can be a contact or a company).
	 */

	public Item getItemAt (int i){
		return myItems.get(i);
	}
	
	//Method to list all Items of a phone book
	public void ItemList() {
		for(Item tmp:myItems){
			ItemExtended tmp1=(ItemExtended) tmp;
			System.out.println("\nName: " + tmp1.getName());
			System.out.println("Address: " + tmp1.getAddress());
			System.out.println("Phone: " + tmp1.getPhoneNumber());
			System.out.println("Email: " + tmp1.getEmail());
			System.out.println("Age: " + tmp1.getAge());
		}
	}
	
	/**
	 * Method to return the Contact corresponding to the given name.
	 * @param  aName   The given name.
	 * @return A Contact containing all attributes.
	 */

	public void searchItemByName (String aName){
		boolean found = false;
		for(Item tmp:myItems){
			if(aName.equals(tmp.getName())){
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









