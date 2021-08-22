#include <vector>


template <typename T>
std::vector<std::vector<int>> filter(T& pool, int value) {
    std::vector<std::vector<int>> filtered_vector;
    for (const auto& v: pool) {
        if (v[0] == value) {
            filtered_vector.push_back(v);
        }
    }
    return filtered_vector;
}


template <typename T>
std::vector<std::vector<int>> filter(T& pool, int first, int second) {
    std::vector<std::vector<int>> filtered_vector;
    for (const auto& v: pool) {
        if (v[0] == first && v[1] == second) {
            filtered_vector.push_back(v);
        }
    }
    return filtered_vector;
}

template <typename T>
std::vector<std::vector<int>> filter_any(T& pool, int value) {
    std::vector<std::vector<int>> filtered_vector;
    for (const auto& v: pool) {
        for (const auto& num: v) {
            if (num == value) {
                filtered_vector.push_back(v);
                continue;
            }
        }
    }
    return filtered_vector;
}
