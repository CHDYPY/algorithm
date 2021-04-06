#include<iostream>
#include<vector>
#include <iomanip>

using namespace std;

string s1 = "intention";
string s2 = "execution";

vector< vector<int> > dp(s1.size()+1, vector<int>(s2.size()+1, 0));

int min(int x,int y,int z) {
    if (x < y) {
        return x < z ? x : z;
    }
    else {
        return y < z ? y : z;
    }
}

void setdp() {
	
	for(int i = 0; i<s1.size(); i++) {
		dp[i][0] = i;
	}
	for(int i = 0; i<s2.size(); i++) {
		dp[0][i] = i;
	}
	for(int i = 1; i<=s1.size(); i++) {
		for(int j = 1; j<=s2.size(); j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j-1]+1, dp[i-1][j]+1);
			}
		}
	}
}

void display() {
	for(int i = 0; i<=s1.size(); i++) {
		for(int j = 0; j<=s2.size(); j++) {
			cout <<std::right<<setw(2) << dp[i][j] << " ";
		} 
		cout << endl;
	}
} 

int main() {
	setdp();
	cout << dp[s1.size()][s2.size()];
	return 0;
}
