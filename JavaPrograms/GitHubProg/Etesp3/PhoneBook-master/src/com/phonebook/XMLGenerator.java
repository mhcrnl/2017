package phone;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */
public class XMLGenerator {
	
// 	Method to generate an XML of the list of Contacts
	
	public void genXML(Phonebook newPhonebook){
		
		System.out.println("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>");
		System.out.println("<?xml-stylesheet href=\"newPhoneBook.xsl\" type=\"text/xsl\"?>");
		System.out.println("<phoneBook>");
		for(Item tmp:newPhonebook.myItems){
//		for(int i = 0; i < newPhonebook.getNumberItem(); i++) {
//			ItemExtended tmp = (ItemExtended) newPhonebook.getItemAt(i);
			System.out.println("<item>");
			System.out.println("<name>"+tmp.getName()+"</name>");
			System.out.println("<address>"+tmp.getAddress()+"</address>");
			System.out.println("<phone>"+tmp.getPhoneNumber()+"</phone>");
			System.out.println("<email>" +((ItemExtended) tmp).getEmail()+"</email>");
			System.out.println("<age>" +((ItemExtended) tmp).getAge()+"</age>");
			System.out.println("</item>");			
		}
		System.out.println("</phoneBook>");	
	}
}
