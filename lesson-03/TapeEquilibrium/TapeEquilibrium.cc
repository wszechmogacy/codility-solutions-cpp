#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <vector>

using std::min_element;
using std::partial_sum;
using std::vector;


vector<int> make_lhalf_sums(const vector<int> &data)
{
    vector<int> lhalf_sums(data.size() - 1);
    partial_sum(data.begin(), prev(data.end()), lhalf_sums.begin());

    return lhalf_sums;
}


vector<int> make_rhalf_sums(const vector<int> &data)
{
    vector<int> rhalf_sums(data.size());
    partial_sum(data.rbegin(), data.rend(), rhalf_sums.begin());
    reverse(rhalf_sums.begin(), rhalf_sums.end());
    rhalf_sums.erase(rhalf_sums.begin());

    return rhalf_sums;
}


vector<int> make_diffs(const vector<int> &lhalf_sums, const vector<int> &rhalf_sums)
{
    vector<int> diff;
    for (auto i = 0U; i < rhalf_sums.size(); i++) {
         diff.push_back(abs(lhalf_sums.at(i) - rhalf_sums.at(i)));
    }

    return diff;
}


int solution(vector<int> &A)
{
    int result;

    if (A.empty()) {
        result = 0;
    } else if (A.size() == 1) {
        result =  A.at(0);
    } else {
        const auto lhalf_sums = make_lhalf_sums(A);
        const auto rhalf_sums = make_rhalf_sums(A);
        const auto diffs = make_diffs(lhalf_sums, rhalf_sums);

        result = *min_element(diffs.begin(), diffs.end());
    }

    return result;
}

/* implementation finished. time for testing */

#include <cassert>
#include <utility>
using std::pair;
using std::get;

int main()
{
    vector<pair<vector<int>, int>> test_cases = {
        {{}, 0},
        {{1}, 1},
        {{34, 34}, 0},
        {{3, 1, 2, 4, 3}, 1},
    };

    for (auto &each : test_cases) {
        const auto ret = solution(get<0>(each));
        assert(ret == get<1>(each));
    }
}
