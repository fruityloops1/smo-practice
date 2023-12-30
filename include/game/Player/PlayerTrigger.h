#pragma once

class PlayerTrigger {
public:
    enum ECollisionTrigger {
        cUpperPunch = 0,
        cPoison = 5
    };
    enum EAttackSensorTrigger {};
    enum EActionTrigger { var1 = 30 };
    enum EReceiveSensorTrigger {};
    enum EPreMovementTrigger {};
    enum EDemoEndTrigger {};
    enum EMaterialChangeTrigger {};

    // bool isOn(ECollisionTrigger);
    // bool isOn(EAttackSensorTrigger);
    // bool isOn(EActionTrigger);
    // bool isOn(EReceiveSensorTrigger);
    // bool isOn(EPreMovementTrigger);
    // bool isOn(EDemoEndTrigger);
    // bool isOn(EMaterialChangeTrigger);

    unsigned int mCollisionTrigger;
    unsigned int mAttackSensorTrigger;
    unsigned long mActionTrigger;
    unsigned int mReceiveSensorTrigger;
    unsigned int mPreMovementTrigger;
    unsigned int mDemoEndTrigger;
    unsigned int mMaterialChangeTrigger;
    const char* mRecMaterialTrigger;
};
