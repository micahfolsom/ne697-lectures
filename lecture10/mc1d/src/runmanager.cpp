#include "runmanager.hpp"
#include <iostream>
using namespace std;

namespace mc1d {
  RunManager::RunManager(int track_length, float absorption):
    m_trackLength(track_length),
    m_absorption(absorption)
  {
    cout << "Creating RunManager with track_len=" << m_trackLength << " and"
      << " absorption=" << m_absorption << endl;
  }
  
  void RunManager::run(int n_particles) {
    cout << "Running simulation with " << n_particles << " particles" << endl;
    // TODO
    write_outputs();
    return;
  }

  void RunManager::write_outputs() {
    // TODO
    return;
  }
}
