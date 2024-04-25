#pragma once

class PlayerCollider;

class IUsePlayerCollision {
public:
    virtual PlayerCollider* getPlayerCollider() const;
    virtual bool isEnableStandUp() const;
    virtual bool isEnableHoldUp() const;
    virtual bool isPressedCeil() const;
    virtual float getSafetyCeilSpace() const;
    virtual float getCeilCheckHeight() const;
    virtual bool isAboveGround() const;
    virtual float getGroundHeight() const;
    virtual float getShadowDropHeight() const;
    virtual float getFallDistance() const;
};
