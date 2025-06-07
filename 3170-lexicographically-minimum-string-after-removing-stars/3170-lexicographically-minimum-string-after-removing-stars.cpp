struct Compare {
    bool operator()(pair<char,int> a, pair<char,int> b) {
        if(a.first == b.first){
            return b.second > a.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    string clearStars(string s) {
                        //char , index -------> smallest char first to remove with largest index
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> pq;
        for(int i=0;i<s.size();i++){
            if(s[i] == '*'){
                pq.pop();
            }else{
                pq.push({s[i] , i});
            }
        }
        vector<char> arr(s.size(), '*');
        while(!pq.empty()){
            auto [ch , ind] = pq.top(); pq.pop();
            arr[ind] = ch;
        }
        string ans = "";
        for(auto x : arr){
            if(x != '*')ans += x;
        }
        return ans;
    }
};