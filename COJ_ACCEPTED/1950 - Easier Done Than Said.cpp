#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool IsVowel(char c)
{
    if(c=='a' || c=='e'|| c=='o'|| c=='i'|| c=='u')
    return true;
    return false;
}

bool TreeVnV(char c1,char c2,char c3){
		if(IsVowel(c1)&& IsVowel(c2) && IsVowel(c3))
			return true;
		if(!IsVowel(c1)&& !IsVowel(c2) && !IsVowel(c3))
			return true;
		return false;
	}

int main()
{
    char s [10001];
    scanf("%s",s);
    while(true)
    {
        if(strlen(s)==3 &&(s[0] == 'e' && s[1] == 'n' && s[2] == 'd'))
            break;

        bool fucked = true;
        for(int i =0;i<strlen(s);i++)
        {
            if(IsVowel(s[i]))
                fucked = false;
            if(i>=1 && s[i]==s[i-1] && s[i]!='e' && s[i]!= 'o')
            {
                fucked = true;
				break;
            }
            if(i>=2 && TreeVnV(s[i], s[i-1], s[i-2]))
            {
                fucked = true;
				break;
			}
        }
        if(fucked)
            printf("<%s> is not acceptable.\n", s);
		else printf("<%s> is acceptable.\n", s);
        scanf("%s",s);
    }
}
