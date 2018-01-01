#include <algorithm>
#include <iterator>
#include <vector>

using std::copy;
using std::next;
using std::prev;
using std::vector;


vector<int> solution(vector<int> &A, int K)
{
    vector<int> data = A;
    vector<int> result(data.size());

    if (A.size() != 0) {
        const auto step = K % A.size();
        copy(data.begin(), prev(data.end(), step), next(result.begin(), step));
        copy(prev(data.end(), step), data.end(), result.begin());
    }

    return result;
}


/*solutiion finish here, some testing next*/

#include <iostream>
#include <utility>

using std::cout;
using std::endl;


void print_vector_elements(const vector<int> &vec)
{
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;

}

int main() {

    const auto K = 3U;
    vector<int> data = {3, 8, 9, 7, 6};
    auto result = solution(data, K);

    print_vector_elements(data);
    print_vector_elements(result);

}
