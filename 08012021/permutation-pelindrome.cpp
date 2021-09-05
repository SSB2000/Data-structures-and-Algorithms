// Given a string, write a function to check if it is a permutation of a palin­
// drome. A palindrome is a word or  phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
using namespace std;

int main()
{
	bool isPalindrome = true;
	string ss = "cdbkxqnqtsqtqcuskbhwhcxjguhunaqytfgzfpxmimxpnubdrhnopplimtgascleyvpegdacvnpsnaaphktvoqodsnpjxmmdryjitrpveyqbjynhhgekukhbzknprpmxrhzxvgyucenmurehmkjyhtrhpuvloingdcsgvngfeanubjcctupmmtikihwxdmfedzlqnjeujfqfphjuwqgnygnkzvhvhppelztlwmvuisfcnbjudqdmxaaoydggaowltyrmlntecmkfpdencllzgvbmfnndsfmuhvgzqamiggxpcvltwijtodzyuuntzczfzgjrwpbqqxccgyajvtjfapkllgrsibyhlysjagbkigwkvlllvkohfisxrkilhblwybqrbdhadxowhedqcmuqldaehtrzywnhvzuurvcumqnbtkygcpvfxkseahownqdhoblktpyvmuvvajieuakfhurmdvivxzcabvnczinlkwizwsuuugyhlrcecjxorieikhwuxvuyvoktgxtsovnphkmhaalmdjtlpmsizogkeaypvwuxfewbuxpgjjcuzpkmitbbbzjbwjhjybzandgxynjfkihvjnjnigakjyaavgvtutuvoqamiiexmmkqvfjtkifvnziprmubtwwozpktbjqfiygwhssefppplgblrtvlsrihkawfcuvkbyzxmqeihoualjizvfrhscsbabdnwqsnuzettueqlweeacpgywdhvefoggdpwnzselbbihqlbdljknbniwgiclxburspmbuvxxzhwoivsbizjztywmvarqdysgpfqhmmenjcqznoigunpdvzhhmkfqxfsngbcpdppgvihelawdftqtaynhoidkugjfwfeunonihhtjuohwhxnwzihnwloxzehprqsmymwamaxvtqtwhihireyrtleijeaprcwydecqkmkfkdnqgevtiucfbjldjfltfhrkfkvrnktuuzqvjqmjl";

	// Most optimized
	// Bitset
	bitset<26> alp;
	for (char ch : ss)
	{
		alp.flip(ch - 'a');
	}
	cout << alp << '\n';
	if (alp.count() != 1 && alp.count() != 0)
		isPalindrome = false;
	// Other method to count if the bitset has only one bit
	// 	00010000  - 1 =  00001111
	// 00010000 & 00001111 =  0

	// Hash map
	/*
	map<int, int> freq;
	for (int i : ss)
		freq[i]++;
	int flag = 1;
	for (auto it : freq)
	{
		if (!(it.second % 2 == 0))
		{
			if (flag == 1)
			{
				flag--;
			}
			else
			{
				isPalindrome = false;
				break;
			}
		}
	}
	*/
	if (isPalindrome)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}