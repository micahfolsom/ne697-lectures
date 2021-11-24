#ifndef GEOMETRY_MESSENGER_HPP
#define GEOMETRY_MESSENGER_HPP
#include "G4UImessenger.hh"
#include "G4UIcmdWith3VectorAndUnit.hh"
#include "runaction.hpp"

namespace g4t {
  // Forward declaration
  class DetectorConstruction;

  class GeometryMessenger: public G4UImessenger {
  public:
    GeometryMessenger(DetectorConstruction* dc);
    ~GeometryMessenger();

    void SetNewValue(G4UIcommand* cmd, G4String val);

  private:
    DetectorConstruction* m_DC;
    G4UIdirectory* m_directory;
    G4UIcmdWith3VectorAndUnit* m_detectorSize;
  };  
}

#endif
