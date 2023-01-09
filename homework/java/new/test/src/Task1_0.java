import java.util.Scanner;

public class Task1_0 {
    public static void complete() {
        //пользователь воодит 2 числа, нужно вывести остаток от деления большего на меньшее
        System.out.println("Enter two positive numbers");
        Scanner sc = new Scanner(System.in);
        int num1;
        int num2;
        num1 = sc.nextInt();
        num2 = sc.nextInt();
        sc.close();
        if(num1 > 0 && num2 > 0)  {
            int diff = num1 > num2 ? num1 % num2 : num2 % num1;
            System.out.println("diff " + diff);
        }
    }
}
