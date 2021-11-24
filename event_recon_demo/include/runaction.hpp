#ifndef RUN_ACTION_HPP
#define RUN_ACTION_HPP

#include "G4UserRunAction.hh"
#include "hit.hpp"
#include <queue>

namespace g4t {
  // Forward declaration, to address circular dependency with RunAction
  // You still need to #include "runmessenger.hpp" in runaction.cpp
  class RunMessenger;

  class RunAction: public G4UserRunAction {
    public:
      RunAction();
      ~RunAction();

      G4Run* GenerateRun() override final;
      void BeginOfRunAction(G4Run const*) override final;
      void EndOfRunAction(G4Run const* run) override final;

      bool save_data() const;
      void save_data(bool save);
      G4String const& get_path() const;
      void set_path(G4String const& path);

    private:
      void write_hits(std::queue<Hit> hits);

      RunMessenger* m_messenger;
      bool m_fSaveData;
      G4String m_path;
  };
}

#endif
