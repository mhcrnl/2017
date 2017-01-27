package phone;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */

public class MyMain {

	static PhonebookExtended myPhonebook= new PhonebookExtended("Friends");

	private void test(){
/*
		Contact contact1 = new ContactExtended("Mary","Eritrea","07179183","maryjs@yahoo.com","20");
		Contact contact2 = new ContactExtended("Ermias","Spain","12345","al143368@uji.es","27");
		Contact contact3 = new ContactExtended("Abel","Kenya","456789","abega16@yahoo.com","28");
		Company company1=new CompanyExtended("UJI","Spain","987654","uji@uji.es","30");

		myPhonebook.addItem(contact1);
		myPhonebook.addItem(contact2);
		myPhonebook.addItem(contact3);
		myPhonebook.addItem(company1);
*/
		// Menu list
		int i;
		do{
			System.out.println("\n----------MENU--------\n");
			System.out.println("1.Add New Contact to Phonebook");
			System.out.println("2.Search Contact");
			System.out.println("3.List of All Contacts");
			System.out.println("4.Add Company to Phonebook");
			System.out.println("5.Search by Email");
			System.out.println("6.Generate XML");
			System.out.println("7.Save Entries");
			System.out.println("0.Exit");
			System.out.print("Choose from Menu:");

			i=Keyboard.readInteger();
			menu(i);
		}while(i!=0);
	}
	// Method to input contact in the phone book
	public void addContactToPhonebook(){
		System.out.println("Name: ");
		String name=Keyboard.readString();
		System.out.println("Address: ");
		String address=Keyboard.readString();
		System.out.println("Phone Number: ");
		String phoneNumber=Keyboard.readString();
		System.out.println("Email: ");
		String email=Keyboard.readString();
		System.out.println("Age: ");
		String age=Keyboard.readString();
		myPhonebook.addItem(new ContactExtended(name,address,phoneNumber,email,age));
	}
	//method to search contact by name

	public void searchByName(){
		System.out.print("Search Phonebook by Name: ");
		String name = Keyboard.readString();
		myPhonebook.searchItemByName(name);
	}
	//Method to search by Email
	public void searchByEmail(){
		System.out.print("Search Phonebook by Email: ");
		String email = Keyboard.readString();
		myPhonebook.searchItemByEmail(email);
	}
	//Method to list all contacts
	public void contactList() {
		myPhonebook.ItemList();
	}
	// method to add Company in phone book
	public void addCompanyToPhonebook(){
		System.out.println("Company Name: ");
		String name=Keyboard.readString();
		System.out.println("Company Address: ");
		String address=Keyboard.readString();
		System.out.println("Company Phone Number: ");
		String phoneNumber=Keyboard.readString();
		System.out.println("Company Email: ");
		String email=Keyboard.readString();
		System.out.println("Company Age: ");
		String age=Keyboard.readString();
		myPhonebook.addItem(new CompanyExtended(name,address,phoneNumber,email,age));
	}
	// method to generate an XML of all items in the phone book
	public void generateXML(){
		new XMLGenerator().genXML(myPhonebook);
	}
	//Menu
	public void menu(int a){
		switch (a){
		case 0 :
			System.out.println("\nGOOD BYE!");
			break;
		case 1:
			addContactToPhonebook();
			break;
		case 2:
			searchByName();
			break;
		case 3:
			contactList();
			break;
		case 4:
			addCompanyToPhonebook();
			break;
		case 5:
			searchByEmail();
			break;
		case 6:
			generateXML();
			break;
		case 7:
			doOutput();
			break;
		default:
			System.out.println("INVALID VALUE");
			break;
		}
	}
	// Method to save entries in to a file
	private void doOutput() {
		System.out.println("\n***DATA SAVED***");
		try {
			PrintWriter pw = new PrintWriter("data.txt");
			for(Item tmp:myPhonebook.myItems){
				for(int i = 0; i < myPhonebook.getNumberItem(); i++)
					if(i==myPhonebook.getNumberItem()-1)
				pw.println(tmp.getName()+";"+tmp.getAddress()+";"+tmp.getPhoneNumber()+";"+((ItemExtended) tmp).getEmail()+";"+((ItemExtended) tmp).getAge());
				
			}
			pw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {

		if(args.length == 1) {
			File f = new File(args[0]);
			FileReader fr;
			try {
				fr = new FileReader(f);
				BufferedReader br = new BufferedReader(fr);
				String string;
				while((string = br.readLine())!= null){
//					System.out.println(string);
				String s[]= string.split(";");
				for(int i=0; i<s.length;i++)
					s[i]=s[i].trim();
					String name =s[0];
					String address =s[1];
					String phoneNumber =s[2];
					String email =s[3];
					String age =s[4];
					myPhonebook.addItem(new ContactExtended(name,address,phoneNumber,email,age));
				}
				br.close();
			} catch(FileNotFoundException e) {
				e.printStackTrace();
			}catch(IOException e) {
				e.printStackTrace();
			}
		}
		new MyMain().test();
	}
}
