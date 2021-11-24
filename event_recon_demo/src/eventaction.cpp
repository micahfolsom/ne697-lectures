#include "eventaction.hpp"

#include "G4Event.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"

namespace g4t {
void EventAction::EndOfEventAction(G4Event const* event) {
  auto run_man = G4RunManager::GetRunManager();
  auto run = dynamic_cast<G4Run*>(run_man->GetNonConstCurrentRun());
  auto ntotal = run->GetNumberOfEventToBeProcessed();
  auto ievent = event->GetEventID();
  // Report status every 5% or so
  int rep_freq = (int)(ntotal / 20);
  if (rep_freq == 0) {
    rep_freq = 1;
  }
  if (ievent % rep_freq == 0) {
    G4cout << "Processing event " << ievent << " ("
           << 100.0 * (float)ievent / (float)ntotal << " %)" << G4endl;
  }
  return;
}
}  // namespace g4t
