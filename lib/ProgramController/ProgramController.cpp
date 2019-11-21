#include "ProgramController.h"
#include "MiLightClient.h"
#include "BulbId.h"
#include "MiLightRemoteType.h"
#include "vector"

ProgramController::ProgramController(MiLightClient* milightClient) : milightClient(milightClient) {
    
}

void ProgramController::start() {
    Serial.println("Starting ProgramController...");
    BulbState state = BulbState();
    state.hue = 1;
    setGroupState(wakeupGroup, state);
}

void ProgramController::setBulbState(BulbId& bulb, BulbState& state) {
    milightClient->prepare(bulb.deviceType, bulb.deviceId, bulb.groupId);
    if(state.hue != UINT16_MAX) {
        milightClient->updateHue(state.hue);
    }
}

void ProgramController::setGroupState(ProgramGroup& group, BulbState& state) {
    Serial.println("Group size"); Serial.print(sizeof(group.bulbs));
    for(auto bulb : group.bulbs) {
        setBulbState(bulb, state);
    }
}