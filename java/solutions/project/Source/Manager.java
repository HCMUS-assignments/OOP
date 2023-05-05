public class Manager extends FullTimeStaff {
    private int allowance;

    public Manager (String sID, String sName, int baseSalary, int bonusRate, int allowance) {
        super.FullTimeStaff(sID, sName, baseSalary, bonusRate);
        this.allowance = allowance;
    }

    public int getAllowance()  {
        return allowance;
    }

    @Override
    public double paySalary(int workedDays) {
        return super.paySalary(workedDays) + allowance;
    }

    @Override
    public String toString() {
        return this.sID + '_' + this.sName + '_' + this.bonusRate + '_' + this.baseSalary + '_' + this.allowance;

    }
}