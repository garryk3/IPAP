// необходимо вычислить скользящее среднее
public class TaskCalculateMiddle {
    private int step;
    private double[] list;

    public TaskCalculateMiddle(int step, double[] list) {
        this.step = step;
        this.list = list;
    }

    public TaskCalculateMiddle() {
        this.step = 4;
        this.list = new double[]{1,3,4,5,6,9, 11, 3.3};
    }

    public void calculateWithStep (int customStep) {
        if(customStep > list.length) {
            System.out.print("cant calculate with step " + customStep + " and list length " + list.length);
            return;
        }

        double count = 0;
        int startIndex = list.length - customStep;

        for(int i = startIndex; i < list.length; i++) {
            count += list[i];
        }
        double middle = count/(list.length - startIndex);
        System.out.print("middle is: " + middle);
        System.out.println();
    }

    public void calculate () {
        calculateWithStep(step);
    }
}