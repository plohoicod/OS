import java.io.*;
import java.lang.reflect.Array;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.lang.Math;
import java.io.FileNotFoundException;

import static java.lang.StrictMath.sqrt;

class DFS {
    static int used[] = new int[1000];
    static int a[][] = new int[1000][1000];
    static int ax[][] = new int[1000][1000];
    static int o[] = new int[1000];
    static int o1 = 0;
    static int n;
    static void dfs(int v) {
        int i;
        used[v] = 1;
        for (i = 0; i < n; i++)
            if (a[v][i] == 1 && used[i] == 0)
                dfs(i);
        o[o1] = v;
        o1++;
    }
    static void dfs2(int v) {
        int i;
        used[v] = 1;
        for (i = 0; i < n; i++)
            if (ax[v][i] == 1 && used[i] == 0)
                dfs(i);
    }
    public static int findcomps() {
        int ans = 0;
        for (int i = 0; i < n; i++)
            used[i] = 0;
        for (int i = 0; i < n; i++)
            if (used[i] == 0) {
                dfs(i);
            }

        for (int i = 0; i < n; i++)
            used[i] = 0;
        for (int i = 0; i < n; i++) {
            int z = o[n - 1 - i];
            if (used[z] == 0) {
                dfs(z);
                ans++;
            }
        }
        //System.out.print(ans);
        return ans;
    }
    public static int begin(int n1, int a3[][], int a3x[][]) {
        a = a3;
        ax = a;
        n = n1;
        int ans;
        ans = findcomps();
        return ans;
    }



}

class DFS2 {
    static int used[] = new int[1000];
    static int a[][] = new int[1000][1000];
    static int n;
    public static int[] begin(int n1, int a3[][], int init) {
        a = a3;
        n = n1;
        dfs(init);
        return used;
    }
    static void dfs(int v) {
        int i;
        used[v] = 1;
        for (i = 0; i < n; i++)
            if (a[v][i] == 1 && used[i] == 0)
                dfs(i);
    }

}

public class FSA{
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new BufferedReader(new FileReader("fsa.txt"))).useLocale(Locale.US);
        PrintWriter out = new PrintWriter(new FileWriter("result.txt"));
        String s = scan.nextLine();
        String a1[] = new String[1000];
        int n1 = 0;
        int z = 8;
        int cc = 0;
        for(int i = 8; i < s.length(); i++) {
            if(s.charAt(i) == ',') {
                a1[n1] = s.substring(z, i);
                n1++;
                z = i + 1;
                cc++;
            }
            if(s.charAt(i) == '}') {
                a1[n1] = s.substring(z, i);
                n1++;
            }
        }
        if(cc != n1 - 1) {
            out.println("Error:");
            out.print("E5: Input file if malformed");
            out.close();
            return;
        }
        String a2[] = new String[1000];
        int n2 = 0;
        z = 7;
        s = scan.nextLine();
        cc = 0;
        for(int i = 8; i < s.length(); i++) {
            if(s.charAt(i) == ',') {
                a2[n2] = s.substring(z, i);
                n2++;
                z = i + 1;
                cc++;
            }
            if(s.charAt(i) == '}') {
                a2[n2] = s.substring(z, i);
                n2++;
            }
        }
        if(cc != n2 - 1) {
            out.println("Error:");
            out.print("E5: Input file if malformed");
            out.close();
            return;
        }
        s = scan.nextLine();
        String init;
        init = s.substring(9, s.length() - 1);
        for(int i = 0; i <= n1; i++) {
            if(i == n1) {
                out.println("Error:");
                out.print("E1: A state '" + init + "' is not in set of states");
                out.close();
                return;
            }
            if(a1[i].equals(init)) {
                break;
            }
        }
        s = scan.nextLine();
        String fin;
        fin = s.substring(8, s.length() - 1);
        int a3[][] = new int[n1][n1];
        int a3x[][] = new int[n1][n1];
        s = scan.nextLine();
        z = 7;
        String in ="", tr ="", op ="";
        int q = 0;
        ArrayList a4[] = new ArrayList[n1];
        for(int i = 0; i < n1; i++) {
                a4[i] = new ArrayList();
        }
        for(int i = 7; i < s.length(); i++) {
            if(s.charAt(i) == ',' || s.charAt(i) == '}') {

                op = s.substring(z, i);
                z = i + 1;
                //out.println(in + " " + tr + " " + op);

                for(int j = 0; j <= n2; j++) {
                    if(j == n2) {
                        out.println("Error:");
                        out.print("E3: A transition '" + tr +  "' is not represented in the alphabet");
                        out.close();
                        return;
                    }
                    if(a2[j].equals(tr)) {
                        break;
                    }
                }

                int a = 0, b = 0;
                for(int j = 0; j < n1; j++) {
                    if(in.equals(a1[j]))
                        a = j;
                }
                for(int j = 0; j < n1; j++) {
                    if(op.equals(a1[j]))
                        b = j;
                }

                a3[a][b] = 1;
                a3x[b][a] = 1;
                a4[a].add(tr);
            }
            if(s.charAt(i) == '>' && q == 0) {
                in = s.substring(z, i);
                z = i + 1;
                q = 1;
                continue;
            }
            if(s.charAt(i) == '>' && q == 1) {
                tr = s.substring(z, i);
                z = i + 1;
                q = 0;
            }
        }

        DFS k = new DFS();
        int r = k.begin(n1, a3, a3x);
        if(r != 1) {
            out.println("Error:");
            out.print("E2: Some states are disjoint");
            out.close();
            return;
        }


        if(init.equals("")) {
            out.println("Error:");
            out.print("E4: Initial state is not defined");
            out.close();
            return;
        }

        for(int i = 0; i <= n1; i++) {
            if(i == n1) {
                out.print("FSA is complete");
                break;
            }
            for(int f = 0; f < n2; f++) {
                int l = 0;
                for(l = 0; l < a4[i].size(); l++) {
                    if(a2[f].equals(a4[i].get(l)))
                        break;
                }
                if(l == a4[i].size()) {
                    out.print("FSA is incomplete");
                    i = n1 + 1;
                    break;

                }

            }
        }


        boolean w = false;
        if(fin.equals("")) {
            w = true;
            out.println();
            out.println("Warning:");
            out.print("W1: Accepting state is not defined");
        }
        int initt = 0;
        for(int i = 0; i < n1; i++) {
            if(a1[i].equals(init)) {
                initt = i;
            }
        }
        DFS2 k1 = new DFS2();
        int ans2[] = k1.begin(n1, a3, initt);
        for(int i = 0; i < n1; i++) {
            if(ans2[i] == 0) {
                if(w == false) {
                    out.println();
                    out.println("Warning:");
                    out.print("W2: Some states are not reachable from initial state");
                    w = true;
                    break;
                }
                else {
                    out.println();
                    out.print("W2: Some states are not reachable from initial state");
                    break;
                }
            }
        }

        out.close();
    }
}