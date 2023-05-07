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

    // part 2
    public static int countWord(String paragraph) {
        // count the number of words
        String temp = new String(paragraph);
        temp.replaceAll("[,.]", "");
        String[] words = temp.split(" ");
        return words.length;
    }

    public static int countSentences(String paragraph) {
        // count the number of sentences
        String[] sentences = paragraph.split("\\.");
        return sentences.length;

    }

    public static int countAppear(String paragraph, String word) {
        // count the number of occurrences of the word in the paragraph
        String temp = new String(paragraph);
        temp.replaceAll("[,.]", "");
        String[] words = temp.split(" ");

        Map<String, Integer> counts = new HashMap<String, Integer>();
        for (int i = 0; i < words.length; i++) {
            counts.compute(words[i], (k,v) -> v == null ? 1 : v + 1);
        }
        return counts.get(word);
    }


    public static void main(String [] args) {
        String str = "Nguyen Le Trong Tin";
        System.out.println("Shortname: " + shortName(str));
        System.out.println("hastagName: " + hashtagName(str));
        System.out.println("upper case all vowel: " + upperCaseAllVowel(str));
        System.out.println("upper case all N: " + upperCaseAllN(str));

        System.out.println("Part 2: ");
        String paragraph = "The Edge Surf is of course also a whole lot better, which will hopefully win Microsoft some converts. It offers time trial, support for other input methods like touch and gamepads, accessibility improvements, high scores, and remastered visuals.";
        System.out.println("The number of words : " + countWord(paragraph));
        System.out.println("The number of sentences : " + countSentences(paragraph));
        System.out.println("The number of occurrences \"and\" : " + countAppear(paragraph, "and"));

    }
}