// created by yel on 2022/4/3
// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence. You must write an algorithm that runs in O(n)
// time.
//
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
// Constraints:
// 0 <= nums.length <= 105
//-109 <= nums[i] <= 109

// 问题：给定未排序的整型数组，返回最长连续元素序列的长度

// 方法：构建一个哈希表，key为数组中的元素，val为该元素组成的最长连续元素序列的长度
// 遍历整个数组，判断当前字符是否在哈希表中，已存在则跳过；否则添加到表中，长度为1，然后寻找-1,+1的数值的最大长度
// 总长 = left + right +1，并更新连续元素序列中的边界部分的长度信息, 即num-left,
// num-right = sum

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "math.h"
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> map;
    for (const int n : nums) {
      if (map.find(n) == map.end()) {
        int left = (map.find(n - 1) == map.end()) ? 0 : map[n - 1];
        int right = (map.find(n + 1) == map.end()) ? 0 : map[n + 1];
        int sum = left + right + 1;
        map[n] = sum;
        map[n - left] = sum;
        map[n + right] = sum;
        res = max(res, sum);
      } else
        continue;
    }
    return res;
  }
};

struct eventCountMap {
  uint32_t count;
  double last_t;

  eventCountMap() : count(0), last_t(0.){};
  eventCountMap(uint32_t c, double lt) : count(c), last_t(lt) {}
};

class Test {
 public:
  eventCountMap event_map;
};

struct TriggerMessage {
  std::string collect_type = "msquare-fusion";
  std::string name =
      "";  // bag name中的命名， 命名规则： 模块名称_用途1_用途2....
  float cool_down_limit = -1;  // cool down 阈值，超过阈值后会被check task冷却
  bool sticky = false;

  // record topics according to specified timestamp
  // record current timestamp if sec == 0
  // event reject if abs(sec - current_timestamp) > 5s
  // recording reject if abs(sec - current_timestamp) > 10s
  uint64_t stamp = 0;

  uint8_t trigger_type = TriggerMessage::EVENT;

  // it is necessary for sequential_frames, must be >= 5 seconds
  // if you set them in single_frame, record like sequential_frames, must be
  // (before + after < 5)
  uint8_t before = 5;
  uint8_t after = 5;

  // sequential_frames is optional and single_frame is mandatory
  std::vector<std::string> topics;
  std::vector<uint64_t> stamps;

  std::vector<std::string> tags;  // tags for sequential filter

  // recording param
  bool start = false;

  enum : uint8_t { EVENT = 0, SINGLE_FRAME = 1, RECORDING = 2 };
};

int main() {
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  //  Solution sol;
  //  sol.longestConsecutive(nums);
  float a = -12.324;
  double b = -23.32;
  float c = 1.23;
  cout << abs(a) << endl;
  cout << (int)a << endl;
  cout << abs(b) << endl;
  cout << abs(c) << endl;
  string str = "hello world";
  char* begin = &str[0];
  Test test;
  cout << test.event_map.count << endl;
  vector<int> int_que{6, 7, 8, 9, 10, 4};
  cout << int_que.empty() << endl;
  //  int_que.push_back(0);
  cout << int_que.size() << endl;
  cout << "size" << endl;
  for (auto it = int_que.begin(); it != int_que.end();) {
    if (*it <= 5) {
      cout << *it << endl;
      it = int_que.erase(it);
    } else if (int_que.size() > 5) {
      it = int_que.erase(int_que.begin(), int_que.begin() + 5);
    } else
      it++;
    cout << int_que.size() << endl;
  }

  vector<TriggerMessage> msg_vec;
  for (auto it = msg_vec.begin(); it != msg_vec.end();) {

  }
}