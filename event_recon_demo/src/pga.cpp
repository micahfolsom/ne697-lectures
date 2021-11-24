#include "pga.hpp"

#include "G4Gamma.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4IonTable.hh"

namespace g4t {
PGA::PGA()
    : G4VUserPrimaryGeneratorAction(),
      // Only 1 particle per shot
      m_gun(new G4ParticleGun(1)) {
  // Constant properties - not changed (unless we use a messenger)
  m_gun->SetParticleDefinition(G4Gamma::Definition());
  m_gun->SetParticleEnergy(1000.*keV);
  m_gun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
  m_gun->SetParticleMomentumDirection(G4ThreeVector(0., -1., 0.));
}

void PGA::GeneratePrimaries(G4Event* event) {
  // Per-event properties (e.g. direction)
  m_gun->GeneratePrimaryVertex(event);
  return;
}
}  // namespace g4t
