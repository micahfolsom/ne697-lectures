#include "hit.hpp"

namespace g4t {
G4ThreadLocal G4Allocator<Hit>* HitAllocator = nullptr;

Hit::Hit(int track_id, int parent_id, G4String const& volume,
         G4String const& particle, G4String const& process,
         G4ThreeVector const& position, float energy, double time)
    : m_eventID(-1),
      m_trackID(track_id),
      m_parentID(parent_id),
      m_volume(volume),
      m_particle(particle),
      m_process(process),
      m_position(position),
      m_energy(energy),
      m_time(time) {}

void Hit::setEventID(int id) {
  m_eventID = id;
  return;
}

int Hit::getEventID() const { return m_eventID; }

int Hit::getTrackID() const { return m_trackID; }

int Hit::getParentID() const { return m_parentID; }

G4String const& Hit::getVolume() const { return m_volume; }

G4String const& Hit::getParticle() const { return m_particle; }

G4String const& Hit::getProcess() const { return m_process; }

G4ThreeVector const& Hit::getPosition() const { return m_position; }

float Hit::getEnergy() const { return m_energy; }

double Hit::getTime() const { return m_time; }
}  // namespace g4t
