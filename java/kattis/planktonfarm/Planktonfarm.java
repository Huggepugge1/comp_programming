import java.util.*;
import java.io.*;

class Planktonfarm {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int[] c = new int[b];
        
        for (int i = 0; i < b; i++) {
            int curr = sc.nextInt();
            c[i] = curr;
        }
        
        Arrays.sort(c);

        int p1=0, p2=b-1, ans=0;
        while (p1 < p2) {
            if (c[p1] * c[p2] >= a) {
                p2--;
                ans++;
            }
            p1++;
        }
        System.out.println(ans);
    }
}
