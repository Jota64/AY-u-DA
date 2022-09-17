/**
 * @file TestUtils.cpp
 * @author Alejandro Mujica (aledrums@gmail.com)
 * @copyright Copyright (c) 2022
 */
#include <TestUtils.hpp>

bool operator < (const std::tuple<std::shared_ptr<Plant>, std::shared_ptr<Plant>, std::shared_ptr<Good>, float, float>& t1,
                 const std::tuple<std::shared_ptr<Plant>, std::shared_ptr<Plant>, std::shared_ptr<Good>, float, float>& t2)
{
  if (std::get<0>(t1) < std::get<0>(t2))
    {
      return true;
    }
    if (std::get<0>(t1) > std::get<0>(t2))
    {
      return false;
    }
    if (std::get<1>(t1) < std::get<1>(t2))
    {
      return true;
    }
    if (std::get<1>(t1) > std::get<1>(t2))
    {
      return false;
    }
    if (std::get<2>(t1) < std::get<2>(t2))
    {
      return true;
    }
    if (std::get<2>(t1)->get_description() > std::get<2>(t2)->get_description())
    {
      return false;
    }	
    if (std::get<3>(t1) < std::get<3>(t2))
    {
      return true;
    }
    if (std::get<3>(t1) > std::get<3>(t2))
    {
      return false;
    }
    return std::get<4>(t1) < std::get<4>(t2);
}

bool operator == (const std::tuple<std::shared_ptr<Plant>, std::shared_ptr<Plant>, std::shared_ptr<Good>, float, float>& t1,
                  const std::tuple<std::shared_ptr<Plant>, std::shared_ptr<Plant>, std::shared_ptr<Good>, float, float>& t2)
{
  return std::get<0>(t1)->get_owner()->get_rif() == std::get<0>(t2)->get_owner()->get_rif() &&
            std::get<1>(t1)->get_owner()->get_rif() == std::get<1>(t2)->get_owner()->get_rif() &&
            std::get<2>(t1)->get_description() == std::get<2>(t2)->get_description() &&
            equal_value(std::get<3>(t1), std::get<3>(t2)) &&
            equal_value(std::get<4>(t1), std::get<4>(t2));
}

bool operator < (const std::tuple<std::shared_ptr<Company>, std::shared_ptr<Company>, std::shared_ptr<Good>, float, float, float>& t1,
                 const std::tuple<std::shared_ptr<Company>, std::shared_ptr<Company>, std::shared_ptr<Good>, float, float, float>& t2)
{
  if (std::get<0>(t1) < std::get<0>(t2))
  {
    return true;
  }
  if (std::get<0>(t1) > std::get<0>(t2))
  {
    return false;
  }
  if (std::get<1>(t1) < std::get<1>(t2))
  {
    return true;
  }
  if (std::get<1>(t1) > std::get<1>(t2))
  {
    return false;
  }
  if (std::get<2>(t1) < std::get<2>(t2))
  {
    return true;
  }
  if (std::get<2>(t1) > std::get<2>(t2))
  {
    return false;
  }
  if (std::get<3>(t1) < std::get<3>(t2))
  {
    return true;
  }
  if (std::get<3>(t1) > std::get<3>(t2))
  {
    return false;
  }
  if (std::get<4>(t1) < std::get<4>(t2))
  {
    return true;
  }
  if (std::get<4>(t1) > std::get<4>(t2))
  {
    return false;
  }
  return std::get<5>(t1) < std::get<5>(t2);
}

bool operator == (const std::tuple<std::shared_ptr<Company>, std::shared_ptr<Company>, std::shared_ptr<Good>, float, float, float>& t1,
                  const std::tuple<std::shared_ptr<Company>, std::shared_ptr<Company>, std::shared_ptr<Good>, float, float, float>& t2)
{
  return std::get<0>(t1)->get_rif() == std::get<0>(t2)->get_rif() &&
         std::get<1>(t1)->get_rif() == std::get<1>(t2)->get_rif() &&
         std::get<2>(t1)->get_description() == std::get<2>(t2)->get_description() &&
         equal_value(std::get<3>(t1), std::get<3>(t2)) &&
         equal_value(std::get<4>(t1), std::get<4>(t2)) &&
         equal_value(std::get<5>(t1), std::get<5>(t2));
}

bool equal_value(float a, float b)
{
  return std::abs(std::abs(a) - std::abs(b)) <= EPSILON;
}