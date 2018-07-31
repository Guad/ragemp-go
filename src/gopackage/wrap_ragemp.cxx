#include "wrap_ragemp.hxx"
#include "../sdk/rage.hpp"

void *getWorld(void *mpRef)
{
    rage::IMultiplayer *mp = (rage::IMultiplayer*) mpRef;
    void *worldref = (void*) &mp->GetWorld();
    return worldref;
}