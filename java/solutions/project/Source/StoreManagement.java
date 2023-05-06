import java.io.*;
import java.util.*;

public class StoreManagement {
    private ArrayList<Staff> staffs;
    private ArrayList<String> workingTime;
    private ArrayList<Invoice> invoices;
    private ArrayList<InvoiceDetails> invoiceDetails;
    private ArrayList<Drink> drinks;

    public StoreManagement(String staffPath, String workingTimePath, String invoicesPath, String detailsPath, String drinksPath) {
        this.staffs = loadStaffs(staffPath);
        this.workingTime = loadFile(workingTimePath);
        this.invoices = loadInvoices(invoicesPath);
        this.invoiceDetails = loadInvoicesDetails(detailsPath);
        this.drinks = loadDrinks(drinksPath);
    }

    public ArrayList<Staff> getStaffs() {
        return this.staffs;
    }

    public void setStaffs(ArrayList<Staff> staffs){
        this.staffs = staffs;
    }
    
    public ArrayList<Drink> loadDrinks(String filePath) {
        ArrayList<Drink> drinksResult = new ArrayList<Drink>();
        ArrayList<String> drinks = loadFile(filePath);

        for (String drink : drinks) {
            String[] information = drink.split(",");
            drinksResult.add(new Drink(information[0], Integer.parseInt(information[1])));
        }

        return drinksResult;
    }

    public ArrayList<Invoice> loadInvoices(String filePath) {
        ArrayList<Invoice> invoiceResult = new ArrayList<Invoice>();
        ArrayList<String> invoices = loadFile(filePath);

        for (String invoice : invoices) {
            String[] information = invoice.split(",");
            invoiceResult.add(new Invoice(information[0], information[1], information[2]));
        }

        return invoiceResult;
    }

    public ArrayList<InvoiceDetails> loadInvoicesDetails(String filePath) {
        ArrayList<InvoiceDetails> invoiceResult = new ArrayList<InvoiceDetails>();
        ArrayList<String> invoices = loadFile(filePath);

        for (String invoice : invoices) {
            String[] information = invoice.split(",");
            invoiceResult.add(new InvoiceDetails(information[0], information[1], Integer.parseInt(information[2])));
        }

        return invoiceResult;
    }

    // requirement 1
    public ArrayList<Staff> loadStaffs(String filePath) {
        //code here and modify the return value
        ArrayList<Staff> staffsResult  = new ArrayList<Staff>();
        ArrayList<String> staffs = loadFile(filePath);

        for (String staff  : staffs) {
            String [] information = staff.split(",");
            switch (information.length) {
                case 3: 
                    staffsResult.add(new SeasonalStaff(information[0], information[1], Integer.parseInt(information[2])));
                    break;

                case 4:
                    staffsResult.add(new FullTimeStaff(information[0], information[1], Integer.parseInt(information[2]), Double.parseDouble(information[3])));
                    break;

                case 5:
                    staffsResult.add(new Manager(information[0], information[1], Integer.parseInt(information[2]), Double.parseDouble(information[3]), Integer.parseInt(information[4])));
                    break;

                default: 
                    System.out.println("Error loadStaff: wrong format staff information !");
                    break;
            }
        }
        return staffsResult;
    }

    // requirement 2
    public ArrayList<SeasonalStaff> getTopFiveSeasonalStaffsHighSalary() {
        //code here and modify the return value
        ArrayList<SeasonalStaff> listSeaSonal = new ArrayList<SeasonalStaff>();
        for (Staff staff : staffs) {
            if (staff instanceof SeasonalStaff) {
                listSeaSonal.add((SeasonalStaff)staff);
            }
        }

        Map<String, Integer> ID_WTime = new HashMap<String, Integer>();
        for (String line : workingTime) {
            String[] token = line.split(",");
            ID_WTime.put(token[0], Integer.parseInt(token[1]));
        }

        Collections.sort(listSeaSonal, new Comparator<SeasonalStaff>() {
            @Override
            public int compare(SeasonalStaff s1, SeasonalStaff s2) {
                if (s1.paySalary(ID_WTime.get(s1.getsID())) < s2.paySalary(ID_WTime.get(s2.getsID()))) {
                    return 1;
                } else if (s1.paySalary(ID_WTime.get(s1.getsID())) > s2.paySalary(ID_WTime.get(s2.getsID()))) {
                    return -1;
                } else {
                    return 0;
                }
            }
        });
        ArrayList<SeasonalStaff> topFive = new ArrayList<SeasonalStaff>();
        for (int i = 0; i < 5; i++) {
            topFive.add(listSeaSonal.get(i));
        }
        return topFive;
    }

    // requirement 3
    public ArrayList<FullTimeStaff> getFullTimeStaffsHaveSalaryGreaterThan(int lowerBound) {
        //code here and modify the return value
        Map<String, Integer> ID_WTime = new HashMap<String, Integer>();
        for (String line : workingTime) {
            String[] token = line.split(",");
            ID_WTime.put(token[0], Integer.parseInt(token[1]));
        }

        ArrayList<FullTimeStaff> result = new ArrayList<FullTimeStaff>();
        for (Staff staff : staffs) {
            if (staff instanceof FullTimeStaff) {
                if (staff.paySalary(ID_WTime.get(staff.getsID())) > lowerBound) {
                    result.add((FullTimeStaff)staff);
                }
            }
        }
        return result;
    }

    // method supply for requirement 4 and 5
    Map<String, Integer> initTotalBill() {
        // convert  drinks into map(K,V)
        Map<String, Integer> Name_Price = new HashMap<String, Integer>();
        for (Drink drink : drinks) {
            Name_Price.put(drink.getdName(), drink.getPrice());
        }

        Map<String, String> HD_Name_SL = new HashMap<String, String>();
        for (InvoiceDetails inDetails : invoiceDetails) {
            String Name_SL = inDetails.getDName() + "," + inDetails.getAmount();
            HD_Name_SL.put(inDetails.getInvoiceID(), Name_SL);
        }

        Map<String, Integer> result = new HashMap<String, Integer>(); // MaHD, Total price
        for (Invoice temp : invoices) {
            String[] token = HD_Name_SL.get(temp.getInvoiceID()).split(",");
            int price = Name_Price.get(token[0]);
            int quantity = Integer.parseInt(token[1]);
            result.put(temp.getInvoiceID(), price * quantity);
        }
        return result;
    }

    // requirement 4
    public double totalInQuarter(int quarter) {
        Map<String, Integer> bills = initTotalBill();
        
        double total = 0;
        // code here
        int firstMonth = (quarter - 1) * 3 + 1;
        int lastMonth = firstMonth + 2;

        for (Invoice invoice : invoices) {
            String[] token = invoice.getDate().split("/");
            int m = Integer.parseInt(token[1]);
            if ( m >= firstMonth && m <= lastMonth ) {
                total += bills.get(invoice.getInvoiceID());
            }
        }

        return total;
    }

    // requirement 5
    public Staff getStaffHighestBillInMonth(int month) {
        Staff maxStaff = null;
        //code here
        Map<String, Integer> bills = initTotalBill();       // MaHD - Total price

        Map<String, Integer> staffBill = new HashMap<String, Integer>();   // MaNV - Total bill

        for (Invoice in : invoices) {
            String[] token = in.getDate().split("/");
            int m = Integer.parseInt(token[1]);
            if (m == month) {
                String idStaff = in.getStaffID();
                if (staffBill.get(idStaff) == null) {
                    staffBill.put(idStaff, bills.get(in.getInvoiceID()));
                } else {
                    int value = staffBill.get(idStaff);
                    staffBill.put(idStaff, value + bills.get(in.getInvoiceID()));
                }
            }
        }

        List<Map.Entry<String, Integer>> sortedList = new LinkedList<>(staffBill.entrySet());
        Collections.sort(sortedList, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> s1, Map.Entry<String, Integer> s2) {
                return s2.getValue().compareTo(s1.getValue());
            }
        });

        Map.Entry<String, Integer> firstEntry = sortedList.get(0);

        String id = firstEntry.getKey();

        // System.out.println("Req 5: MaNV: " + id);

        for (Staff s : staffs) {
            if (id.equals(s.getsID())) {
                maxStaff = s;
                break;
            }
        }

        return maxStaff;
    }

    // load file as list
    public static ArrayList<String> loadFile(String filePath) {
        String data = "";
        ArrayList<String> list = new ArrayList<String>();

        try {
            FileReader reader = new FileReader(filePath);
            BufferedReader fReader = new BufferedReader(reader);

            while ((data = fReader.readLine()) != null) {
                list.add(data);
            }

            fReader.close();
            reader.close();

        } catch (Exception e) {
            System.out.println("Cannot load file");
        }
        return list;
    }

    public void displayStaffs() {
        for (Staff staff : this.staffs) {
            System.out.println(staff);
        }
    }

    public <E> boolean writeFile(String path, ArrayList<E> list) {
        try {
            FileWriter writer = new FileWriter(path);
            for (E tmp : list) {
                writer.write(tmp.toString());
                writer.write("\r\n");
            }

            writer.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("Error.");
            return false;
        }

        return true;
    }

    public <E> boolean writeFile(String path, E object) {
        try {
            FileWriter writer = new FileWriter(path);

            writer.write(object.toString());
            writer.close();

            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("Error.");
            return false;
        }

        return true;
    }
}