#include <algorithm>
#include <numeric>
#include <vector>

using std::vector;

namespace {

using std::iota;
using std::sort;

vector<int> generate_simple_progression(size_t size)
{
    vector<int> progression(size);
    iota(progression.begin(), progression.end(), 1);

    return progression;
}



}


int solution(int X, vector<int> &A)
{
  //  auto pattern = generate_simple_progression(X);
    return -1;
}


/***implementation finishes here, now time for testing*****/

#include <cassert>
//#include <utility>
#include <tuple>

using std::get;
using std::make_tuple;
using std::tuple;

int main()
{
    vector<tuple<int, vector<int>, int>> test_cases = {
        make_tuple(0, vector<int>{}, -1),
        make_tuple(6, vector<int>{}, -1),
    };

    for (auto &each : test_cases) {
        const auto ret = solution(get<0>(each), get<1>(each));
        assert(ret == get<2>(each));
    }
}
