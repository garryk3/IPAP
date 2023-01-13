package v1;

import v1.application.Application;

public class App {
    private static Application app = new Application();
    public static void main(String[] args) {
        app.run();
    }
}
