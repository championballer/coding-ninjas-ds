#include <iostream>
#include <string>
using namespace std;

void swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void printPermutations2(string s, int i, int n)
{
    int j;
    if (i == n)
        cout << s << endl;
    else
    {
        for (j = i; j < s.length(); j++)
        {
            swap(s[i],s[j]);
            printPermutations2(s, i + 1, n);
            swap(s[i],s[j]);
        }  
    }
}
void printPermutations(string input){

    /* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	printPermutations2(input, 0, input.length() - 1);
	
}
