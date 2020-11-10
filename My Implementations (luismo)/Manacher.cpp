struct Manacher
{
    string s;
    int lenMan;
    char * man;
    int * table;

    // Const
    Manacher(string ss)
    {
        s = ss;
        lenMan = s.size() * 2 + 2;
        man = new char[lenMan];
        table = new int[lenMan];
        // fill the manacher
        preProcess();
    }

    // mirror for index "idx" at center "center"
    int mirror(int idx, int center)
    { return (center - (idx - center)); }

    void manFill()
    {
        man[0] = '$';
        man[1] = '#';
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            man[2*i+2] = c;
            man[2*i+3] = '#';
        }
    }

    void preProcess()
    {
        // fill the manacher string
        manFill();
        // set intial values for the table
        table[0] = table[1] = 0;
        table[2] = 1;
        // set the center and its wing
        int center = 2;

        // for each character
        for(int i = 3; i < lenMan; i++)
        {
            int currWing = 0;
            // if can be calculated from its mirror
            if(i <= center + table[center])
            {
                int mirr = mirror(i, center);
                currWing = min(table[mirr], center + table[center] - i);
            }
            // update the value of the table
            table[i] = currWing;
            // while being possible to increase the lengt
            while(i + table[i] < lenMan && man[i+table[i]+1] == man[i-(table[i]+1)])
                table[i]++;
            // update the center
            if(i + (table[i]) > center + table[center])
                center = i;
        }
    }

	bool isPalindrome(int le, int ri)
	{
		int idxLe = le * 2 + 2;
		int idxRi = ri * 2 + 2;

		int mid = (idxLe + idxRi) / 2;

		int wing = table[mid];

		if(wing / 2 >= (ri - le + 1) / 2)
			return true;

		return false;
	}
};