public class TestClub {
    public static void main(String[] args) {
        Club firstClub = new Club("OOP", 3,0,1);
        Club secondClub = new Club(firstClub);
        secondClub.setName("DSA");
        secondClub.setWins(5);
        secondClub.setDraws(3);
        secondClub.setLosses(2);
        System.out.println(firstClub);
        System.out.println(secondClub);

        System.out.println("First club | matches played: " + firstClub.numMatchesPlayed());
        System.out.println("Second club | matches played: " + secondClub.numMatchesPlayed());
        
        System.out.println("first club | is finish: " + firstClub.isFinish());
        System.out.println("second club | is finish: " + secondClub.isFinish());

        System.out.println("first club | points : " + firstClub.getPoints());
        System.out.println("second club | points : " + secondClub.getPoints());
    }
}