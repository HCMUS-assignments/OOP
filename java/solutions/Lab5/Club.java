import java.lang.*;
import java.util.*;

public class Club {
    // attributes
    private String name;
    private int wins;
    private int draws;
    private int losses;

    // constructors
    public Club() {
        this("", 0, 0, 0);
    }

    public Club(String name, int wins, int draws, int losses) {
        this.name = name;
        this.wins = wins;
        this.draws = draws;
        this.losses = losses;
    }

    public Club(Club another) {
        this.name = another.name;
        this.wins = another.wins;
        this.draws = another.draws;
        this.losses = another.losses;
    }

    // methods
    public String getName() {
        return this.name;
    }

    public int getWins() {
        return this.wins;
    }

    public int getDraws() {
        return this.draws;
    }

    public int getLosses() {
        return this.losses;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setWins(int wins) {
        this.wins = wins;
    }

    public void setDraws(int draws) {
        this.draws = draws;
    }

    public void setLosses(int losses) {
        this.losses = losses;
    }

    public int numMatchesPlayed() {
        return this.wins + this.draws + this.losses;
    }
     
    public boolean isFinish() {
        if (numMatchesPlayed() == 10) {
            return true;
        }
        return false;
    }

    public int getPoints() {
        return this.wins * 3 + this.draws;
    }

    @Override
    public String toString() {
        return this.name + ": " + this.wins + "/" + this.draws + "/" + this.losses;
    }
}