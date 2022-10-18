using System;
using System.Collections.Generic;

public class Planktonfarm {
    public static void Main(string[] args) {
        int a, b;
        a = Convert.ToInt32(Console.ReadLine());
        b = Convert.ToInt32(Console.ReadLine());
        List<string> s = new List<string>(Console.ReadLine().Split(' '));
        List<int> c = s.ConvertAll(int.Parse);
        c.Sort();
        int p1 = 0, p2 = b-1, ans = 0;
        while (p1 < p2) {
            if (c[p1] * c[p2] < a) {
                p1 += 1;
            } 
            else {
                p1 += 1;
                p2 -= 1;
                ans += 1;
            }
        }
        Console.WriteLine(ans);
    }
}
