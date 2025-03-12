#ifndef DSU_H
#define DSU_H

#include <vector>

const int defaultValue = 10;

namespace DataStructure {
    class DisjointSetUnion {
    public:
        DisjointSetUnion() : vSize(defaultValue) {
            init();
        }

        DisjointSetUnion(const DisjointSetUnion&) = delete;

        DisjointSetUnion(DisjointSetUnion&&) = delete;

        DisjointSetUnion& operator=(const DisjointSetUnion&) = delete;

        ~DisjointSetUnion() = default;

        explicit DisjointSetUnion(size_t size) : vSize(size) {
            init();
        }

        explicit DisjointSetUnion(const std::vector<int>& v) {
            vSize = v.size();
            link = v;
        }

        void init() {
            link.resize(vSize);
            size.resize((vSize));
            for (int i = 0; i < vSize; ++i) {
                link[i] = i;
                size[i] = 1;
            }
        }

        // эвристика сжатия пути
        int find(int x) {
            if (link[x] == x) return x;
            link[x] = find(link[x]);
            return link[x];
        }

        // весовая эвристика
        void unite(const int x, const int y) {
            int first = find(x), second = find(y);
            if (size[first] > size[second]) std::swap(first,second);
            size[second] += size[first];
            link[first] = second;
        }

    private:
        std::vector<int> link;
        std::vector<int> size;
        size_t vSize{};

        bool isSame(int x, int y) {
            x = find(x); y = find(y);
            return x == y;
        }
    };
}

#endif
