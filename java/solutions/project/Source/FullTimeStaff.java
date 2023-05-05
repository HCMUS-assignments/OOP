public class FullTimeStaff extends Staff {
    protected int baseSalary;
    protected double bonusRate;

    public FullTimeStaff(String sID, String sName, int baseSalary, int bonusRate) {
        super.Staff(sID, sName);
        this.baseSalary = baseSalary;
        this.bonusRate = bonusRate;
    }

    public int getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary (int baseSalary) {
        this.baseSalary = baseSalary;
    }

    public double getBonusRate() {
        return bonusRate;
    }

    public void setBonusRate(double bonusRate) {
        this.bonusRate = bonusRate;
    }

    @Override
    public double paySalary(int workedDays) {
        return baseSalary * bonusRate + (workedDays - 21) * 100000;

    }

    @Override 
    public String toString() {
        return this.sID + '_' + this.sName + '_' + this.bonusRate + '_' + this.baseSalary;
    }
}