bool isSame(char open, char close){
    if((open == '[' && close == ']') || (open == '{' && close == '}') || (open == '(' && close == ')'))
        return true;
    return false;
}

int Solution::solve(string A) {
    stack<char> s;
    int i = 0;
    while(A[i] != '\0'){
        if( (A[i] == '[') || (A[i] == '{') || (A[i] == '(') )
            s.push(A[i]);
        else if( (A[i] == ']') || (A[i] == '}') || (A[i] == ')') ){
            if (s.size() == 0)
                return 0;
            char temp = s.top();
            s.pop();
            if(isSame(temp, A[i])){
                if(s.size() == 0 && A[i + 1] == '\0')
                    return 1;
            }
            else{
                return 0;
            }
        }
    i++;
    }
    if(s.size() != 0)
        return 0;
}
