class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> m;

        for (auto& x : nums){
            m[x]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& [key, value] : m){
            pq.push({value, key});
            if (pq.size()>k){
                pq.pop();
            }
        }

        vector<int> answer;

        for (int i = 0; i<k; i++){
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;

    }
};
