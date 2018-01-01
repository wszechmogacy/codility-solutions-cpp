#include <algorithm>
#include <iterator>
#include <list>

using std::max_element;
using std::next;
using std::list;
using std::prev;

namespace
{

list<unsigned> find_ones_position(int n)
{
    list<unsigned> ones_positions;
    auto current_bit = 0U;

    while (n > 0) {
        if (n % 2 == 1) {
            ones_positions.push_back(current_bit);
        }
        n = n >> 1;
        current_bit++;
    }
    return ones_positions;
}


list<unsigned> get_intervals_between_elements(const list<unsigned> &elements)
{
    list<unsigned> gap_widths;
    if (elements.size() > 1) {
        for (auto iter = elements.begin(); iter != prev(elements.end()); iter++) {
            gap_widths.push_back(*next(iter) - *iter - 1);
        }
    }

    return gap_widths;
}

}


int solution(int N)
{
    const auto ones_positions = find_ones_position(N);
    const list<unsigned> intervals = get_intervals_between_elements(ones_positions);

    const auto max_iter = max_element(intervals.begin(), intervals.end());
    if (max_iter != intervals.end()) {
        return *max_iter;
    } else {
        return 0;
    }
}

/*finish solution of task - small test now **/

#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<unsigned> v(150);
    std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
    for (const auto &each : v) {
        std::cout << each << " : " << solution(each) << std::endl;
    }
}
