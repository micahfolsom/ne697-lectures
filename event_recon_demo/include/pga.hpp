#ifndef PGA_HPP
#define PGA_HPP
#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

namespace g4t {
class PGA : public G4VUserPrimaryGeneratorAction {
 public:
  PGA();

  void GeneratePrimaries(G4Event* event) override final;

 private:
  // This has a messenger now!
  G4ParticleGun* m_gun;
};
}  // namespace g4t

#endif
