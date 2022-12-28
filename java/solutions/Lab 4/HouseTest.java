import package4.House;

public class HouseTest {
    public static void main(String[] args) {
        House myHouse = new House();
        myHouse.setHouseCode("225");
        myHouse.setNumbOfBedRooms(3);
        myHouse.setHasSwimmingPool(true);
        myHouse.setArea(200);
        myHouse.setCostPerSquareMeter(1000);
        System.out.println("House Code: " + myHouse.getHouseCode());
        System.out.println("Number of Bedrooms: " + myHouse.getNumbOfBedRooms());
        System.out.println("Has Swimming Pool: " + myHouse.isHasSwimmingPool());
        System.out.println("Area: " + myHouse.getArea());
        System.out.println("Cost Per Square Meter: " + myHouse.getCostPerSquareMeter());
        System.out.println("Selling Price: " + myHouse.calculateSellingPrice());

        System.out.println(myHouse.toString());
    }
}