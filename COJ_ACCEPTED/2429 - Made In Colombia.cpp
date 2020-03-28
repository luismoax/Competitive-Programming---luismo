    #include <iostream>
    #include <cstdio>
    #include <vector>
    #include <cstring>
    #include <map>
    #include <algorithm>
    #include <cmath>
    #include <set>
    #include <queue>

    #define pf printf
    #define sf scanf

    #define INF 1000000

    /*
        Author: Luismo
        Problem: 2429 Made In Colombia
        Algorithm: Use 2 priority queues, one for the values lower or igual then the median FIRST, and the other for the
		greater values SECOND. With the invariant that the heap for lower values, alwasy has >= elements then the other
		The first heap is a Max-Build Heap, the second heap is a Min-Build Heap,
		in that way the first heap alwasy has the median value of the sorted collection.
		When adding elements i need to balance the size() difference between heaps
    */

    using namespace std;
    
	// comparator for the heap of min
    struct _comparator
    {
        bool operator ()(const long long& a,const long long& b) const
        {
            return a>b;
        }
    };

    int main()
    {
        int n=0;
        sf("%d%",&n);
        while(n !=0)
        {
            long long arr[n];
            double cnt=0; // saves the sum

            // heap for values to the right half of the middle (min heap)
            std::priority_queue<long long, vector<long long> ,_comparator> _heap_greater;
            // heap for values to the left half of the middle (max heap)
            std::priority_queue<long long> _heap_lower;

            // reading values
            for(int i=0;i<n;i++)
            {
                sf("%lld",&arr[i]);

				// if is the first element, push it into the first heap
                if(_heap_lower.empty() && _heap_greater.empty())
                {
                    _heap_lower.push(arr[i]);
                }
                else
                {
                    long long top = _heap_lower.top(); // value in the middle
					
					// if the new value is greater then the middle value
                    if(arr[i] > top)
                    {
						// if the second heap has less elements then the first
						// push into the second without problems
                        if(_heap_greater.size()< _heap_lower.size())
                            _heap_greater.push(arr[i]);
                        
						// else if has equal amount of elements
						// push into the second (disbalance), and then pop out the top 
						// of the second (balance) and push it into the first heap
						else
                        {
                            _heap_greater.push(arr[i]);
                            long long top2 = _heap_greater.top();
                            _heap_greater.pop();
                            _heap_lower.push(top2);
                        }
                    }
					// if the new value is lower the middle value
                    else if(arr[i] <=top)
                    {
						// if second heap has less elements then the first adding
						// into the first would violate my balance, so I pop out the
						// top and push it into the second, then push the value into the first
                        if(_heap_greater.size() < _heap_lower.size())
                        {
                            _heap_greater.push(top);
                            _heap_lower.pop();
                            _heap_lower.push(arr[i]);
                        }
						// no disbalance found
                        else
                        {
                            _heap_lower.push(arr[i]);
                        }
                    }
                }
				// adding the middle value
                cnt+=_heap_lower.top();
            }

            pf("%.2lf\n",cnt/n);

            sf("%d%",&n);
        }

    }
