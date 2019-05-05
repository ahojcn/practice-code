package Chapter8;

import java.util.*;

/*
 * 8.3
 */
public class SortStudentOnGrades {
    public static void main(String[] args) {
        char[][] answers = {
                {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
                {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
                {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
                {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
                {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
                {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
                {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
                {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}};
        char[] keys = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};

        Map<String, Integer> tree = new TreeMap<>();

        for (int i = 0; i < answers.length; i++) {
            int cnt = 0;
            for (int j = 0; j < answers[i].length; j++) {
                if (answers[i][j] == keys[j]) {
                    cnt++;
                }
            }
            tree.put("Student" + i, cnt);
        }

        System.out.println(tree);

        List<Map.Entry<String, Integer>> treeList = new ArrayList<>(tree.entrySet());
        treeList.sort(Comparator.comparing(Map.Entry::getValue));

        System.out.println(treeList);
    }
}
