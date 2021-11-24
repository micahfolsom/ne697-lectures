#include "geometrymessenger.hpp"
#include "G4UnitsTable.hh"
#include "detectorconstruction.hpp"

namespace g4t {
  GeometryMessenger::GeometryMessenger(DetectorConstruction* dc):
    G4UImessenger(),
    m_DC(dc)
  {
    // Directory: /ne697/geometry
    m_directory = new G4UIdirectory("/ne697/geometry/");
    m_directory->SetGuidance("Change the geometry.");

    // Toggle data saving: /ne697/geometry/save_data
    m_detectorSize = new G4UIcmdWith3VectorAndUnit("/ne697/geometry/det_size",
        this);
    m_detectorSize->SetGuidance("Toggle saving data to file.");
    m_detectorSize->SetParameterName("x", "y", "z", true);
    m_detectorSize->SetDefaultValue(m_DC->get_det_size());
    m_detectorSize->AvailableForStates(G4State_PreInit);
  }
  
  GeometryMessenger::~GeometryMessenger() {
    delete m_directory;
    delete m_detectorSize;
  }

  void GeometryMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_detectorSize) {
      auto parsed_val = m_detectorSize->GetNew3VectorValue(val);
      m_DC->set_det_size(parsed_val);
      G4cout << "Detector size set to " << G4BestUnit(parsed_val, "Length")
        << G4endl;
    }
    // Command did not match
    return;
  }
}
