#include "Imports.h"
#include "CellList.h"
#include "ShortToLong.h"
#include "AssignFreqeuncies.h"
#include "ScoreSolution.h"
#include "RandomizeFreqs.h"
#include <chrono>

using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();
    CellList list ("CellInfo.csv");
    list.findDistances();
    vector<Dist*> ori = list.getAllDistList();
    vector<CellCollective*> cells = list.getCellList();

    ShortToLong* stl = new ShortToLong(cells, ori);
    vector<Dist*> sorted = stl->getOrderedDistList();
    AssignFreqeuncies* af = new AssignFreqeuncies(sorted, list.getAverageDist(), list.getLongestDist(), list.getShortestDist());
    list.printList();
    ScoreSolution ss(list.getLongestDist(), list.getShortestDist());
    ss.calculateScore(sorted);
    cout << "Solution score: " << ss.getScore() << endl << endl;

    cout << "Finding the optimum solution...Takes approximately two minutes on a I5 processor";
    cout << endl << endl;
    double maxScore = -DBL_MAX;
    int iter = 10000000;
    vector<Cell> bestConfig;
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < iter; i++) {
        RandomizeFreqs rf(cells);
        ScoreSolution ss1(list.getLongestDist(), list.getShortestDist());
        ss1.calculateScore(sorted);
        if (ss1.getScore() > maxScore) {
            bestConfig.clear();
            maxScore = ss1.getScore();
            for (auto i : cells) {
                bestConfig.push_back(*i->getCell());
            }
        }
    }

    for (int i = 0; i < bestConfig.size(); i++) {
        cells.at(i)->setCell(&bestConfig.at(i));
    }
    list.printList();
    cout << "Best configuration from " << iter << " random iterations: " << maxScore << endl << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout <<"Time taken: "<< duration.count() <<"seconds"<< endl;

}
