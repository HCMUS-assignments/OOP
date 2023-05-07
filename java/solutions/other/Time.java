import java.util.*;

public class Time {
    private int h, mn;  // ignore seconds
    private int d, mth, y;

    public Time() {
            h = 0;
            mn = 0;
            d = 0;
            mth = 0;
            y = 0;
        };


    public void setTime(String strTime) {
        // strTime = "dd/mm/yyyy hh:mm"
        String[] arr = strTime.split(" ");
        String[] arrDate = arr[0].split("/");
        String[] arrTime = arr[1].split(":");

        d = Integer.parseInt(arrDate[0]);
        mth = Integer.parseInt(arrDate[1]);
        y = Integer.parseInt(arrDate[2]);

        h = Integer.parseInt(arrTime[0]);
        mn = Integer.parseInt(arrTime[1]);
    };

    public int h() {
        return h;
    };

    public int mn() {
        return mn;
    };

    public int d() {
        return d;
    };

    public int mth() {
        return mth;
    };

    public int y() {
        return y;
    };

    public String display() {
        return "Time: " + d + "/" + mth + "/" + y + " " + h + ":" + mn;
    };
};

