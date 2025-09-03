interface sports {
    void play();
    void showRules();
}

class Cricket implements sports {
    public void play() {
        System.out.println("Playing Cricket...");
    }

    public void showRules() {
        System.out.println("Cricket Rules:\n- Each team has 11 players\n- Match is divided into overs\n- Batsman tries to score runs");
    }
}

class Football implements sports {
    public void play() {
        System.out.println("Playing Football...");
    }

    public void showRules() {
        System.out.println("Football Rules:\n- Each team has 11 players\n- Game lasts 90 minutes\n- Players try to score goals");
    }
}

public class SportsDemo {
    public static void main(String[] args) {
        sports cricket = new Cricket();
        sports football = new Football();

        System.out.println("Cricket:");
        cricket.play();
        cricket.showRules();

        System.out.println("\nFootball:");
        football.play();
        football.showRules();
    }
}
