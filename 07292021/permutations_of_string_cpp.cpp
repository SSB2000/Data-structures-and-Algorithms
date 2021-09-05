#include <iostream>
#include <string>
using namespace std;
void permutations (std::string str, std::string prefix) {
	if (str.length() == 0) {
		std::cout<<prefix<<'\n';
		return;
	}

	for (int i = 0; i < str.length(); i++) {
		string rem = str.substr(0, i) + str.substr(i + 1);
		permutations(rem, prefix + str[i]);	
	}
}

int main() {
	permutations("abcd", "");
}