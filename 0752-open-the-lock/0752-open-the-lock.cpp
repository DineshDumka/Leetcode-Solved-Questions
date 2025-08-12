class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> d;

        for (int i = 0; i < deadends.size(); i++){
            d.insert(deadends[i]);
        }

        if (d.count("0000")){
            return -1;
        }

        queue<pair<string,int>> q;

        set<string> visited = {};

        q.push({"0000",0});
        visited.insert("0000");

        while (!q.empty()){
            string node = q.front().first;
            int cnt = q.front().second;

            if (node == target){
                return cnt;
            }

            q.pop();

            for (int i = 0; i < 4; i++){
                int num = node[i] - '0';
                char c = (num+1)%10 + '0';

                string new_node = node.substr(0,i) + c + node.substr(i+1);

                if (!visited.count(new_node) && !d.count(new_node)){
                    visited.insert(new_node);
                    q.push({new_node,cnt+1});
                }

                if (num == 0){
                    c = '9';
                } else {
                    c = (num-1)%10 + '0';
                }

                new_node = node.substr(0,i) + c + node.substr(i+1);

                if (!visited.count(new_node) && !d.count(new_node)){
                    visited.insert(new_node);
                    q.push({new_node,cnt+1});
                }

            }
        }

        return -1;
    }
};