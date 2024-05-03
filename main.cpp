#include <iostream>
#include <cstdlib>
#include "square.h"
#include "grid.h"

int main() {
    //TEST GRIDS
    std::string test_rows = "123456789123456789123456789123456789123456789123456789123456789123456789123456789";
    std::string test_blocks = "123456789234567891345678912456789123567891234678912345789123456891234567912345678";
    std::string test_valid = "124567893378294516659831742987123465231456978546789321863972154495618237712345689";
    std::string unsolved_shortz = "039500000000800070000010904100400003000000000007000860006708200010090005000001008";
    std::string solved_shortz = "639574182541829376782613954198467523365982417427135869956748231813296745274351698";
    std::string markup_test = "001900008600085030007060100034090000000504000000010420005070900010840007700009200";
    std::string mepham_diabolical = "295700860031865020806000000007050006000387000500016700000500109020600350054008672";
    std::string mepham_solution = "295743861431865927876192543387459216612387495549216738763524189928671354154938672";
    std::string gentle_unsolved = "010420005002071039000000040207100006000040000600007403070000000120730500300082070";
    std::string gentle_solved = "81342976546257183979536814224715398653986539846217681297453978615324";
    std::string moderate_unsolved = "006201000800000071001700032007030040050000080080040700460005800170000004000406500";
    std::string moderate_solved = "736291458842653971591784632917538246254967183683142795469315827175829364328476519";
    std::string tough_unsolved = "001900008600085030007060100034090000000504000000010420005070900010840007700009200";
    std::string tough_solved = "341927568692185734857463192134296875278534619569718423425371986916842357783659241";

    Grid test = Grid();
    test.printGrid();
    test.markupGrid();
    test.printSquareCandidates();
    test.solve_pp();
    test.printGrid();
    
    return 0;
}