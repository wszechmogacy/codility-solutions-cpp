#include <algorithm>
#include <vector>

using std::is_permutation;
using std::vector;


bool check_if_permutation(const vector<int> &data)
{
    vector<int> v(data.size());
    std::generate(v.begin(), v.end(), [n = 1] () mutable { return n++; });

    return is_permutation(v.begin(), v.end(), data.begin(), data.end());

}


int solution(vector<int> &A)
{
     return static_cast<int>(check_if_permutation(A));
}


/***implementation finishes here, now time for testing*****/

#include <cassert>
#include <utility>

using std::get;
using std::pair;

int main()
{
    vector<pair<vector<int>, int>> test_cases = {
        {{}, 1},
        {{1}, 1},
        {{4, 1, 3, 2}, 1},
        {{4, 1, 3}, 0},
    };

    for (auto &each : test_cases) {
        const auto ret = solution(get<0>(each));
        assert(ret == get<1>(each));
    }

}
