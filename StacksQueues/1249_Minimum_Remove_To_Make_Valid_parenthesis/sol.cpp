class Solution {
public:
	string minRemoveToMakeValid(string s) {
		stack<unsigned> parenthesesIndexStack;
		for (size_t i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				parenthesesIndexStack.push(i);
			} else if (s[i] == ')') {
				if (!parenthesesIndexStack.empty() && s[parenthesesIndexStack.top()] == '(')
					parenthesesIndexStack.pop();
				else
					parenthesesIndexStack.push(i);
			}
		}

		while (!parenthesesIndexStack.empty()) {
			s.erase(parenthesesIndexStack.top(), 1);
			parenthesesIndexStack.pop();
		}

		return s;
	}
};
