package package4;

public class House {
    private String houseCode;
    private int numbOfBedRooms;
    private boolean hasSwimmingPool;
    private double area;
    private double costPerSquareMeter;

    // methods
    
    public House () {
        this.houseCode = "A01";
        this.numbOfBedRooms = 2;
        this.hasSwimmingPool = false;
        this.area = 0;
        this.costPerSquareMeter = 0;
    }

    // getter and setter methods

    public String getHouseCode() {
        return houseCode;
    }

    public void setHouseCode(String houseCode) {
        this.houseCode = houseCode;
    }

    public int getNumbOfBedRooms() {
        return numbOfBedRooms;
    }

    public void setNumbOfBedRooms(int numbOfBedRooms) {
        this.numbOfBedRooms = numbOfBedRooms;
    }

    public boolean isHasSwimmingPool() {
        return hasSwimmingPool;
    }

    public void setHasSwimmingPool(boolean hasSwimmingPool) {
        this.hasSwimmingPool = hasSwimmingPool;
    }

    public double getArea() {
        return area;
    }

    public void setArea(double area) {
        this.area = area;
    }

    public double getCostPerSquareMeter() {
        return costPerSquareMeter;
    }

    public void setCostPerSquareMeter(double costPerSquareMeter) {
        this.costPerSquareMeter = costPerSquareMeter;
    }

    // calculate the selling price of the house according to formula
    // subTotal = area * costPerSquareMeter
    // if the house has a swimming pool, subTotal will add 10% values of the subTotal
    //  Selling price = subTotal + 15% tax

    public double calculateSubTotal() {
        double subTotal = this.area * this.costPerSquareMeter;
        if (this.hasSwimmingPool) {
            subTotal += subTotal * 0.1;
        }
        return subTotal;
    }

    public double calculateSellingPrice() {
        double sellingPrice = calculateSubTotal() * 1.15;
        return sellingPrice;
    }

    // display the information of the house
    public String toString() {
        String str = "House [ " + houseCode + "," + numbOfBedRooms + "," + hasSwimmingPool + "," + calculateSellingPrice() + "]";
        return str;
    }
}