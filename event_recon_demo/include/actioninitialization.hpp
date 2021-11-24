#ifndef ACTION_INITIALIZATION_HPP
#define ACTION_INITIALIZATION_HPP
#include "G4VUserActionInitialization.hh"

namespace g4t {
class ActionInitialization : public G4VUserActionInitialization {
 public:
  void BuildForMaster() const override final;
  void Build() const override final;
};
}  // namespace g4t

#endif
