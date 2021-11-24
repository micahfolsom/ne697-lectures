#include "actioninitialization.hpp"

#include "eventaction.hpp"
#include "pga.hpp"
#include "runaction.hpp"

namespace g4t {
void ActionInitialization::BuildForMaster() const {
  SetUserAction(new RunAction);
  return;
}

void ActionInitialization::Build() const {
  SetUserAction(new PGA);
  SetUserAction(new RunAction);
  SetUserAction(new EventAction);
  return;
}
}  // namespace g4t
