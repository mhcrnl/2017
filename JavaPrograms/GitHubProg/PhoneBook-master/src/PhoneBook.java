import java.util.ArrayList;

/**
 * Created by Соня on 17.10.2014.
 */

interface Property {
    void setProperties();
}

interface Action {
    void addItem(String x, String y, String z);
    void removeItem(int index);
}

abstract class Component implements Action, Property {
    abstract public void addItem(String x, String y, String z);

    abstract public void removeItem(int index);

    public void setProperties(){
    }
}

public class PhoneBook extends Component {

    private static class People
    {
        String name;
        String surname;
        String address;
        public People(String name, String surname, String address)
        {
            this.address = address;
            this.name = name;
            this.surname = surname;
        }

    }
    private ArrayList<People> listPep = new ArrayList<People>();

    @Override
    public void addItem(String x, String y, String z){
        listPep.add(new People(x, y, z));
    }

    @Override
    public void removeItem(int index) {
        listPep.remove(index);
    }

    static String regularExpression = "[^0-9]";

    public static void validate(String phoneNumber) {

        class PhoneNumber {
            String formattedPhoneNumber;

            PhoneNumber(String phoneNumber) {
                String currentNumber = phoneNumber.replaceAll(regularExpression, "");
                if (currentNumber.length() == 10)
                    formattedPhoneNumber = currentNumber;
                else
                    formattedPhoneNumber = null;
            }

            public String getNumber() {
                return formattedPhoneNumber;
            }
        }

        PhoneNumber myNumber = new PhoneNumber(phoneNumber);
        if (myNumber.getNumber() == null)
            System.out.println("Неверный номер");
        else
            System.out.println("Номер " + myNumber.getNumber());

    }

    private interface SayHello
    {
        void hello();
    }
    SayHello HelloUser = new SayHello() {
        @Override
        public void hello() {
            System.out.println("Hello");
        }
    };
}