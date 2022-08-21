/* Write a program to simulate a vending machine. This is the output of the demo program, you 
can use this output to build your program (Hint: you should use while statement and 
switch…case… statement) */

import java.util.Scanner;

public class Exercise14 {
    public static void menu() {
        System.out.println("-----Menu-----");
        System.out.println("1. Coca");
        System.out.println("2. Pepsi");
        System.out.println("3. Sprite");
        System.out.println("4. Snake");
        System.out.println("5. Shutdown Machine");
    }

    public static void solution(int itemPrice) {
        Scanner sc = new Scanner(System.in);
        int amount = sc.nextInt();
        if (amount >= itemPrice) {
            int remainMoney = amount - itemPrice;
            System.out.println("Your change is " + remainMoney + " $");
        } else {
            System.out.println("Not enough money to buy this item. Please select again.");
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);        

        // define variables
        final int COCA_PRICE = 2;
        final int PEPSI_PRICE = 3;
        final int SPRITE_PRICE = 5;
        final int SNAKE_PRICE = 4;

        // remain money
        int number = 0;

        // loop
        do {
            menu();
            // User input
            System.out.println("Please enter the number: ");
            number = input.nextInt();

            switch (number) {
                case 1:
                    System.out.println("The price of Coca is " + COCA_PRICE + " $" + ",please enter the amount of money: ");
                    solution(COCA_PRICE);
                    break;
                case 2:
                    System.out.println("The price of Pepsi is " + PEPSI_PRICE + " $" + ",please enter the amount of money: ");
                    solution(PEPSI_PRICE);
                    break;
                case 3:
                    System.out.println("The price of Sprite is " + SPRITE_PRICE + " $" + ",please enter the amount of money: ");
                    solution(SPRITE_PRICE);
                    break;
                case 4:
                    System.out.println("The price of Snake is " + SNAKE_PRICE + " $" + ",please enter the amount of money: ");
                    solution(SNAKE_PRICE);
                    break;
                case 5:
                    System.out.println("Machine is shutting down");
                    break;
                default:
                    System.out.println("Invalid input");
                    break;
                
            }
        } while (number != 5);

    }
}