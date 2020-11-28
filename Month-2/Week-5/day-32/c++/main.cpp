/**
 * DAY-32 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

#include <list>

/**
 * Track the player ranking using Dense Ranking.
 * @param rankedScores the ranked scores
 * @param playerScores the player scores
 * @return Player Ranking for each game
 */ 
std::vector<int> playerRank(std::vector<int> rankedScores, std::vector<int> playerScores) {    
    
    std::vector<int> playerRanking;
    for (auto &p : playerScores) {
        std::list<int> unifiedScoresAux;
        std::list<int> rankedScoresAux(rankedScores.begin(), rankedScores.end());
        unifiedScoresAux.merge(rankedScoresAux);
        unifiedScoresAux.push_back(p);
        unifiedScoresAux.sort();
        unifiedScoresAux.unique();
        
        int index = 0;
        for (auto &s : unifiedScoresAux) {
            if (s == p) {
                playerRanking.push_back(unifiedScoresAux.size() - index);
                break;
            }
            index++;
        }
    }

    return playerRanking;
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(playerRank({100, 90, 90, 80}, {70, 80, 105}) == std::vector<int>{4, 3, 1});
    CHECK(playerRank({100, 90, 90, 80}, {106, 107, 105}) == std::vector<int>{1, 1, 1});
    CHECK(playerRank({100, 90, 90, 80}, {90, 80, 1}) == std::vector<int>{2, 3, 4});
}
