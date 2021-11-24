#ifndef HIT_HPP
#define HIT_HPP
#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4VHit.hh"

namespace g4t {
class Hit : public G4VHit {
 public:
  Hit(int trackid, int parent_id, G4String const& volume,
      G4String const& particle, G4String const& process,
      G4ThreeVector const& position, float energy, double time);

  inline void* operator new(std::size_t);
  inline void operator delete(void* hit);

  void setEventID(int id);
  int getEventID() const;
  int getTrackID() const;
  int getParentID() const;
  G4String const& getVolume() const;
  G4String const& getParticle() const;
  G4String const& getProcess() const;
  G4ThreeVector const& getPosition() const;
  float getEnergy() const;
  double getTime() const;

 private:
  int m_eventID;
  int m_trackID;
  /// Track ID of the parent
  int m_parentID;
  G4String m_volume;
  G4String m_particle;
  /// Process that created this particle
  G4String m_process;
  G4ThreeVector m_position;
  float m_energy;
  double m_time;
};

/*! Alias HitsCollection as G4THitsCollection<Hit>. */
typedef G4THitsCollection<Hit> HitsCollection;
/*! Thread-local pointer for the Hit allocator. */
extern G4ThreadLocal G4Allocator<Hit>* HitAllocator;

// The two functions below must be defined *after* HitAllocator. */
inline void* Hit::operator new(std::size_t) {
  // If there's no allocator yet, make one, then return memory for
  // a new Hit
  if (!HitAllocator) {
    HitAllocator = new G4Allocator<Hit>;
  }
  return (void*)HitAllocator->MallocSingle();
}
inline void Hit::operator delete(void* a_hit) {
  HitAllocator->FreeSingle((Hit*)a_hit);
  return;
}
}  // namespace g4t

#endif
