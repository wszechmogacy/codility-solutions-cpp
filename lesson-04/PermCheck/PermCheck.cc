#include <algorithm>
#include <numeric>
#include <vector>

using std::vector;

namespace {

using std::equal;
using std::iota;
using std::sort;

vector<int> generate_simple_progression(size_t size)
{
    vector<int> progression(size);
    iota(progression.begin(), progression.end(), 1);

    return progression;
}


bool is_permutation(const vector<int> &candidate, const vector<int> &pattern)
{
    auto perm_candidate = candidate;
    sort(perm_candidate.begin(), perm_candidate.end());

    return equal(pattern.begin(), pattern.end(), perm_candidate.begin());
}

}


int solution(vector<int> &A)
{
    const auto pattern = generate_simple_progression(A.size());
    return static_cast<int>(is_permutation(A, pattern));
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
