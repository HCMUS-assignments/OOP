/* 
Given a Vietnamese fullname (ex “Nguyen Van Teo”). 
Students need to write methods as follows:
1. Count how many words in the name.
2. Return a first name
3. Return a last name
4. Return a middle name
5. Capitalize the first character in each word of the name
6. Formalize the name, including:
q Delete all spaces in front and behind of the name.
q Leave one space between the words of the name.

*/

import java.util.Scanner;

public class exercise {
    public static int countWords(String name) {
        int count = 0;
        String duplicateName = name;
        duplicateName = duplicateName.trim();

        System.out.println(duplicateName);
        System.out.println(name);

        return count;
    }


    public static void main(String[] args) {
        String name = "      Nguyen       Van Teo      ";
        countWords(name);
        // System.out.println(countWords(name));
    }
}
 


 ....