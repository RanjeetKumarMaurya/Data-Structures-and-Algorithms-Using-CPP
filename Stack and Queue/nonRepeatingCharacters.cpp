string Solution::solve(string A) {
    string output;
    unordered_map<char, int> map;
    queue<char> queue;

    int i = 0;
    while(A[i] != '\0'){

        if(map.count(A[i]) > 0){
            map[A[i]]++;
            queue.push(A[i]);
        }
        else{
            map[A[i]] = 1;
            queue.push(A[i]);
        }

        if(map[A[i]] < 2){
            output += queue.front();
        }
        else{
            while(map[queue.front()] >= 2){                                                 
                queue.pop();
                if(queue.size() == 0){
                    output += "#";
                }
            }
            if(queue.size() != 0){
                output += queue.front();
            } 
        }
        i++;
    }
    return output;
}
