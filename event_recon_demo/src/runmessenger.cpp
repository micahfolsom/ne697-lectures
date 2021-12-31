#include "runmessenger.hpp"
#include "runaction.hpp"

namespace g4t {
  RunMessenger::RunMessenger(RunAction* runaction):
    m_runAction(runaction)
    {
      // Directory: /ne697/run
      m_directory = new G4UIdirectory("/ne697/run/");
      m_directory->SetGuidance("Change parameters of the run.");

      // Toggle data saving: /ne697/run/save_data
      m_saveDataCmd = new G4UIcmdWithABool("/ne697/run/save_data", this);
      m_saveDataCmd->SetGuidance("Toggle saving data to file.");
      m_saveDataCmd->SetParameterName("save_data", true);
      m_saveDataCmd->SetDefaultValue(m_runAction->save_data());
      m_saveDataCmd->AvailableForStates(G4State_Idle);

      // Save file path: /ne697/run/save_path
      m_savePathCmd = new G4UIcmdWithAString("/ne697/run/save_path", this);
      m_savePathCmd->SetGuidance("Save file path.");
      m_savePathCmd->SetParameterName("save_path", true);
      m_savePathCmd->SetDefaultValue(m_runAction->get_path());
      m_savePathCmd->AvailableForStates(G4State_Idle);
    }

  RunMessenger::~RunMessenger() {
    delete m_directory;
    delete m_saveDataCmd;
    delete m_savePathCmd;
  }

  void RunMessenger::SetNewValue(G4UIcommand* cmd, G4String val) {
    if (cmd == m_saveDataCmd) {
      bool parsed_val = m_saveDataCmd->GetNewBoolValue(val);
      m_runAction->save_data(parsed_val);
      G4cout << "Save data set to " << (parsed_val ? "true" : "false")
        << G4endl;
    } else if (cmd == m_savePathCmd) {
      m_runAction->set_path(val);
      G4cout << "Save file path set to " << val << G4endl;
    }
    // Command didn't match
    return;
  }
}
