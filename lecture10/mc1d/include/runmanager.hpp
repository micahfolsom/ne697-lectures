#ifndef RUNMANAGER_HPP
#define RUNMANAGER_HPP

namespace mc1d {
  class RunManager {
    public:
      RunManager(int track_length, float absorption);

      void run(int n_particles);
      void write_outputs();

    private:
      int m_trackLength;
      float m_absorption;
      // TODO
  };
}

#endif
