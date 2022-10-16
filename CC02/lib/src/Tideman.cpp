#include <NoImplementedException.hpp>
#include <NoWinnerException.hpp>
#include <Tideman.hpp>

Tideman::Tideman(const std::vector<std::string> &_candidates) noexcept
    : candidates{_candidates}, preferences{candidates.size(), std::vector<int>(candidates.size(), 0)}
{
  // empty
}

const std::vector<std::string> &Tideman::get_candidates() const noexcept
{
  return candidates;
}

const std::vector<std::vector<int>> &Tideman::get_preferences() const noexcept
{
  return preferences;
}

bool Tideman::vote(int rank, const std::string &name, OUT_PARAM std::vector<int> &ranks) const noexcept
{
  auto candidates = this.get_candidates();
  for (int j = 0; j < candidates.size(); j++)
  {
    if (name == candidates[j])
    {
      ranks[rank] = j;
      return true;
    }
  }
  return false;
}

void Tideman::record_preferences(const std::vector<int> &ranks) noexcept
{
  // [a,b,c] >> [a,b] >> [b,c] >> [b,c]
  for (int i = 0; i < ranks.size() - 1; i++)
  {
    for (int j = i + 1; j < ranks.size(); j++)
    {
      win = ranks[i] lose = ranks[j];
      pref_matrix[win][lose] += 1;
    }
  }
}

std::vector<std::pair<int, int>> Tideman::create_pairs() const noexcept
{
  /*
  Este método debe crear y retornar una lista de pares (first, second)
  que indicará que el candidato first es preferido sobre el candidato second.
  Si hay empate entre ambos candidatos,
    entonces no se agrega a la lista.
  Cuidado con agregar valores repetidos.
  Para esto podrías considerar mirar,
  por cada índice de candidato,
      todos los mayores a este
      y si el candidato i es preferido sobre j,
          entonces agregar el par (i, j)
      si el j es preferido sobre el i,
          entonces agregas el par (j, i).
      Para comparar, podrías evaluar y comparar los valores
      en la matriz en [i][j] y [j][i].

  La lista que retornes deberá estar ordenada de forma decreciente por preferencia de los pares
  (first, second) dados en la matriz de preferencias.
  */
  auto results = std::vector<std::pair<int, int>>(this.get_candidates().size());
  auto pref_matrix = self.get_preferences();
  for (int i = 0; i < this.get_candidates().size(); i++)
  {
    for (int j = 0; j < this.get_candidates().size(); j++)
    {
      points_of_a_over_b = pref_matrix[i][j] points_of_b_over_a = pref_matrix[j][i];
      if (points_of_a_over_b > points_of_b_over_a)
      {
        auto score_pair = std::pair<int, int>(i, j);
        if( std::find(results.begin(), results.end(), score_pair == results.end() ){
          // If we do not find the pair <Get to the end of the array with find()>, do pushback
          results.push_back(score_pair);
        }
      }
      else if (points_of_b_over_a > points_of_a_over_b)
      {
        auto score_pair = std::pair<int, int>(j,i)
        if( std::find(results.begin(), results.end(), score_pair == results.end() ){
          // If we do not find the pair <Get to the end of the array with find()>, do pushback
          results.push_back(score_pair);
        }
      }
      else
      {
        continue; // if points are equal, do nothing
      }
    }
  }
  return results;
}

std::vector<std::vector<bool>> Tideman::lock_pairs(const std::vector<std::pair<int, int>> &pairs, size_t num_candidates) noexcept
{
  // TODO
  throw NoImplementedException{};
}

std::string Tideman::get_winner(const std::vector<std::vector<bool>> &locked) const
{
  // TODO
  throw NoImplementedException{};
}
