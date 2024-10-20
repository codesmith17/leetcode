class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> logicalExpression;
        stack<char> resultExpression;
        vector<char> logical = {'&', '|', '!'};

        for (auto it : expression) {
            if (find(logical.begin(), logical.end(), it) != logical.end()) {
                logicalExpression.push(it);
            } else if (it == '(' || it == 't' || it == 'f') {
                resultExpression.push(it);
            } else if (it == ',') {
                continue;
            } else if (it == ')') {
                char boolExpr = logicalExpression.top();
                logicalExpression.pop();

                stack<char> tempResult;
                while (resultExpression.top() != '(') {
                    tempResult.push(resultExpression.top());
                    resultExpression.pop();
                }
                resultExpression.pop();
                bool res;
                if (boolExpr == '&') {
                    res = true;
                    while (tempResult.size()) {
                        res &= (tempResult.top() != 'f');
                        tempResult.pop();
                    }
                } else if (boolExpr == '|') {
                    res = false;
                    while (tempResult.size()) {
                        res |= (tempResult.top() != 'f');
                        tempResult.pop();
                    }
                } else if (boolExpr == '!') {
                    while (tempResult.size()) {
                        res = (tempResult.top() == 'f');
                        tempResult.pop();
                    }
                }

                resultExpression.push(res ? 't' : 'f');
            }
        }

        return resultExpression.top() == 't';
    }
};
