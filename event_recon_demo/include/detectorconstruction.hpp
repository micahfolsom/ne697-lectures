#ifndef DETECTOR_CONSTRUCTION_HPP
#define DETECTOR_CONSTRUCTION_HPP
#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"
class G4LogicalVolume;

namespace g4t {
class GeometryMessenger;
class DetectorConstruction : public G4VUserDetectorConstruction {
 public:
  DetectorConstruction();
  ~DetectorConstruction();
  G4VPhysicalVolume* Construct() override final;
  void ConstructSDandField() override final;

  void set_det_size(G4ThreeVector const& det_size);
  G4ThreeVector const& get_det_size() const;

 private:
  std::vector<G4LogicalVolume*> m_trackingVols;
  GeometryMessenger* m_messenger;
  G4ThreeVector m_detSize;
};
}  // namespace g4t

#endif
