#include "detectorconstruction.hpp"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "sensitivedetector.hpp"
#include "geometrymessenger.hpp"

namespace g4t {
DetectorConstruction::DetectorConstruction():
  G4VUserDetectorConstruction(),
  m_trackingVols()
{
  G4cout << "Creating DetectorConstruction" << G4endl;
  m_messenger = new GeometryMessenger(this);
}

DetectorConstruction::~DetectorConstruction() {
  G4cout << "Destroying DetectorConstruction" << G4endl;
  delete m_messenger;
}

G4VPhysicalVolume* DetectorConstruction::Construct() {
  // Build world
  // Half-dimensions
  auto world_solid = new G4Box("world_solid", 1. * m, 1. * m, 1. * m);

  auto nist = G4NistManager::Instance();
  auto world_mat = nist->FindOrBuildMaterial("G4_AIR");
  //auto world_mat = nist->FindOrBuildMaterial("NE697_LIQUID_OXYGEN");
  //G4cout << "OURS IN CONSTRUCT(): " << world_mat << G4endl;
  auto world_log = new G4LogicalVolume(world_solid, world_mat, "world_log");
  auto world_phys =
      new G4PVPlacement(nullptr, G4ThreeVector(0, 0, 0), world_log,
                        "world_phys", nullptr, false, 0, true);

  // Detector
  auto det_mat = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
  auto det_solid = new G4Box("det_solid", 25*cm, 25*cm, 25*cm);
  auto det_log = new G4LogicalVolume(det_solid, det_mat, "det_log");
  m_trackingVols.push_back(det_log);
  new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), det_log, "det_phys",
      world_log, false, 0, true);
  return world_phys;
}

void DetectorConstruction::ConstructSDandField() {
  auto sd = new SensitiveDetector("world_sd");
  G4SDManager::GetSDMpointer()->AddNewDetector(sd);
  for (auto& log: m_trackingVols) {
    SetSensitiveDetector(log, sd);
  }
  return;
}

void DetectorConstruction::set_det_size(G4ThreeVector const& det_size) {
  m_detSize = det_size;
  return;
}

G4ThreeVector const& DetectorConstruction::get_det_size() const {
  return m_detSize;
}
}  // namespace g4t
