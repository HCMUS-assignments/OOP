// Write a function that receives a character and check whether it is alphanumeric or not (Hint: 
// you should use ASCII code).

import java.util.Scanner;

public class Exercise07 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a character: ");
        char ch = input.next().charAt(0);
        /* if (Character.isAlphabetic(ch) || Character.isDigit(ch)) {
            System.out.println("The character is alphanumeric");
        } else {
            System.out.println("The character is not alphanumeric");
        } */

        // get the ASCII code of the character
        int ascii = (int) ch;
        // check
        if (ascii >= 48 && ascii <= 57 || ascii >= 65 && ascii <= 90 || ascii >= 97 && ascii <= 122) {
            System.out.println("The character is alphanumeric");
        } else  {
            System.out.println("The character is not alphanumeric");
        }
    }
}