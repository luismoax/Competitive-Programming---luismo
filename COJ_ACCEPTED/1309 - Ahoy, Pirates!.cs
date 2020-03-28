using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;


namespace CompetitiveProgramming
{
    /*
     * Author: Luis Manuel Díaz Barón
     * Problem: 1309 - Ahoy, Pirates!
     * Online Judge: COJ
     * Idea: Use a Segment Tree with Lazy updates, as the problem describes 3 diferent types of update
	 * use a list in each node to store all lazy updates over it. Once we need to update the value
	 * of a node, we apply every type of update on the list in the order they were made, and finally clear the list.	 
     * 
     * */

    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = Console.In;
            TextWriter tw = Console.Out;

            // Console.SetIn(new StreamReader(@"d:\lmo.in"));

            SolveSingleProblem();

            Console.SetIn(tr);
            Console.SetOut(tw);
            Console.ReadLine();
        }

        static void SolveSingleProblem()
        {
            int TC = int.Parse(Console.ReadLine());

            for (int tc = 0; tc < TC; tc++)
            {
                Console.WriteLine("Case {0}:",tc+1);

                int m = int.Parse(Console.ReadLine());
                // foreach pair
                string piratesLine = "";
                for (int i = 0; i < m; i++)
                {
                    int t = int.Parse(Console.ReadLine());

                    string s = Console.ReadLine();

                    for (int k = 0; k < t; k++)
                    {
                        piratesLine += s;
                    }
                }
				
				// build the Segment Tree
                SegmentTree st = new SegmentTree(piratesLine);
				
                int Q = int.Parse(Console.ReadLine());
                // foreach query
                int qCnt = 1;
                for (int q = 0; q < Q; q++)
                {
                    string[] data = Console.ReadLine().Split(new char[] { ' ' });

                    string query = data[0];
                    int a = int.Parse(data[1]);
                    int b = int.Parse(data[2]);

                    // setting the query bounds
                    st.SetQueryBounds(a, b);

                    if (query == "I")
                        st.Update(0, 1);
                    else if (query == "F")
                        st.Update(0, 2);
                    else if (query == "E")
                        st.Update(0, 3);
					// print answer
                    else Console.WriteLine( "Q{0}: {1}",qCnt++, st.Retrieve(0));
                }   
            }
        }
    }

    class Node
    {
        public int L, R;
        public int Buc, Barb, val;
        public List<int> Lazy;        
        // 1 invert
        // 2 mutate to buccannerr
        // 3 mutate to barbarian
        public Node(int L, int R)
        {
            this.L = L;
            this.R = R;
            Lazy = new List<int>(); // lazy updates
        }

        public override string ToString()
        {
            return string.Format("[{0},{1}] Buc:{2} Barb:{3}", L, R, Buc, Barb);
        }
    }

    class SegmentTree
    {
        Node[] tree;
        string arr;
        int QL, QR;

        public SegmentTree(string arr)
        {
            tree = new Node[4 * arr.Length];
            this.arr = arr;

            BuildTree(0, 0, arr.Length - 1);
        }
		// LEFT SON
        int LS(int idx)
        {
            return (idx << 1) + 1;
        }
		// RIGHT SON
        int RS(int idx)
        {
            return (idx << 1) + 2;
        }

        // PROPAGATE
        void Propagate(int idx)
        {
            Node node = tree[idx];

            #region Download

            for (int i = 0; i < node.Lazy.Count; i++)
            {
                int k = node.Lazy[i];
                // invert Pirates
                if (k == 1)
                {
                    int aux = node.Barb;
                    node.Barb = node.Buc; node.Buc = aux;
                }
                // all to bucanner
                else if (k == 2)
                {
                    node.Buc = node.R - node.L + 1;
                    node.Barb = 0;
                }
                // all to barbarian
                else
                {
                    node.Barb = node.R - node.L + 1;
                    node.Buc = 0;
                }
            }

            #endregion

            // if not leaf
            if (node.L != node.R)
            {
                //
                for (int i = 0; i < node.Lazy.Count; i++)
                {
                    tree[LS(idx)].Lazy.Add(node.Lazy[i]);

                    tree[RS(idx)].Lazy.Add(node.Lazy[i]);
                }
            }
            // clear lazy
            node.Lazy.Clear();
        }

        // BUILD TREE
        public void BuildTree(int idx, int L, int R)
        {            
            tree[idx] = new Node(L, R);
            Node node  = tree[idx];
            // if leaf
            if (L == R)
            {
                node.val = int.Parse(arr[L].ToString() );

                if (node.val == 1)
                    node.Buc++;
                else node.Barb++;
                return;
            }

            int mid = (L + R) >> 1;

            BuildTree(LS(idx), L, mid);

            BuildTree(RS(idx), mid + 1, R);

            // updating values
            node.Barb = tree[LS(idx)].Barb + tree[RS(idx)].Barb;
            node.Buc = tree[LS(idx)].Buc + tree[RS(idx)].Buc;
        }

        // SET QUERY BOUNDS
        public void SetQueryBounds(int QL, int QR)
        {
            this.QL = QL; this.QR = QR;
        }
		// UPDATE
        public void Update(int idx, int upd)
        {
            // propagate
            Propagate(idx);
			// current node
            Node node = tree[idx];

            // if outside
            if (node.L > QR || node.R < QL)
                return;

            // if inside
            if (node.L >= QL && node.R <= QR)
            {
                #region UpdateCurrent
                if (upd == 1)
                {
                    int aux = node.Barb;
                    node.Barb = node.Buc; node.Buc = aux;
                }
                // all to bucanner
                else if (upd == 2)
                {
                    node.Buc = node.R - node.L + 1;
                    node.Barb = 0;
                }
                // all to barbarian
                else
                {
                    node.Barb = node.R - node.L + 1;
                    node.Buc = 0;
                }
                #endregion

                // propagate if not leaf
                if (node.L != node.R)
                {
                    tree[LS(idx)].Lazy.Add(upd);
                    tree[RS(idx)].Lazy.Add(upd);
                }
                return;
            }
            // update both kids
            Update(LS(idx), upd);
            Update(RS(idx), upd);

            // update current node
            node.Barb = tree[LS(idx)].Barb + tree[RS(idx)].Barb;
            node.Buc = tree[LS(idx)].Buc + tree[RS(idx)].Buc;
        }

        // RETRIEVE Buccaners
        public int Retrieve(int idx)
        {
            // propagate
            Propagate(idx);

            Node node = tree[idx];

            // if outside
            if (node.L > QR || node.R < QL)
                return 0;

            // if inside
            if (node.L >= QL && node.R <= QR)
            {
                return node.Buc;
            }

            return Retrieve(LS(idx)) + Retrieve(RS(idx));
        }
    }

}
