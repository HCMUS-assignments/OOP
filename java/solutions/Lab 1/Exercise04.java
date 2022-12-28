// Write a function to convert the temperature from Fahrenheit to Celsius and a function to 
// convert the temperature from Celsius to Fahrenheit

import java.util.Scanner;

public class Exercise04 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the temperature in Fahrenheit: ");
        double fahrenheit = input.nextDouble();
        System.out.println("The temperature in Celsius is " + convertFahrenheitToCelsius(fahrenheit));
        System.out.println("Enter the temperature in Celsius: ");
        double celsius = input.nextDouble();
        System.out.println("The temperature in Fahrenheit is " + convertCelsiusToFahrenheit(celsius));
    }
    
    public static double convertFahrenheitToCelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }
    
    public static double convertCelsiusToFahrenheit(double celsius) {
        return celsius * 9 / 5 + 32;
    }
}