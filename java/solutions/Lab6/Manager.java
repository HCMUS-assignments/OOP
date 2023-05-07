public class Manager extends Employee {
    protected String position;
    protected String department;
    protected double coeffSalaryByPos;

    // constructors
    public Manager() {
        super();
        this.coefficientsSalary = 5.0;
        this.position = "head of tje office at the administrative office";
    }

    public Manager(String ID, String fullName, double coefficientsSalary, String position, double salaryCoeffPos) {
        super(ID, fullName, coefficientsSalary, 2020,0);
        this.position = position;
        this.coeffSalaryByPos = salaryCoeffPos;
    }

    public Manager(String ID, String fullName, double coefficientsSalary, String position, double salaryCoeffPos, int yearJoined, int numDaysOff) {
        this(ID, fullName, coefficientsSalary, position, salaryCoeffPos);
        this.yearJoined = yearJoined;
        this.numDaysOff = numDaysOff;
    }

    // methods
    @Override
    public String considerEmulation() {
        return "A";
    }

    public double bonusByPosition() {
        return basicSalary * coeffSalaryByPos;        
    }

    @Override
    public double getSalary() {
        return super.getSalary() + bonusByPosition();
    }
}