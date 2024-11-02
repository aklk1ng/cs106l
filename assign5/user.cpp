#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

User::User(const User &user)
    : _name(user._name), _friends(new std::string[user._capacity]), _size(user._size),
      _capacity(user._capacity) {
  for (size_t i = 0; i < this->_size; ++i) {
    this->_friends[i] = user._friends[i];
  }
}

User &User::operator=(const User &user) {
    if (this != &user) {
        delete[] this->_friends;
        this->_size = user._size;
        this->_capacity = user._capacity;
        this->_friends = new std::string[this->_capacity];
        for (size_t i = 0; i < _size; ++i) {
            this->_friends[i] = user._friends[i];
        }
        this->_name = user._name;
    }
    return *this;
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

std::ostream& operator<<(std::ostream &out, const User &user) {
    out << "User(name=" << user._name << ", friends=[";
    for (size_t i = 0; i < user._size; ++i) {
        out << user._friends[i];
        if (i < user._size - 1) {
            std::cout << ", ";
        }
    }
    out << "])";
    return out;
}

User &User::operator+=(User &other) {
    this->add_friend(other._name);
    other.add_friend(this->_name);
    return *this;
}

bool User::operator<(const User &other) const {
    return this->_name < other._name;
}

User::~User() {
    delete[] this->_friends;
}
