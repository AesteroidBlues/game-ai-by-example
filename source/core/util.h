#include <string>
#include <unordered_map>

namespace GameAi
{

namespace Core
{

using String = std::string;

template<class K, class V>
using Map = std::unordered_map<K, V>;

using Texture = sf::Texture;

}

}
