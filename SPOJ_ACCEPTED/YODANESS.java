import java.io.BufferedReader;
import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;
 
 
/**
 * Author: Luis Manuel Díaz Barón
 * Problem: YODANESS
 * Online Judge: SPOJ
 * Idea: Use a Binary Indexed Tree
 *
 */
 
 
public class Main {
 
    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";
    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        //sc = new MyScanner(new FileReader(filePath));
        mw = new MyWriter(System.out);
 
        int tc=sc.nextInt();
        while(tc-->0)
            SolveSingleProblem();
 
        mw.close();
    }
 
    public static void SolveSingleProblem() throws IOException{
        int n = sc.nextInt();
        HashMap<String,Integer> map1 = new HashMap<String, Integer>();
        // Reading data and saving it into map
        for(int i=0;i<n;i++){
            String s = sc.next();
            map1.put(s,i+1);
        }
 
        FenwickTree ft = new FenwickTree(n);
        long inversions = 0;
        for (int i=0;i<n;i++){
            String s = sc.next();
            int idx = map1.get(s);
            ft.update(idx,1);
            int k=  (idx-1) - ft.retrieve(idx-1);
            inversions+=k;
 
        }
        mw.println(inversions);
 
    }
}
 
 
 
class FenwickTree{
    int [] tree;
 
    public FenwickTree(int n){
        this.tree = new int[n+1];
    }
 
    public void update(int idx,int v){
        for(int i=idx;i<tree.length;i+=lowBit(i))
            tree[i]+=v;
    }
 
    public int retrieve(int idx){
        int sum=0;
        for(int i=idx;i>0;i-=lowBit(i))
            sum+=tree[i];
        return sum;
    }
 
    int lowBit(int idx){
        return idx&-idx;
    }
}
 
 
class MyScanner{
    BufferedReader br;
    StringTokenizer stk;
    public MyScanner(InputStream stream){
        this.br = new BufferedReader(new InputStreamReader(stream),72357);
        this.stk = new StringTokenizer("");
    }
 
    public MyScanner(FileReader fr){
        this.br = new BufferedReader(fr);
        this.stk = new StringTokenizer("");
    }
 
    public String next() throws IOException {
        while(!stk.hasMoreElements()){
            String line = br.readLine();
            if(line == null)
                return null;
            stk = new StringTokenizer(line);
        }
        return stk.nextToken();
    }
 
    public int nextInt()throws IOException{
        return Integer.parseInt(next());
    }
 
    public long nextLong() throws IOException{
        return Long.parseLong(next());
    }
 
    public double nextDouble() throws IOException{
        return Double.parseDouble(next());
    }
 
    public boolean canRead() throws IOException{
        return br.ready();
    }
 
    public int [] nextIntArray(int n) throws IOException{
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = nextInt();
        return arr;
    }
 
    public long [] nextLongArray(int n) throws IOException{
        long arr[] = new long[n];
        for(int i=0;i<n;i++)
            arr[i] = nextInt();
        return arr;
    }
}
 
class MyWriter{
 
    PrintWriter pw;
    public MyWriter(OutputStream out){
        this.pw = new PrintWriter(out);
    }
 
    public void print(Object obj){
        pw.print(obj.toString());
    }
 
    public void println(Object obj){
        pw.println(obj.toString());
    }
 
    public void printArray(Object... arr){
        for(int i=0;i<arr.length;i++){
            if(arr[i]!=null){
                if(i==0)
                    println(arr[i].toString());
                else println(" "+arr[i].toString());
            }
        }
    }
    public void close() {
        pw.close();
    }
 
} 