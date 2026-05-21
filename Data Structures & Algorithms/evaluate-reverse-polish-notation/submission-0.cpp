class Solution {
public:
// helper
    bool isOp(string s){ return s=="+" || s=="-" || s=="*" || s=="/"; }
    int evalRPN(vector<string>& tokens) {
        vector<int> res;
        for(int i=0;i<tokens.size();i++){
            if(!isOp(tokens[i])) res.push_back(stoi(tokens[i]));
            else{
                int a=res.back();
                res.pop_back();
                int b=res.back();
                res.pop_back();
                int c;
                switch(tokens[i][0]){
                    case '+': c=b+a;break;
                    case '-': c=b-a;break;
                    case '/': c=b/a;break;
                    case '*': c=b*a;break;
                }
                res.push_back(c);
            }
        }
        return res.back();
    }
};
