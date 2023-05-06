Staff.class : Staff.java
	javac Staff.java

SeasonalStaff.class: SeasonalStaff.java Staff.class
	javac SeasonalStaff.java

FullTimeStaff.class : FullTimeStaff.java Staff.class
	javac FullTimeStaff.java

Manager.class : Manager.java FullTimeStaff.class
	javac Manager.java

Invoice.class : Invoice.java 
	javac Invoice.java

Drink.class : Drink.java
	javac Drink.java

InvoiceDetails.class : InvoiceDetails.java
	javac InvoiceDetails.java

StoreManagement.class : StoreManagement.java SeasonalStaff.class Manager.class Invoice.class InvoiceDetails.class Drink.class
	Javac StoreManagement.java

Test.class : Test.java StoreManagement.class
	javac Test.java

run: Test.class
	java Test





clean:
	rm -f *.class