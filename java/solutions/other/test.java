// Viết chương trình Java đơn giản mô tả số lượng xe máy trong nhà xe. Mỗi lần gửi xe máy hệ thống ghi lại biển số và thời gian gửi. 

// 1. Tính số tiền khi xe ra khỏi nhà xe. Biết rằng ban ngày 5000 đồng, ban đêm 10.000 đồng

// 2. Hiển thị số tiền thu được sau mỗi ngày (tính đến 23h59)


public class test {
    public static void main(String[] args) {
        // test cases
        Garage garage = new Garage();
        garage.addMotobike("abc","29/10/2019 01:00");
        garage.addMotobike("xyz","30/10/2019 19:00");

        System.out.println("Fee | " + garage.getFeeMotobike("abc","29/10/2019 02:00") );
        System.out.println("Fee | " + garage.getFeeMotobike("xyz","30/10/2019 20:00") );
        

        System.out.println("Total fee day | " + garage.calcTotalFeeAtDay("29/10/2019"));
        System.out.println("Total fee day | " + garage.calcTotalFeeAtDay("30/10/2019"));
    
    }
}