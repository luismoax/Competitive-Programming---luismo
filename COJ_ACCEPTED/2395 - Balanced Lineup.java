import java.io.BufferedReader;
import java.io.*;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;



/**
 * Author: Luis Manuel Díaz Barón
 * Problem: 2395 Balanced LineUp
 * Online Judge:
 * Idea: Classic use of a SegmentTree (with minimun and maximun)
 *
 */


public class Main {

    static MyScanner sc;
    static MyWriter mw;
    static String filePath="d:\\lmo.in";

    public static void main(String[] args) throws IOException {
        sc = new MyScanner(System.in);
        
        mw = new MyWriter(System.out);

        //int tc=sc.nextInt();
        while(sc.canRead())
            SolveSingleProblem();

        mw.close();
    }

    public static void SolveSingleProblem() throws IOException{
        int n = sc.nextInt();
        int q = sc.nextInt();

        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        SegmentTree st = new SegmentTree(arr);

        // queries
        for (int i = 0; i < q; i++) {
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;

            mw.println( st.retrieveMax(a,b) - st.retrieveMinimun(a,b) );
        }

    }



}


class SegmentTree{
    SegmentTreeNode [] tree;
    int [] arr;
    int limit;

    int limit2;
    // query bounds
    int qLeft,qRight;
    public SegmentTree(int [] arr){
        // creates the tree
        this.arr =arr;
        this.tree = new SegmentTreeNode[4*arr.length];
        // instanciate root
        tree[0] = new SegmentTreeNode(0,arr.length - 1);

        this.limit = Integer.MAX_VALUE;

        this.limit2 = Integer.MIN_VALUE;
        buildTree(0);
    }

    void buildTree(int nodeIdx){
        SegmentTreeNode node = tree[nodeIdx];
        int idxL = leftChild(nodeIdx);
        int idxR = rightChild(nodeIdx);

        // if this is a leaf, left and right will be pointing at a valid index in arr
        if(node.left==node.right){
            node.min = arr[node.left];
            node.sum = arr[node.left];
            // mx
            node.max = arr[node.left];
            return;
        }

        // split the interval in the middle
        int mid = (node.left +node.right)/2;
        // instanciate both children
        tree[idxL] = new SegmentTreeNode(node.left,mid);
        tree[idxR] = new SegmentTreeNode(mid+1,node.right);

        // build both subtrees;
        buildTree(idxL);
        buildTree(idxR);

        // update the minimun value and sum for this interval
        node.sum = tree[idxL].sum +tree[idxR].sum;
        node.min = min(tree[idxL].min,tree[idxR].min);
        // updatting max
        node.max = max(tree[idxL].max,tree[idxR].max);
    }

    int retrieveMinimun(int qLeft,int qRight){
        // Setting query bounds
        this.qLeft = qLeft;
        this.qRight= qRight;
        return retrieveMinimun(0);
    }

    int retrieveMinimun(int nodeIdx){
        SegmentTreeNode node = tree[nodeIdx];
        // If this interval does not overlap with the query interval
        if(node.right< qLeft || node.left>qRight)
            return limit;

        // if this interval is within the query interval
        if(node.right<=qRight && node.left>=qLeft)
            return node.min;

        // else return the min value of both subtrees minimun
        return min(retrieveMinimun(leftChild(nodeIdx)) , retrieveMinimun(rightChild(nodeIdx)));
    }


    //--------------------

    int retrieveMax(int qLeft,int qRight){
        // Setting query bounds
        this.qLeft = qLeft;
        this.qRight= qRight;
        return retrieveMax(0);
    }

    int retrieveMax(int nodeIdx){
        SegmentTreeNode node = tree[nodeIdx];
        // If this interval does not overlap with the query interval
        if(node.right< qLeft || node.left>qRight)
            return limit2;

        // if this interval is within the query interval
        if(node.right<=qRight && node.left>=qLeft)
            return node.max;

        // else return the min value of both subtrees minimun
        return max(retrieveMax(leftChild(nodeIdx)) , retrieveMax(rightChild(nodeIdx)));
    }



    //----------------------




    int retrieveSum(int qLeft,int qRight){
        // Setting query bounds
        this.qLeft = qLeft;
        this.qRight= qRight;
        return retrieveSum(0);
    }

    int retrieveSum(int nodeIdx){
        SegmentTreeNode node = tree[nodeIdx];
        // If this interval does not overlap with the query interval
        if(node.right< qLeft || node.left>qRight)
            return limit;

        // if this interval is within the query interval
        if(node.right<=qRight && node.left>=qLeft)
            return node.sum;

        // else return the min value of both subtrees minimun
        int x1= retrieveSum(leftChild(nodeIdx));
        int x2 =retrieveSum(rightChild(nodeIdx));
        if(x1==limit)
            x1=0;
        if(x2==limit)
            x2=0;
        return x1+x2;
    }


    int rightChild(int idx){
        return idx*2 +2;
    }
    int leftChild(int idx){
        return idx*2+1;
    }
    int father(int idx){
        return (idx-1)/2;
    }
    int min(int a,int b){
        return (a<b)?a : b;
    }
    int max(int a,int b){
        return (a>b)?a : b;
    }
}


class SegmentTreeNode{
    public int sum,min,lazy,left,right,max;

    public SegmentTreeNode(int left,int right){
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        return String.format("[%d , %d] %d %d %d\n",left,right,sum,min, lazy);
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

    public void printArray(int[] arr){
        for(int i=0;i<arr.length;i++){

            if(i==0)
                println(arr[i]);
            else println(" "+arr[i]);

        }
    }


    public void printVector(Vector<Integer> arr){
        for(int i=0;i<arr.size();i++){

            if(i==0)
                print(arr.elementAt(i));
            else print(" " + arr.elementAt(i));

        }
    }

    public void printIntMatrix(int [][] mt){
        for(int i=0;i<mt.length;i++){
            for(int j=0;j<mt[0].length;j++){
                print(mt[i][j]+" ");
            }
            println("");
        }
        println("");
    }
    public void close() {
        pw.close();
    }

}