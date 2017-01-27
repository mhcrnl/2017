package phone;

/**
 * (c) Ermias B. Tesfamariam 2010
 *
 * @author Ermias
 * @since 09:01:39 - 21.03.2010
 */
//An interface sub type of item class with extended Accessor methods to retrieve email and age
public interface ItemExtended extends Item{
	public String getEmail();
	public String getAge();
}
