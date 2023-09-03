class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
         std::sort(courses.begin(), courses.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        std::priority_queue<int> queue;
        int time = 0;

        for (const std::vector<int>& c : courses) {
            if (time + c[0] <= c[1]) {
                queue.push(c[0]);
                time += c[0];
            } else if (!queue.empty() && queue.top() > c[0]) {
                time += c[0] - queue.top();
                queue.pop();
                queue.push(c[0]);
            }
        }

        return queue.size();  
    }
};