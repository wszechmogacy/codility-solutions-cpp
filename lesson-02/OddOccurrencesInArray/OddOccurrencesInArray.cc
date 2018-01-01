#include <algorithm>
#include <experimental/optional>
#include <iterator>
#include <vector>

using std::advance;
using std::experimental::optional;
using std::next;
using std::sort;
using std::vector;


optional<int> find_first_unpaired_in_sorted_container(const vector<int> &data)
{
    auto iter = data.begin();

    while (iter < data.end()) {
        if (next(iter) == data.end() || *iter != *next(iter)) {
            return *iter;
        } else {
            advance(iter, 2);
        }
    }
    return {};
}


int solution(vector<int> &A)
{
    vector<int>data = A;
    sort(data.begin(), data.end());
    return find_first_unpaired_in_sorted_container(data).value_or(0);
}


/*finish solution, some testing now*/
#include <cassert>
#include <iostream>
#include <map>
#include <utility>
using std::cout;
using std::endl;
using std::get;
using std::map;
using std::pair;


void print_vector_elements(const vector<int> &vec)
{
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;

}


int main()
{
    vector<pair<vector<int>, int>> test_cases = {
        {{}, 0},
        {{1,}, 1},
        {{2, 2}, 0},
        {{2, 2, 3}, 3},
        {{1, 2, 1}, 2},
        {{4, 3, 6, 4, 3,}, 6},
        {{9, 3, 9, 3, 9, 7, 9}, 7},
    };

    for (auto &each : test_cases) {
        print_vector_elements(get<0>(each));
        const auto ret = solution(get<0>(each));
        cout << "solution: " << ret << endl;
        assert(ret == get<1>(each));
    }
}
