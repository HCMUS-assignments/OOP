public class SeaSonalStaff extends Staff {
    private int hourlyWage;

    public SeaSonalStaff(String sID, String sName, int hourlyWage) {
        super(sID, sName);
        this.hourlyWage = hourlyWage;
    }

    public int getHourlyWage() {
        return this.hourlyWage;
    }

    public void setHourlyWage(int hourlyWage) {
        this.hourlyWage = hourlyWage;
    }

    @Override
    public double paySalary(int workedHours) {
        return hourlyWage * workedHours;
    }

    @Override
    public String toString() {
        return this.sID + '_' + this.sName + '_' + this.hourlyWage;
    }
}