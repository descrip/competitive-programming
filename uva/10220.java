import java.math.*;
import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        BigInteger A = new BigInteger("1");
        int[] ans = new int[1001];
        ans[0] = ans[1] = 1;
        for (int i = 2; i <= 1000; ++i) {
            A = A.multiply(new BigInteger(Integer.toString(i)));
            String S = A.toString();
            for (int j = 0; j < S.length(); ++j)
                ans[i] += S.charAt(j) - '0';
        }
        while (sc.hasNextInt())
            System.out.println(ans[sc.nextInt()]);
        sc.close();
    }
}
