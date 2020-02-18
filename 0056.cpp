class Solution {
public:
    static bool intervalCmp(vector<int> intervalA, vector<int> intervalB) {
        return intervalA[0] < intervalB[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), intervalCmp);

        for(int i=0; i+1<intervals.size(); ) {
            int j = i + 1; 
            while(intervals[j][0]<=intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1],intervals[j][1]); 
                intervals.erase(std::begin(intervals)+j);
                if(j>=intervals.size())
                    break;             
            }
            i = j;
        }
        //输出区间
        // for(int i=0; i<intervals.size(); i++) {
        //     cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]" << endl;
        // }
        return intervals;
    }
};