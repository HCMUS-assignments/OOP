package package2;

import package1.Time;
import java.util.*;

public class Motobike {
    private    String licensePlate;
    private    Time timeIn;
    private    Time timeOut;

    private    int fee;

    public    Motobike() {
            licensePlate = "";
            fee = 0;
        }


    public    Motobike(String license, String time) {
            licensePlate = license;
            timeIn.setTime(time);
            fee = 0;
        };

    public    void calcFee() {
            // compare day//mth in and day//mth out (ignore year) 
            if (timeOut.mth() == timeIn.mth()) {
                if (timeOut.d() == timeIn.d()) {
                    // same day
                    if (timeIn.h() > 0 && timeIn.h() < 6) {
                        if (timeOut.h() > 0 && timeOut.h() < 6) {
                            fee = 10000;    // 1 night
                        } else {
                            if (timeOut.h() > 6 && timeOut.h() < 18) {
                                fee = 15000;    // 1 night + 1 day
                            } else {
                                fee = 25000;    // 2 night + 1 day
                            }
                        }
                    } else if (timeIn.h() > 6 && timeIn.h() <18) {
                        if (timeOut.h() > 6 && timeOut.h() < 18) {
                            fee = 5000;     // 1 day
                        } else {
                            fee = 15000;    // 1 night + 1 day
                        }
                        
                    }
                } else {
                    // different day
                    int nightTime, dayTime = 0;

                 
                }
            } else {
                // different month
               
                }

            
        };
           

    public    void setTimeOut(String time) {
            timeOut.setTime(time);
        };

    public    String getLicensePlate() {
            return licensePlate;
        };

    public    Time getTimeIn() {
            return timeIn;
        };

    public    Time getTimeOut() {
            return timeOut;
        };

    public    int getFee() {
            return fee;
        };

    public    void display() {
            System.out.print("License plate: " + licensePlate);
            System.out.print(" | Time in: " + timeIn.display());
            System.out.print(" | Time out: " + timeOut.display());
            System.out.println(" | Fee: " + fee);
        };
};




