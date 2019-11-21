using namespace std;

#include "BulbId.h"
#include "vector"

class ProgramGroup {
    public:
        string name;
        vector<BulbId> bulbs;

    ProgramGroup(string name, vector<BulbId> bulbs);
};