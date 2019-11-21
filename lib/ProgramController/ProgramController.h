#include "MiLightClient.h"
#include "ProgramGroup.h"
#include "BulbId.h"
#include "MiLightRemoteType.h"

class BulbState {
    public:
        uint16_t hue = UINT16_MAX;
};

class ProgramController {
    protected:
        MiLightClient* milightClient;
        
        ProgramGroup wakeupGroup = ProgramGroup("WakeUp", {
            BulbId(1, 1, REMOTE_TYPE_RGB_CCT),
            BulbId(2, 1, REMOTE_TYPE_RGB_CCT)
        });

        ProgramGroup partyGroup = ProgramGroup("PartyGroup", {
            BulbId(1, 1, REMOTE_TYPE_RGB_CCT),
            BulbId(2, 1, REMOTE_TYPE_RGB_CCT)
        });

    public:
        ProgramController(MiLightClient* milightClient);
        void setupGroups();
        void start();
        void setBulbState(BulbId& bulb, BulbState& state);
        void setGroupState(ProgramGroup& group, BulbState& state);
        void setGroup(string name, vector<BulbId> bulbs);
        void setGroupStates(JsonArray& states);
};