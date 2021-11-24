#include "sensitivedetector.hpp"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"

namespace g4t {
SensitiveDetector::SensitiveDetector(G4String const& name)
    : G4VSensitiveDetector(name), m_id(-1), m_hitsCollection(nullptr) {
  G4String hc_name = name + "_hits";
  collectionName.insert(hc_name);
}

SensitiveDetector::~SensitiveDetector() {
}

void SensitiveDetector::Initialize(G4HCofThisEvent* hc) {
  // Check if we have a valid ID
  if (m_id < 0) {
    m_id = GetCollectionID(0);
  }
  // Create a hits collection for this SD
  m_hitsCollection =
      new HitsCollection(SensitiveDetectorName, collectionName[0]);
  // Give the collection to the G4Event, so we can get it at the end
  // in Run::RecordEvent()
  hc->AddHitsCollection(m_id, m_hitsCollection);
  return;
}

bool SensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*) {
  auto track = step->GetTrack();
  // "must use class tag", I think G4VSensitiveDetector must have a Hit
  // member?

  auto hit = new g4t::Hit(
      track->GetTrackID(), track->GetParentID(), track->GetVolume()->GetName(),
      track->GetDefinition()->GetParticleName(),
      (track->GetCreatorProcess() ? track->GetCreatorProcess()->GetProcessName()
                                  : "generator"),
      track->GetPosition(), step->GetTotalEnergyDeposit(),
      track->GetGlobalTime());
  m_hitsCollection->insert(hit);
  // DEBUG
  /*G4cout << "Got a hit!" << G4endl;
  G4cout << "Volume: " << hit->getVolume() << "\n";
  G4cout << "Particle: " << hit->getParticle() << "\n";
  G4cout << "Creator process: " << hit->getProcess() << "\n";
  G4cout << "Position: " << G4BestUnit(hit->getPosition(), "Length") << "\n";
  G4cout << "Energy deposited: " << G4BestUnit(hit->getEnergy(), "Energy")
         << "\n";
  G4cout << "Time: " << G4BestUnit(hit->getTime(), "Time") << "\n" << G4endl;
  */
  // DEBUG
  return true;
}
}  // namespace g4t
