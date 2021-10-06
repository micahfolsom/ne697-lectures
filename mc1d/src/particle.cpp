#include "particle.hpp"

namespace mc1d {
  Particle::Particle(int id):
    m_id(id),
    m_position(0),
    m_fAlive(true)
  {
  }

  int Particle::get_id() const {
    return m_id;
  }

  int Particle::get_position() const {
    return m_position;
  }

  void Particle::set_position(int pos) {
    m_position = pos;
    return;
  }

  bool Particle::alive() const {
    return m_fAlive;
  }

  void Particle::kill() {
    m_fAlive = false;
    return;
  }
}
