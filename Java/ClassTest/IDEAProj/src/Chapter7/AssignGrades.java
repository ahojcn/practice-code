package Chapter7;
/*
 * 7.1
 */
import java.util.Scanner;

public class AssignGrades {
    public static char get(int score, int best) {
        int a = best - score;
        if (a <= 10) {
            return 'A';
        } else if (a <= 20) {
            return 'B';
        } else if (a <= 30) {
            return 'C';
        } else if (a <= 40) {
            return 'D';
        } else {
            return 'F';
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = sc.nextInt();
        int[] scores = new int[n];
        int best = 0;
        System.out.printf("Enter %d scores: ", n);
        for (int i = 0; i < n; i++) {
            scores[i] = sc.nextInt();
            if (scores[i] > best) {
                best = scores[i];
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.printf("Student %d is %d and grade is %c.\n", i, scores[i], get(scores[i], best));
        }

    }
}
