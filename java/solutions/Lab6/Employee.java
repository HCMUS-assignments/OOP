import java.time.LocalDate;

public class Employee {
    // attributes
    protected String ID;
    protected String fullName;
    protected int yearJoined;
    protected double coefficientsSalary;
    protected int numDaysOff;
    protected int basicSalary = 1150;

    // constructors
    public Employee() {
        this("0", "", 1.0);
    }

    public Employee(String ID, String fullName, double coefficientsSalary ) {
        this.ID = ID;
        this.fullName = fullName;
        this.coefficientsSalary = coefficientsSalary;
        this.yearJoined = 2020;
        this.numDaysOff = 0;
    }

    public Employee(String ID, String fullName, double coefficientsSalary, int yearJoined, int numDaysOff) {
        this(ID, fullName, coefficientsSalary);
        this.yearJoined = yearJoined;
        this.numDaysOff = numDaysOff;
    }

    // methods
    public double getSenioritySalary() {
        LocalDate currentDate = LocalDate.now();
        int year = currentDate.getYear();
        int yearOfWork = year - yearJoined;

        if (yearOfWork >= 5) {
            return yearOfWork * basicSalary / 100;
        }
        return 0;
    }

    public String considerEmulation() {
        if (numDaysOff <= 1) {
            return "A";
        } else if (numDaysOff >=2 && numDaysOff <= 3) {
            return "B";
        } else {
            return "C";
        }
    }

    public double getSalary() {
        double emuCoeff = 0;
        if (considerEmulation().equals("A")) {
            emuCoeff = 1.0;
        } else if (considerEmulation().equals("B")) {
            emuCoeff = 0.75;
        } else {
            emuCoeff = 0.5;
        }

        return basicSalary + basicSalary * (coefficientsSalary + emuCoeff) + getSenioritySalary();
    }
}