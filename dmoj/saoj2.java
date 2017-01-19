import java.io.*;
import java.util.*;
import java.math.*;

public class saoj2{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        BigInteger x = new BigInteger(sc.nextLine());
        BigInteger y = x.multiply(x.add(new BigInteger("1"))).divide(new BigInteger("2"));
        System.out.println(y);
    }
}
