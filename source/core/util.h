#include <memory>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

namespace GameAi
{

namespace Core
{

using String = std::string;

template<class K, class V>
using Map = std::unordered_map<K, V>;

using Texture = sf::Texture;

template <class T>
using SharedPtr = std::shared_ptr<T>;

}

}
