import java.lang.*;

public class Person {
    // attributes
    protected String name;
    protected String address;

    // methods and constructions 
    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public String getName() {
        return this.name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String add) {
        this.address = add;
    }

    @Override
    public String toString() {
        return " name: " + name + " - address: " + address; 
    }
}