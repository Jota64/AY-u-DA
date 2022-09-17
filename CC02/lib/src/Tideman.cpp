#include <NoImplementedException.hpp>
#include <NoWinnerException.hpp>
#include <Tideman.hpp>

Tideman::Tideman(const std::vector<std::string>& _candidates) noexcept
  : candidates{_candidates}, preferences{candidates.size(), std::vector<int>(candidates.size(), 0)}
{
  // empty
}

const std::vector<std::string>& Tideman::get_candidates() const noexcept
{
  return candidates;
}

const std::vector<std::vector<int>>& Tideman::get_preferences() const noexcept
{
  return preferences;
}

bool Tideman::vote(int rank, const std::string& name, OUT_PARAM std::vector<int>& ranks) const noexcept
{
  // TODO
  throw NoImplementedException{};
}

void Tideman::record_preferences(const std::vector<int>& ranks) noexcept
{
  // TODO
  throw NoImplementedException{};
}

std::vector<std::pair<int, int>> Tideman::create_pairs() const noexcept
{
  // TODO
  throw NoImplementedException{};
}

std::vector<std::vector<bool>> Tideman::lock_pairs(const std::vector<std::pair<int, int>>& pairs, size_t num_candidates) noexcept
{
  // TODO
  throw NoImplementedException{};
}

std::string Tideman::get_winner(const std::vector<std::vector<bool>>& locked) const
{
  // TODO
  throw NoImplementedException{};
}
