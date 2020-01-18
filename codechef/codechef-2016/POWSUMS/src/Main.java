
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author Jatin
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // java.io.BufferedReader r = new java.io.BufferedReader (new java.io.InputStreamReader (System.in));
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int n, q, b1;
        BigInteger temp, res, pow;
        BigInteger func = BigInteger.valueOf(2L);
        BigInteger carry = BigInteger.valueOf(2L);
        BigInteger modvalue = BigInteger.valueOf(123456789L);
        for (int i = 1; i <= t; ++i) {
            n = sc.nextInt();
            q = sc.nextInt();
            BigInteger[] a = new BigInteger[n];
            for (int j = 0; j < n; ++j) {
                a[j] = sc.nextBigInteger();
                temp = a[j];
                // do some calculation to find the function
            }
            for (int j = 1; j <= q; ++j) {
                b1 = sc.nextInt();
                res = func.pow(b1);
                res = res.add(carry);
                res = res.mod(modvalue);
                System.out.print(res + " ");
            }
            System.out.println("");
        }
    }

}
