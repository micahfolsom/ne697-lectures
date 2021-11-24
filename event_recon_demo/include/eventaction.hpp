#ifndef EVENT_ACTION_HPP
#define EVENT_ACTION_HPP
#include "G4UserEventAction.hh"

namespace g4t {
class EventAction : public G4UserEventAction {
 public:
  void EndOfEventAction(G4Event const* event) override final;
};
}  // namespace g4t

#endif
