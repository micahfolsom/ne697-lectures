#include "runaction.hpp"
#include "globals.hh"
#include "run.hpp"
#include <fstream>
#include "G4SystemOfUnits.hh"
#include "runmessenger.hpp"

namespace g4t {
  RunAction::RunAction():
    G4UserRunAction(),
    m_fSaveData(true),
    m_path("hits.csv")
    {
      G4cout << "Creating RunAction" << G4endl;
      m_messenger = new RunMessenger(this);
    }

  RunAction::~RunAction() {
    G4cout << "Deleting RunAction" << G4endl;
    delete m_messenger;
  }

  G4Run* RunAction::GenerateRun() {
    return new Run;
  }
  void RunAction::BeginOfRunAction(G4Run const*) {
    G4cout << "Starting a run!" << G4endl;
    return;
  }

  void RunAction::EndOfRunAction(G4Run const* run) {
    // Cast to our Run object, C++-style
    auto our_run = dynamic_cast<Run const*>(run);
    // Less safe, C-style
    //auto our_run = (Run const*)run;

    auto nevents = run->GetNumberOfEvent();
    if (nevents == 0) {
      return;
    }
    G4cout << "Finished processing " << nevents << " events" << G4endl;
    // We don't want to do this in every thread, just the master one!
    if (IsMaster()) {
      if (m_fSaveData) {
        G4cout << "Writing hits..." << G4endl;
        write_hits(our_run->get_hits());
      }
    }
    return;
  }

  bool RunAction::save_data() const {
    return m_fSaveData;
  }

  void RunAction::save_data(bool save) {
    m_fSaveData = save;
    return;
  }

  G4String const& RunAction::get_path() const {
    return m_path;
  }

  void RunAction::set_path(G4String const& path) {
    m_path = path;
    return;
  }

  void RunAction::write_hits(std::queue<Hit> hits) {
    std::ofstream out_file(m_path);
    out_file << "eventID,trackID,parentID,particle,creator_process,volume,";
    out_file << "x[cm],y[cm],z[cm],energy_dep[keV],time[ns]" << std::endl;
    while (!hits.empty()) {
      auto hit = hits.front();
      out_file << hit.getEventID() << ",";
      out_file << hit.getTrackID() << ",";
      out_file << hit.getParentID() << ",";
      out_file << hit.getParticle() << ",";
      out_file << hit.getProcess() << ",";
      out_file << hit.getVolume() << ",";
      // This is where we take our units back out - the number will be in
      // whatever units we divide by
      out_file << hit.getPosition().getX() / cm << ",";
      out_file << hit.getPosition().getY() / cm << ",";
      out_file << hit.getPosition().getZ() / cm << ",";
      out_file << hit.getEnergy() / keV << ",";
      out_file << hit.getTime() / ns << std::endl;
      hits.pop();
    }
    out_file.close();
    return;
  }
}
