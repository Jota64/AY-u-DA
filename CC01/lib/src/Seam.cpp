#include <Color.hpp>
#include <Seam.hpp>

Seam::Seam(const std::vector<std::vector<unsigned>>& _energy) noexcept
  : energy(_energy)
{
  
}

std::pair<size_t, unsigned> Seam::compute_vertical_seam() const noexcept
{
  // TODO

  return std::make_pair(0, 0);
}

std::pair<std::vector<size_t>, unsigned> Seam::compute_vertical_seams() const noexcept
{
  // TODO
  
  return std::make_pair(std::vector<size_t>{}, 0);
}

std::vector<std::vector<Color>> Seam::min_seam_to_colors(const std::vector<std::vector<Color>>& pixels, size_t end_j) noexcept
{
  long h = pixels.size();
  long w = pixels[0].size();
  
  std::vector<std::vector<Color>> new_pixels{pixels};

  size_t min_j = std::max(long(end_j) - 5, 0L);
  size_t max_j = std::min(long(end_j) + 5, w - 1);

  size_t min_i = std::max(h - 11, 0L);
  
  for (size_t i = min_i; i < h; ++i)
  {
    for (size_t j = min_j; j <= max_j; ++j)
    {
      new_pixels[i][j] = Color(255, 0, 0);
    }
  }

  return new_pixels;
}

std::vector<std::vector<Color>> Seam::min_seams_to_colors(const std::vector<std::vector<Color>>& pixels, const std::vector<size_t>& seam_cols) noexcept
{
  long h = pixels.size();
  long w = pixels[0].size();
  
  std::vector<std::vector<Color>> new_pixels{pixels};

  for (size_t i = 0; i < seam_cols.size(); ++i)
  {

    size_t min_j = std::max(long(seam_cols[i]) - 2, 0L);
    size_t max_j = std::min(long(seam_cols[i]) + 2, w - 1);

    for (size_t j = min_j; j <= max_j; ++j)
    {
      new_pixels[i][j] = Color(255, 0, 0);
    }
  }

  return new_pixels;
}
