#include <numeric>
#include <vector>

using std::accumulate;
using std::vector;

namespace
{

int calculate_missing_element_value(const vector<int> &data)
{
    const auto expected_max_value = data.size() + 1;
    const auto expected_sum = (1 + expected_max_value) * (data.size() + 1) / 2;
    const auto sum_of_elements = accumulate(data.begin(), data.end(), 0);

    return expected_sum - sum_of_elements;
}

}


int solution(vector<int> &A)
{
    auto data = A;
    return calculate_missing_element_value(data);
}
