#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		stack< char, vector<char> > iStack;
		string x;
		cin >> x;
		int cnt = 0;
		for (int i = 0; i < (int) x.size(); i++) {
			if (x[i] == '(' || x[i] == '{' || x[i] == '[') {
				cnt++;
				iStack.push(x[i]);
			} else {
				if (iStack.empty()) {
					break;
				}
				if (x[i] == ')') {
					if (iStack.top() == '(') {
						cnt++;
						iStack.pop();
					}
				} else if (x[i] == '}') {
					if (iStack.top() == '{') {
						cnt++;
						iStack.pop();
					}
				} else if (x[i] == ']') {
					if (iStack.top() == '[') {
						cnt++;
						iStack.pop();
					}
				}
			}
		}
		cout << (iStack.empty() && cnt == (int) x.size()? "YES" : "NO") << '\n';
	}
	return 0;
}
