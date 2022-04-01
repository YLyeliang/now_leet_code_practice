// created by yel on 2022/3/26
#include "iostream"
#include "map"
#include "vector"
#include "chrono"

using namespace std;

struct durationMap {
    int a;
    uint32_t b;

    durationMap(int a_, uint32_t b_) : a(a_), b(b_) {}

    durationMap() = default;
};

//class test{
//
//    void process_test(){
//        std::map<int, vector<int>> id_duration_map;
//        std::map<int, durationMap> tt_map;
//
//        if (tt_map.find(123) == tt_map.end()) {
//            durationMap list;
//            list.a = 123, list.b = 123;
//
//
//        } else {
//            list = tt_map.find(123)->second;
////        list.b = 555;
////        tt_map[123] = list;
//        }
//
//        list.b = 555;
//        tt_map[123] = list;
//
//    }
//
//private:
//};


int main() {
    std::map<int, vector<int>> id_duration_map;
    std::map<int, durationMap> tt_map;

    durationMap list;
    if (tt_map.find(123) == tt_map.end()) {
        list.a = 123, list.b = 123;


    } else {
        list = tt_map.find(123)->second;
//        list.b = 555;
//        tt_map[123] = list;
    }

    list.b = 555;
    tt_map[123] = list;
    auto sdfsd = tt_map[123];

    durationMap sss(1, 2);
    cout << sss.a << sss.b << endl;
    id_duration_map[123] = {1, 2, 3};
    id_duration_map[122] = {2, 2, 3};

    auto dd = id_duration_map.find(123)->second;
    dd[2] = 155;
    id_duration_map[123] = dd;
    id_duration_map[123][2]=2;

    auto aa = id_duration_map.find(222);

    auto cc = id_duration_map.find(233) == id_duration_map.end();
    bool tag = aa->second.size() == 0;
//    bool tag2 = dd->second.size() == 0;
    uint64_t timestamp1 = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    uint64_t timestamp2 = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    auto ttt = timestamp1 / 1e9;
    auto diff = timestamp2 / (1e9) - timestamp1 / (1e9);
    return 0;


}