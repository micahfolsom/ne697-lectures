#ifndef RUN_MANAGER_HPP
#define RUN_MANAGER_HPP
#include <queue>
#include <vector>
#include "hit.hpp"

namespace mc1d {
  class RunManager {
    public:
      RunManager(int track_len, float atten);
      
      void run(int n);
      void write_results();

    private:
      int m_trackLength;
      float m_absorption;
      //std::queue<Hit> m_hits;
      std::vector<Hit> m_hits;
  };
}

#endif
