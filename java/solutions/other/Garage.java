import java.util.Scanner;
import java.util.Vector;

public class Garage {
    private int totalFee;
    private Vector<Motobike> motobikes;

    public Garage() {
            totalFee = 0;
            motobikes = new Vector<Motobike>();
        }

    public    void addMotobike(String license, String timeIn) {
            // add info of motobike to list
            Motobike motobike = new Motobike(license, timeIn);
            motobikes.add(motobike);
        }

    public    int getFeeMotobike(String license, String timeOut) {
            // calculate fee of motobike when it out
            int i = 0;
            for ( ; i < motobikes.size(); i++) {
                if (motobikes.get(i).getLicensePlate().equals(license)) {
                    motobikes.get(i).setTimeOut(timeOut);
                    motobikes.get(i).calcFee();
                    totalFee += motobikes.get(i).getFee();
                    break;
                }
            }
            return motobikes.get(i).getFee();

        }

    public    int calcTotalFeeAtDay(String time) {
            // time: dd/mm/yyyy
            // split time into d, mth, y
            String[] arr = time.split("/");
            int d = Integer.parseInt(arr[0]);
            int mth = Integer.parseInt(arr[1]);
            int y = Integer.parseInt(arr[2]);

            int fee = 0;

            for (int i = 0; i < motobikes.size(); i++) {
                if (motobikes.get(i).getTimeOut().d() == d && motobikes.get(i).getTimeOut().mth() == mth && motobikes.get(i).getTimeOut().y() == y) {
        
                    fee += motobikes.get(i).getFee();
                }
            }

            return fee;
        }

    public    void rmMotobikesOut () {
            for (int i = 0; i < motobikes.size(); i++) {
                if (motobikes.get(i).getTimeOut().d() != 0) {
                    motobikes.remove(i);
                }
            }
        }

    public    void displayTotalFeeAt(String time) {
            System.out.println("Total fee of day: " + calcTotalFeeAtDay(time));

        }
};