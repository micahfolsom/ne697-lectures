#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "runmanager.hpp"
#include "particle.hpp"
using namespace std;

namespace mc1d {
  RunManager::RunManager(int track_len, float atten):
    m_trackLength(track_len),
    m_absorption(atten)
  {
    cout << "Creating RunManager with track_len=" << m_trackLength << " and "
      << "absorption=" << m_absorption << endl;
  }

  void RunManager::run(int n) {
    // Set up RNG (from std::)
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> rng(0, 1.0);

    // Allocate particles
    //std::queue<Particle> particles;
    std::vector<Particle> particles;
    for (int i=0;i < n;++i) {
      //particles.push(Particle(i));
      particles.push_back(Particle(i));
    }
    // This is a trick to clear out the queue quickly: we construct a new,
    // empty queue, and swap with ours (instead of removing every element
    // individually)
    //std::queue<Hit>().swap(m_hits);
    std::vector<Hit>().swap(m_hits);

    // Run transport
    cout << "Running simulation with " << n << " particles" << endl;
    // std::queue implementation
    /*while (!particles.empty()) {
      auto particle = particles.front();
      while (particle.alive()) {
        auto roll = rng(gen);
        if (roll < m_absorption) {
          particle.kill();
          m_hits.push(Hit{particle.get_position()});
        } else {
          // Check if we're at the last position (track length - 1) due to
          // 0-index
          if (particle.get_position() == m_trackLength) {
            particle.kill();
            m_hits.push(Hit{particle.get_position()});
          } else {
            particle.set_position(particle.get_position() + 1);
          }
        }
      }
      particles.pop();
    }*/
    // std::vector implementation
    for (auto& p : particles) {
    //for (Particle& p : particles) {
    //for (int iparticle=0;iparticle < n;++iparticle) {
      for (int i=0;i < m_trackLength;++i) {
        auto roll = rng(gen);
        if (roll < m_absorption) {
          p.kill();
          m_hits.push_back(Hit{p.get_position()});
          break;
        } else {
          if (p.get_position() == (m_trackLength - 1)) {
            p.kill();
            m_hits.push_back(Hit{p.get_position()});
            break;
          } else {
            p.set_position(p.get_position() + 1);
          }
        }
      }
    }
    write_results();
    cout << "...finished!" << endl;
    return;
  }

  void RunManager::write_results() {
    std::vector<int> hist(m_trackLength, 0);
    // Write to file and populate histogram
    ofstream out_file("hits.csv", ofstream::out);
    int nhits = 0;
    /*while (!m_hits.empty()) {
      auto hit = m_hits.front();
      // Particles that didn't interact will be at index=m_trackLength
      // They don't get histogrammed or counted
      if (hit.position < m_trackLength) {
        hist[hit.position]++;
        nhits++;
      }
      out_file << hit.position << endl;
      m_hits.pop();
    }*/
    for (size_t ihit = 0;ihit < m_hits.size();++ihit) {
      auto hit = m_hits[ihit];
      if (hit.position < m_trackLength) {
        hist[hit.position]++;
        nhits++;
      }
      out_file << hit.position << endl;
    }
    cout << "Got " << nhits << " hits. Recording..." << endl;
    out_file.close();

    cout << "Hit Distribution:\n" << endl;
    // Make pretty histogram
    int const MAX_ROWS = 10;
    // Normalize. std::max_element returns an iterator (pointer) to the max
    // value element, so we have to dereference to get the value
    int MAX_VAL = *std::max_element(hist.begin(), hist.end());
    // Make a copy to scale
    std::vector<float> hist_scaled(m_trackLength, 0.);
    for (int i=0;i < m_trackLength;++i) {
      hist_scaled[i] = hist[i] * (float(MAX_ROWS) / float(MAX_VAL));
    }

    // Print an ASCII histogram to terminal
    for (int ir=0;ir < MAX_ROWS;++ir) {
      for (int ic=0;ic < m_trackLength;++ic) {
        // We're printing from top to bottom, starting with row index 9; we use
        // these values as thresholds on the scaled values to decide whether
        // or not to draw the *
        if (hist_scaled[ic] > (9 - ir)) {
          cout << "*";
        } else {
          cout << " ";
        }
      }
      // Finished a row that is m_trackLength long
      cout << endl;
    }
    cout << endl;
    // Also print the counts in each bin
    for (int ic=0;ic < m_trackLength;++ic) {
      cout << hist[ic] << " ";
    }
    cout << endl;

    return;
  }
}
