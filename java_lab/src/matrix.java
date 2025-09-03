//Q. wap to multiply 2 matrices

import java.util.Scanner;

public class matrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // input first matrix
        System.out.print("Enter no. of rows for 1st matrix: ");
        int rowsFirst = sc.nextInt();
        System.out.print("Enter no. of columns for 1st matrix: ");
        int colsFirst = sc.nextInt();
        int[][] firstMatrix = new int[rowsFirst][colsFirst];

        System.out.println("Enter elements of 1st matrix:");
        for (int i = 0; i < rowsFirst; i++) {
            for (int j = 0; j < colsFirst; j++) {
                firstMatrix[i][j] = sc.nextInt();
            }
        }

        // input second matrix
        System.out.print("Enter no. of rows for 2nd matrix: ");
        int rowsSecond = sc.nextInt();
        System.out.print("Enter no. of columns for 2nd matrix: ");
        int colsSecond = sc.nextInt();
        int[][] secondMatrix = new int[rowsSecond][colsSecond];

        System.out.println("Enter elements of 2nd matrix:");
        for (int i = 0; i < rowsSecond; i++) {
            for (int j = 0; j < colsSecond; j++) {
                secondMatrix[i][j] = sc.nextInt();
            }
        }

        // Check m = n
        if (colsFirst != rowsSecond) {
            System.out.println("Matrix multiplication is not possible.");
            return;
        }

        // Resultant matrix
        int[][] resultMatrix = new int[rowsFirst][colsSecond];

        // Multiply matrices
        for (int i = 0; i < rowsFirst; i++) {
            for (int j = 0; j < colsSecond; j++) {
                for (int k = 0; k < colsFirst; k++) {
                    resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
                }
            }
        }

        System.out.println("Resultant Matrix:");
        for (int i = 0; i < rowsFirst; i++) {
            for (int j = 0; j < colsSecond; j++) {
                System.out.print(resultMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
