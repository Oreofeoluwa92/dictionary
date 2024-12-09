#include "header.hpp"

int main() {
    DICTION d = {};
    buildDictionary(d);
    showStats(d);
    drawHistograms(d);
    return 0;
}