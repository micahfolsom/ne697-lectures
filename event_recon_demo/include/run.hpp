#ifndef RUN_HPP
#define RUN_HPP
#include <queue>

#include "G4Run.hh"
#include "hit.hpp"

namespace g4t {
class Run : public G4Run {
 public:
  Run();
  ~Run();

  void RecordEvent(G4Event const* event);
  void Merge(G4Run const* from_run);
  std::queue<Hit> get_hits() const;
  void writeHits(std::string const& file_path) const;

 private:
  std::queue<Hit> m_hits;
};
}  // namespace g4t

#endif
