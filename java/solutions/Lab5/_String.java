import java.lang.*;
import java.util.*;

public class _String {
    public static String shortName(String str) {
        // Ex: Nguyen Le Trong Tin => Tin Nguyen
        String[] token = str.split(" ");
        return token[token.length - 1] + " " + token[0];
    }

    public static String hashtagName (String str) {
        // create names with hashtag
        // Ex: Nguyen Le Trong Tin => #TinNguyen

        String[] token = str.split(" ");
        return "#" + token[token.length - 1] + token[0] ;

    }

    public static  String upperCaseAllVowel(String str) {
        // uppercase all vowel letters
        // Ex: Nguyen Le Trong Tin => NgUyEn LE TrOng TIn
        // char[] chars = {'u', 'e', 'o', 'a', 'i'};
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == 'u' || chars[i] == 'e' || chars[i] == 'o' || chars[i] == 'a' || chars[i] == 'i') {
                chars[i] = Character.toUpperCase(chars[i]);
            }
        }
        return new String(chars);
    }

    public static String upperCaseAllN(String str) {
        // Ex: Nguyen Le Trong Tin => NguyeN Le TroNg TiN
        char[] chars = str.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == 'n') {
                chars[i] = 'N';
            }
        }
        return new String(chars);
    }

    public static void main(String [] args) {
        String str = "Nguyen Le Trong Tin";
        System.out.println("Shortname: " + shortName(str));
        System.out.println("hastagName: " + hashtagName(str));
        System.out.println("upper case all vowel: " + upperCaseAllVowel(str));
        System.out.println("upper case all N: " + upperCaseAllN(str));

    }
}