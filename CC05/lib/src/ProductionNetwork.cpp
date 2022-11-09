/**
 * @file ProductionNetwork.cpp
 * @authors
 */
#include <ProductionNetwork.hpp>

ProductionNetwork::ProductionNetwork(const ProductionData& data) noexcept
{
  // TODO
}

ProductionNetwork::~ProductionNetwork()
{

}

std::vector<ProductionNetwork::NodeData> ProductionNetwork::get_node_info_list() const noexcept
{
  // TODO
  return std::vector<NodeData>{};
}

std::vector<ProductionNetwork::ArcData> ProductionNetwork::get_arc_info_list() const noexcept
{
  // TODO
  return std::vector<ArcData>{};
}

std::vector<ProductionNetwork::ChangedPriceData> ProductionNetwork::change_price(std::shared_ptr<Good> good, float change)
{
  // TODO
  return std::vector<ChangedPriceData>{};
}

std::ostream& ProductionNetwork::to_dot(std::ostream& output) const noexcept
{
  // TODO  
  return output;
}