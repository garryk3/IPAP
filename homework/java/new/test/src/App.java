import utils.InputUtils;

public class App {
    public static void main(String[] args) {
        startTaskCalcMiddle();
    }

    public static void startTaskCalcMiddle() {
        final InputUtils utils = new InputUtils();

        System.out.println("Enter step");
        int step = utils.readInt();
        System.out.println("Enter list");
        double[] list = utils.readDoubleArrayLine();

        new TaskCalculateMiddle(step, list).calculateWithStep(step);
    
        utils.close();
    }

}
