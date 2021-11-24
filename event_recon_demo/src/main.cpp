#include "G4RunManagerFactory.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "QGSP_BERT_HP.hh"
#include "actioninitialization.hpp"
#include "detectorconstruction.hpp"
#include "G4RadioactiveDecayPhysics.hh"

int main(int argc, char* argv[]) {
  // Initialize simulation objects
  auto* run_manager =
      G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
  // Physics
  auto physics_list = new QGSP_BERT_HP;
  physics_list->SetVerboseLevel(0);
  run_manager->SetUserInitialization(physics_list);
  // Geometry
  run_manager->SetUserInitialization(new g4t::DetectorConstruction);
  // Actions (RunAction, EventAction, PrimaryGeneratorAction)
  run_manager->SetUserInitialization(new g4t::ActionInitialization);

  // Check number of command-line args, which controls whether we run
  // in visual mode or batch mode
  G4VisManager* vis_manager = nullptr;
  auto ui_manager = G4UImanager::GetUIpointer();
  if (argc == 1) {
    vis_manager = new G4VisExecutive;
    vis_manager->Initialize();
    auto ui = new G4UIExecutive(argc, argv);
    ui_manager->ApplyCommand("/control/macroPath scripts/");
    ui_manager->ApplyCommand("/control/execute scripts/init_vis.mac");
    ui->SessionStart();
    delete ui;
  } else if (argc == 2) {
    G4String cmd = "/control/execute " + (G4String)argv[1];
    ui_manager->ApplyCommand(cmd);
  }

  delete vis_manager;
  delete run_manager;
  return 0;
}
