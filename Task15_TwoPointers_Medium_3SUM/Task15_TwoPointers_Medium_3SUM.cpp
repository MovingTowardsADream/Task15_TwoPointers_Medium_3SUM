#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<int> small;
        std::vector<std::vector<int>> output;
        int l, r, sum, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0;i < n-2;i++) {
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] < 0) continue;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = n - 1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    small = { nums[i] ,nums[l] ,nums[r] };
                    output.push_back(small);
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
                else if (sum > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return output;
    }
};

int main()
{
    std::vector<int> nums = { -1,0,1,2,-1,-4 };
    for (std::vector<int> i : Solution::threeSum(nums)) {
        for (int j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
